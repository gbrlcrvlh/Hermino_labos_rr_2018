//### Algoritmo do Barbeiro

//Este algoritmo foi encontrado no seguinte link:
//https://www.codeproject.com/Questions/49028/Sleeping-barber-problem., que é um
//fórum de dúvidas, com o seguinte tópico: Sleeping barber problem.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<sys/ipc.h>
#include<semaphore.h>

#define N 5

time_t end_time;/*Fim do tempo*/
sem_t mutex,customers,barbers;/*Três semáforos*/
int count=0;/*O número de clientes à espera de cortes de cabelo*/

void barber(void *arg);
void customer(void *arg);

int main(int argc,char *argv[])
{
	pthread_t id1,id2;
	int status=0;
	end_time=time(NULL)+20;/*Horas de barbearia é 20s*/

	/*Inicialização do semáforo*/
	sem_init(&mutex,0,1);
	sem_init(&customers,0,0);
	sem_init(&barbers,0,1);

	/*Inicialização Barber_thread*/
	status=pthread_create(&id1,NULL,(void *)barber,NULL);
	if(status!=0)
		perror("create barbers is failure!\n");
	/*Inicialização do cliente_thread*/
	status=pthread_create(&id2,NULL,(void *)customer,NULL);
	if(status!=0)
		perror("create customers is failure!\n");

	/*Cliente_thread primeiro bloqueado*/
	pthread_join(id2,NULL);
	pthread_join(id1,NULL);

	exit(0);
}

void barber(void *arg)/*Processo Barbeiro*/
{
	while(time(NULL)<end_time || count>0)
	{
		sem_wait(&customers);/*P(clientes)*/            
		sem_wait(&mutex);/*P(mutex)*/
		count--;
		printf("Barber:cut hair,count is:%d.\n",count);
		sem_post(&mutex);/*V(mutex)*/
		sem_post(&barbers);/*V(barbeiros)*/
		sleep(3);       
	}
}

void customer(void *arg)/*Processo de clientes*/
{
	while(time(NULL)<end_time)
	{
		sem_wait(&mutex);/*P(mutex)*/
		if(count<N)
		{
			count++;
			printf("Customer:add count,count is:%d\n",count);
			sem_post(&mutex);/*V(mutex)*/
			sem_post(&customer);/*V(clientes)*/
			sem_wait(&barbers);/*P(barbeiros)*/
		}
		else
			/*V(mutex)*/
			/*Se o número estiver cheio de clientes, basta colocar o bloqueio no mutex*/
			sem_post(&mutex);
		sleep(1);
	}
}
