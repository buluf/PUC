# OpenMP
Multiplicação de matriz utiliza-se de duplo for, para paralizar isto teremos que entender da diretiva que eu escreverei logo abaixo:

## Collapse
One directive i required for each nested loop. This tends to be cumbersome especially if multiple nested loops are to be treated in the same way. The **collapse clause** comes in handy in such a case. The argument to the collapse clause is a constant positive integer, which specifies how many tightly nested loops are associated with the loop construct. Consequently, you can describe the scheduling of the iterations of these loops using a single loop construct according to the rest of its clases(ohter than the collapse).
