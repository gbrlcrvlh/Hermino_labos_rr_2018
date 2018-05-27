### Algoritmo do Banqueiro:

O algoritmo do banqueiro é executado pelo SO e impede o deadlock 
negando ou adiando um pedido. Se o algoritmo aceitar o pedido, ele coloca
o SO em estado inseguro, que quer dizer que pode acontecer um deadlock.
Quando um novo processo entra em um sistema, ele deve declarar o número
máximo de instâncias de cada tipo de recurso que não pode exceder o número
total de recursos no sistema.

Exemplo:

Supondo que o sistema distingue quatro tipos de recursos, (A, B, C e D):

Recursos do sistema disponíveis são:

A B C D

3 1 1 2

Processos (recursos atualmente alocados):
   A B C D
   
P1 1 2 2 1

P2 1 0 3 3

P3 1 1 1 0

Processos (máximo de recursos):
   A B C D
   
P1 3 3 2 2

P2 1 2 3 4

P3 1 1 5 0

Podemos ver o codigo no seguinte link: 
https://github.com/hermino/Hermino_labos_rr_2018/tree/master/AlgoritmoDoBanqueiro

Onde as entrada: e um vetor {0, 1, 2, 3, 4}

Com as seguintes saidas:

O sistema nao esta em estado seguro

ou

O sistema esta em estado seguro.
Seguro: 1 3 4 0 2

### Referencias:

Site: https://pt.wikipedia.org/wiki/Algoritmo_do_banqueiro. Acesso em 27/05/2018

Site: https://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/. Acesso em 27/05/2018


