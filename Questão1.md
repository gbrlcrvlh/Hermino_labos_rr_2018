### Prática A:

Quantos dois ou mais processos estão **prontos** para executarem eles permanencem
em uma fila esperando sua vez de executar, porem pode ocorrer de que um processo depende
da resposta de outro processo, neste caso, o processo que espera a resposta fica no estado
**bloqueado**.

![Prática 1.0](https://github.com/hermino/Hermino_labos_rr_2018/blob/master/Pr%C3%A1tica1.0.PNG)

![Prática 1.1](https://github.com/hermino/Hermino_labos_rr_2018/blob/master/Pr%C3%A1tica1.1.PNG)

![Prática 1.2](https://github.com/hermino/Hermino_labos_rr_2018/blob/master/Pr%C3%A1tica1.2.PNG)


### Prática B:

a) O starvation acontece porque o escalonador da sempre preferência para o processo com maior
prioridade, isso faz com o processo com a cor **Ciano** saia do estado **pronto** para **em execução** e de **em execução**
para **pronto**, consequentemente o precesso de cor Preta fica sempre em estado pronto.


![Prática 2.0](https://github.com/hermino/Hermino_labos_rr_2018/blob/master/Pr%C3%A1tica2.0.PNG)

![Prática 2.1](https://github.com/hermino/Hermino_labos_rr_2018/blob/master/Pr%C3%A1tica2.1.PNG)

b) Para solucionar esse problema a prioridade do processo pode ir se alterando de acordo com o "tempo de vida"
do mesmo, isso faz com que prioridade de um processo que não é executado mude momentaneamente, para que possa ser
executado, depois disso volta a sua prioridade normal.

### Prática C:

a) O espaço real de um processos varia de acordo com hadware e da mémoria virtual,
mas espaço é a soma do espaço da mémoria principal e da mémoria virtual.

b) É o tamanho minimo da tabela de mapeamento carregada.

c) O próprio usário pode definir o tamanho que quiser para mémoria virtual, se caso não seja feito
isso o tamanho da mémoria virtual será definido de acordo com o hardware. Esse tamanho muda de acordo
com o hardware.

### Prática D:

a) Seleciona o processo com menor chance de ser executado pelo processador.

b) Quando entra em execução.

