# Padrões de Programação Paralela
* Leia as seções 1.4, 3.3.1 e 3.3.2 do livro texto para entender um pouco mais sobre padrões de programação paralela (esqueletos paralelos), e especificamente os padrões FORK-JOIN e MAP.

# Introdução ao OpenMP

* Tutorial no Eitas!: [Introdução a Programação Paralela com OpenMP](http://www.eitas.com.br/tutorial/12/26)

* **

## 2.1 STRUCTURED PATTERN-BASED PROGRAMMING
Algorithm strategy patterns have two parts: semantics and implementation.

Three patterns deserve special mention: **nesting, map,** and **for-join.**

**Nesting** means that patterns can be hierarchically composed. This is important for modular programming.

The **map** pattern divides a problem into a number of uniform parts and represents a regular parallelization. This is also known as **embarrassing parallelism.** The map pattern is worth using whenever possible since it allows for both efficient parallelization and efficient vectorization.

The **fork-join** pattern recursively subdivides a problem into subparts and can be used for both regular and irregular parallelization. It is useful for implementating a **divide-and-conquer** strategy.

In summary, patterns provide a common vocabulary for discussing approaches to problem solving and allow reuse of best practices. Patterns transcend languages, programming models, and even computer architectures, and you can use patterns whether or not the programming system you are using explicitly supports a given pattern with a specific feature.

![patterns](images/parallel_patterns.png)

## 3.3.1 Fork-Join
Fork-join should not be confused with **barriers**. A barrier is a synchronization construct across multiple threads. In a barrier, each thread must wait for all other threads to reach the barrier before any of them leave. The difference is that after a barrier all threads continue, but after a join only one does. Sometimes barriers are used to imitate joins, by making all threads execute identical code after the barrier, until the next conceptual fork.

## 3.3.2 Map
The **map** pattern replicates a function over every element of an index set. The index set may be abstract or associated with the elements of a collection. The function being replicated is called an **elemental function** since it applies to the elements of an actual collection of input data.
The map pattern replaces one specific usage of iteration in serial programs: a loop in which every iteration is independent, in which the number of iterations is known is advance, and in which every computation depends only on the iteration count and data read using the iteration count as an index into a collection. This form of loop is often used, like map, for processing every element of a collection with an independent operation. The elemental function must be pure(that is, whithout side-effects) in order for the map to be implementable in parallel while achieving deterministic results. In particular, elemental funcions must not modify global data that other instances of that function depend on.
