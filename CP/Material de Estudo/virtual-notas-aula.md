# Computação Paralela

## Padrões de Programação Paralela

### Programação Estruturada
* A "programação estruturada" (sequencial) é composta pelos seguintes Padrões
  * Estruturas de Seleção e Repetição
  * Funções, Recursão etc.

* Estas boas práticas de programação eliminam problemas como o GOTO
  * Melhora a manutenabilidade do software.
  * Aumenta o reuso de software.
  * Problema: Serialização

### Serialização
* **Abstração de uma máquina sequencial.**
  * Possui ordem temporal.
  * É determinística.
    * Fácil de codificar, depurar e testar.

* **Limita o paralelismo sem necessidade.**
  * Paralelismo não é determinístico.

### Quebrando a Serialização
Por padrão o for por exemplo, ele força uma serialização no nosso código, ou seja, uma ordem a ser executada. Mas em muitos casos não necessariamente essas ações de um mesmo laço necessita de vir em uma ordem não há dependência de dados entre as camadas de um mesmo for.

* #### Que tal um for sem serialização?

  ![](images/parallel_for.png)

* **Agora lê-se:** A "palavra" pode ser buscada em todas as páginas "i" ao mesmo tempo, ou seja, em paralelo.  


### Programação Paralela Estruturada
* **A "programação paralela estruturada" é composta por padrões paralelos ou esqueletos algoritmicos ou paralelos.**
  * Fork-Join, Map, Reduce, Scan, Stencil etc.
* **Estes padrões paralelos capturam estruturas comuns a programas paralelos.**
    * Elimina o uso explícito de threads.
    * Remove(relaxa) as restrições de serialização dos padrões sequenciais.

#### Fork-Join
* **É o padrão paralelo mais simples.**

* **Permite que uma mesma seção de código seja executada em paralelo por várias threads trabalhadoras.**

* **Uma thread mestre dispara(fork) várias threads trabalhadoras e ao final da execução de cada thread, elas sincronizam-se, restando apenas a thread mestre(join).**

#### Map
*  **O padrão Map replica uma função sobre cada elemento de um conjunto de índices(ou dados diferentes).**

* **Ele é mais comumente encontrado na forma de uma estrutura de repetição sem a restrição de ordem de execução das iterações.**
  * É necessário que as funções(iterações) sejam independentes.

#### Reduce
* **O padrão Reduce combina cada elemento de uma coleção, geralmente em pares, utilizando um operador, até reduzi-los a um único elemento.**

* **Exemplos**
  * Realizar somatório de inteiros.

#### Stencil
* **O padrão Stencil é uma generalização do MAP, onde cada função acessa não somente um único elemento, mas também seus vizinhos.**
  * Condições de borda precisam ser checadas.

* **Exemplos**
  * Convolução de imagens
  * Detecção de quinas
  * Simulação de nuvens

#### Scan
  * **O padrão Scan computa todas as reduções parciais de uma coleção de elementos, ou seja, para cada saída, uma redução parcial é computada até o elemento atual.**

* **Exemplo**
  * Somatório parciais
  ![somatorio_parcial](images/somatorio_parcial.png)

* **
## Semântica e implementação

* **Semântica**
  * O que o padrão faz?
  * É apenas a funcionalidade do padrão (visão de fora).


* **Implementação**
  * Como o padrão executa na prática?
  * Várias implementações são possíveis.
  * Visão de dentro do padrão.

## Suporte aos Padrões pelos Modelos de Programação

* **Open Multi-processing (OpenMP)**
  * Fork-Join, Map e Reduce


* **Compute Unified Device Architecture(CUDA)
Open Computing Language(OpenCL)**
  * Map


* **Intel Thread Building Blocks (TBB)**
  * Fork-Join, Map, Reduction, Pipeline, Scan e outros


* **Message Passing Interface (MPI)**
  * Map, Gather, Scatter, Reduce e outros

## Padrão REDUCE em OpenMP
* **Shared** - a variavel declarada como shared, ela terá apenas uma única cópia dessa mesma variavel para todas as threads que tivermos.
E variaveis declaradas fora do laço serão declaradas por default como shared.

* **Critical** - Diretiva que garante atomicidade em um área de código de sua paralelização.
