# Arquiteturas Paralelas

* Leia a seção "2.4 Machine Models" do livro texto, para entender um pouco mais sobre os modelos de máquinas paralelas, hierarquia de memória e desempenho.

## *2.4* MACHINE MODELS
 To write efficiente programs, it is important to have a clear mental model of the organization of the hardware resources being used.

 ![multicore](images/multicore_processor.png)
This is a sketch of a typical **multicore processor**. Inside every **core** there are multiple functional units, each such funcional unit being able to do a single arithmetic operation.
### Instruction parallelism
Since cores usually have multiple functional units, multiple arithmetic operationms can often be performed in parallel, even in a single core. Parallel use of multiple functional units in a single core can be done either implicitly, by a **superscalar execution of serial instructions, hardware multithreading, or bu explicit vector instructions. A **superscalar processor** analyzes an instruction stream and executes multiple instructions in parallel as long as they do not depend on each other. Vector instructions enable explicit use of multiple functional units at once by specifying an operation on a small collection of data elements.
