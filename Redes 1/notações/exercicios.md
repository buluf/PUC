# Exercícios
#### 2. Explique a necessidade de um mecanismo de controle de acesso ao meio nas redes difusão.
Porque se não tivesse um dispositivo de controle de acesso numa rede broadcast(difusão) sendo que o canal de comunicação dela é compartilhado qualquer um poderia acessar mensagens que não lhe é destinado. Por isso também foi adicionado um campo de endereço em toda mensagem.
#### 3. Dê um exemplo de um serviço orientado a conexão confiável. Justifique sua resposta.
Transferência de arquivos(transporte). TCP(Transmission Control Protocol) é um exemplo disso,
pois ele permite a entrega sem erros(confiável) de dados de uma determinada máquina a outra máquina da rede. O proprietário do arquivo deseja se certificar que todos os bits chegaram corretamente e na mesma ordem em que foram enviados.
#### 4. Em alguns casos, quando uma conexão é estabelecida, o transmissor e o receptor conduzem uma “negociação” sobre os parâmetros a serem usados. Dê um exemplo do uso de negociação pelos protocolos de rede.
Como por exemplo definir o tamanho máximo das mensagens, a qualidade do serviço exigida e entre outra possibilidades. Em geral, um lado faz uma proposta e a outra parte pode aceitá-la, rejeitá-la ou fazer um contraproposta.
#### 5 Como seria o tipo de serviço que um usuário de uma aplicação de tempo real precisaria? Justifique.
Seria algo no estilo do protocolo UDP(User Datagram Protocol) algo que não será orientado a conexão, pois não há garantia de envio/recebimento de pacotes e isso é caro, para um aplicação de tempo real não serviria.
#### 6. Quando um arquivo é transferido entre dois computadores, são possíveis duas estratégias de confirmação. Na primeira, o arquivo é dividido em pacotes, que são confirmados individualmente pelo receptor, mas a transferência do arquivo como um todo não é confirmada. Na segunda, os pacotes não são confirmados individualmente mas, ao chegar a seu destino, o arquivo inteiro é confirmado. Analise essas duas abordagens.
Começando pela segunda abordagem tem um problema bem nítido, e provável que aconteça, que é o problema de houver um falha logo de começo, ele só será noticiado no final de seu destino, e terá que retransmitir tudo de novo. A primeira abordagem se houver falha no meio do caminho ela responderá muito melhor, mas ela terá um overhead muito alto, ter que enviar confirmação toda hora pode não valer muita a pena.

#### 7. Determine qual das camadas do modelo OSI trata de cada uma das tarefas a seguir:
* Dividir o fluxo de bits transmitidos em quadros.
* Definir a rota que será utilizada na sub-rede.

a) Camada de enlace de dados, é usado quando ela mascara os erros de transmissão para a camada de rede(para que a camada de rede não veja), fazendo com que o transmissor divida os dados de entrada em quadros de dados(que, em geral, tem algumas centenas ou alguns milhares de bytes).

b) Camada de rede, é nela que é determinado a maneira como os pacotes serão transportados(roteados) da origem até o destino.

#### 8. Um sistema tem uma hierarquia de protocolos com n camadas. As aplicações geram mensagens com M bytes de comprimento. Em cada uma das camadas, é acrescentado um cabeçalho com h bytes. Qual é a fração da largura de banda da rede é preenchida pelos cabeçalhos?

fração da largura de banda = h.n/(M + h.n)

#### 9. Cite dois aspectos em que o modelo de referência OSI e o modelo de referência TCP/IP são iguais. Agora cite dois aspectos em que eles são diferentes.
O uso da camada de aplicação, a única diferença nesse sentido é que o modelo TCP/IP não tem as camadas de sessão nem de apresentação, não havia necessidade, então ele usa a camada de aplicação para meio que tapar esse "buraco", mas tirando isso é usada da mesma forma, tem até protocolos em comum usados na mesma camada, como o HTTP por exemplo.

Outros aspectos iguais são nas duas terem também a camada de enlace e de transporte.

E outro aspecto diferente que eu acho importante citar, seria na camada de transporte, o modelo TCP/IP ter um serviço orientado a conexão e não orientado a conexão, dando essa versatilidade com os protocolos TCP e UDP, e no OSI só o orientado a conexão.

Ambos se baseiam no conceito de uma pilha de protocolos independentes.

#### 10. Qual é a principal diferença entre o TCP e o UDP?
TCP usa um serviço orientado à conexão
UDP não orientado a conexão/ não é confiável

#### 20. Compare o retardo do ALOHA puro com o do slotted ALOHA com uma carga mínima (por exemplo, apenas uma estação usando o canal). Qual deles é menor? Explique sua resposta.

Slotted ALOHA, pois seu throughput é maior já que sua probabilidade de colisão é menor em relação ao ALOHA puro, logo menos retardo.

Vulnerable Time = Frame Transmission time.(duas vezes menor em relação ao ALOHA puro)

Throughput = G x e^-G; Where G is the number of stations wish to transmit in the same time.

Maximum throughput = 0.368 for G=1 (o dobro do ALOHA original).



#### 21. Suponha um enlace de comunicação que utiliza CRC com o polinômio gerador x8+x5+x4+x2+1 que recebe duas mensagens:
10011001111010101111000
10011001111010101110000
1. Qual é o tamanho do total de verificação deste enlace? Justifique

Segundo o método do código polinomial o tamanho do nosso CRC seria igual ao grau do polinômio gerador. O grau do nosso polinômio gerador é 8, esse será o tamanho do código de verificação que será acrescentado na extremidade de baixa ordem do nosso quadro.

2. Estas mensagens contêm erros? Justifique.
hora do teste

10011001111010101111000 % 100110101 = 0 -> logo não teve erro na primeira mensagem
10011001111010101110000 % 100110101 = 1000 -> segunda mensagem teve erro de transmissão

3. Encontre a mensagem original (sem o total de verificação) das
mensagens sem erro.

10011001111010101111000 -> 100110011110101 (mensagem original)

4. Para as mensagens que não contêm erros, apresente um erro que
não seria detectado pelo CRC.

se eu pegar a primeira mensagem 10011001111010101111000 e soma-la ao meu gerador, se tornará outro múltiplo dele onde que a divisão continuará zero, mas mesmo assim com alguns bits trocados.

exemplo de como nossa mensagem poderia ficar com erro mais indetectável pelo nosso CRC:
10011001111010001001101


#### 22. Uma LAN CSMA/CD de 10 Mbps (não 802.3) com a extensão de 1 km tem uma velocidade de propagação de 200m/s. Não são permitidos repetidores nesse sistema. Os quadros de dados têm 256 bits, incluindo 32 bits de cabeçalho, totais de verificação e outras formas de overhead. O primeiro slot de bits depois de uma transmissão bem-sucedida é reservado para o receptor capturar o canal com o objetivo de enviar um quadro de confirmação de 32 bits. Qual será a taxa de dados efetiva, excluindo o overhead, se partirmos do princípio de que não há colisões?
