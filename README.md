# Analise de desempenho de diferentes metodos de busca

1º Exercício Prático - Estrutura de Dados 2 - 2019.1 - UnB - Gama
=========================
André Lucas de Sousa Pinto - 17/0068251
Leonardo de Araujo Medeiros - 17/0038891

## Instalação

1. Faça o clone deste projeto com ```$ git clone https://github.com/EDAII/Lista1-AndreLucas-LeonardoMedeiros.git ```
2. Acesse a pasta do projeto via terminal
3. Execute os seguintes comandos ``` $ g++ main.cpp -o prog -std=c++11 ```
4. Rode a aplicação com ``` $ ./prog``` 

## Ideia proposta

O programa executa diferentes métodos de busca (busca binária, busca sequencial, busca sequencial indexada, busca sequencial com sentinela), implementadas a partir do conhecimento dos contribuidores, em diferentes situações. Primeiro é gerado um vetor aleatório e em seguida ordenado e depois são feitas 1000 iterações de busca por um número aleatório que pode ou não estar no vetor, exibindo a média aritimética dos tempos obtidos.

O programa retorna 4 saidas, sendo elas os respectivos tempos médios de cada um dos diferentes algoritmos nos diferentes cenários propostos(vetor completamente aleatório, vetor com elementos concentrados no meio, com elementos concentrados no começo e com elementos concentrados no final).

## Resultados

Analisando os dados obtidos:
```
Searching for a random number in a random generated vector.

Binary search average time: 0.000001 seconds;
Sequential search average time: 0.001063 seconds;
Sequential search with sentinel average time: 0.000857 seconds;
Indexed sequential search average time: 0.000178 seconds;
```
```
Searching for a random number in a random generated vector, with 80% concentraded in the middle.

Binary search average time: 0.000001 seconds;
Sequential search average time: 0.001324 seconds;
Sequential search with sentinel average time: 0.001072 seconds;
Indexed sequential search average time: 0.000221 seconds;
```
```
Searching for a random number in a random generated vector, with 80% concentraded in the beginning.

Binary search average time: 0.000001 seconds;
Sequential search average time: 0.001469 seconds;
Sequential search with sentinel average time: 0.001191 seconds;
Indexed sequential search average time: 0.000229 seconds;
```
```
Searching for a random number in a random generated vector, with 80% concentraded in the ending.

Binary search average time: 0.000001 seconds;
Sequential search average time: 0.001249 seconds;
Sequential search with sentinel average time: 0.001013 seconds;
Indexed sequential search average time: 0.000224 seconds;
```
Em geral, podemos ver que a busca binária é mais rápida em todos os casos, sendo seguida da busca sequencial indexada, busca sequencial com sentinela e a busca sequencial. Esses resultados estão dentro do esperado devido principalmente a complexidade assintótica dos algoritmos ser 'log(n)' no caso da busca binária, e 'n' nas demais. No caso das buscas lineares a diferença se da devido a constantes na complexidade, sendo que a busca sequencial passa por todos os elementos sem otimização, a busca sequencial com sentinela passa por todos elementos evitando <i>branchs</i> desnecessárias, e a busca sequencial indexada otimiza a busca evitando passar por todos os elementos.

Nas diferentes situações é visivel que a busca binária não se alterou significantemente, nos demais casos podemos notar uma mudança significante que se da devido a forma como números foram distruidos, em todos os casos, exceto o completamente aletório, a chance do elemento não estar presente no intervalo superconcentrado do vetor é maior que a chance do elemento estar, consequentemente, quando uma busca por elemento aleatório é realizada, e o elemento se encontra depois do intervalo superconcentrado, as buscas sequenciais precisam passar por todos os elementos concentrados, para entao encontrar o elemento buscado.