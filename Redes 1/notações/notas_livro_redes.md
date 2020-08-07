## **Acrônimos:**
* VPNs (Virtual Private Networks)
* NFC (Near Field Communication)
* RFID (Radio Frequency IDentification)
* LAN (Local Area Network)
* AP (Access Point)
# Termos importantes
#### Peer-to-peer(do inglês par-a-par ou ponto-a-ponto, famoso P2P)
é uma arquitetura de redes de computadores onde cada um dos pontos ou nós da rede funciona tanto como cliente quanto como servidor, permitindo compartilhamentos de serviços e dados sem a necessidade de um servidor central.
Seu projeto tem como objetivo distribuir um serviço totalmente descentralizado e organizado, equilibrando, automaticamente, as cargas de armazenamento e processamento de forma dinâmica entre todos os computadores participantes à medida que as máquinas entram e saem do serviço.

# Tópicos do livro
## HARDWARE DE REDE
redes de computadores hoje que se destacam além das demais: a tecnologia de transmissão e a escala.
#### Tecnologias de transmissão
Em termos gerais, há dois tipos de tecnologias de transmissão em uso disseminado nos dias de hoje: enlaces de **broadcast** e enlaces **ponto a ponto**.

Os enlaces ponto a ponto conectam pares de máquinas individuais. Para ir da origem ao destino em uma rede composta de enlaces ponto a ponto, mensagens curtas, chamadas **pacotes** em certos contextos, talvez tenham de visitar primeiro uma ou mais máquinas intermediárias.
A transmissão ponto a ponto com exatamente um transmissor e exatamente um receptor às vezes é chamada de **unicasting**.

Já as redes de broadcast tem apenas um canal de comunicação, compartilhado por todas as máquinas da rede; os pacotes enviados por qualquer máquina são recebidos por todas as outras.

**Obs:** *Uma rede sem fio é um exemplo comum de um enlace broadcast, com a comunicação compartilhada por uma região de cobertura que depende do canal sem fios e da máquina transmissora.*

##### Escala ou escalabilidade
Um critério alternativo para classificar as redes. A distância é importante como métrica de classificação, pois diferentes tecnologias são usadas em diferentes escalas.

![escalabilidade](images/escalabilidade.png)

#### Redes Pessoais
As redes pessoais, ou PANs (Personal Area Networks), permitem que dispositivos se comuniquem pelo
alcance de uma pessoa.

**Bluetooth** as redes Bluetooth usam um paradigma mestre-escravo.

![bluetooth](images/bluetooth.png)

A unidade do sistema(PC) normalmente é o mestre, e os periféricos, escravos. O mestre diz aos escravos quais endereços usar, quando eles podem transmitir, por quanto tempo, quais frequências eles podem usar e assim por diante.

#### Redes Locais
**Rede local**, ou **LAN(Local Area Network).** Uma LAN é uma rede particular que opera dentro e próximo de um único prédio, como uma residência, um escritório ou uma fábrica. As LANs são muito usadas para conectar computadores pessoais e aparelhos eletrônicos, para permitir que compartilhem recursos (como impressoras) e troquem informações.

 **obs**: Quando as LANs são usadas pelas empresas, elas são chamadas **redes empresariais.**
  LANs sem fio são muito populares atualmente, especialmente nas residências, prédios de escritórios antigos e lugares onde a instalção de cabos é muito trabalhosa. Nesses sistemas, cada computador tem um rádio modem e uma antena, que ele usa para se comunicar com outros computadores. Quase sempre, cada computador fala com um dispositivo no teto, chamado **ponto de acesso**, **roteador sem fio** ou **estação-base**,repassa os pacotes entre os computadores sem fio e também entre eles e a Internet. Ser o AP é como ser o garoto popular na escola, pois todos querem falar com você. Porém, se os outros computadores estiverem próximos o suficiente, eles podem se comunicar diretamente em uma configuração peer-to-peer.
  Existe um padrão para as LANs sem fios, chamado **IEEE 802.11**, nosso famigerado **WiFi**. Ele trabalha em velocidades de 11 a centenas de Mbps.
![WiFi](images/ponto_de_acesso.png)
 As LANs com fios Utilizam uma série de tecnologias de transmissão diferentes. A maioria delas usa fios de cobre, mas algumas usam fibra óptica. A topologia de muitas LANs com fios é embutida a partir de enlaces ponto a ponto. O IEEE 802.3, popularmente

## Curiosidades:
* ##### Napster
 foi o programa de compartilhamento de arquivos em rede P2P criado em 1999, que protagonizou o primeiro grande episódio na luta jurídica entre a indústria fonográfica e as redes de compartilhamento de música na internet.

* ##### Talk do UNIX
troca de mensagens instantâneas. Esses recurso, derivado do programa talk do UNIX, em uso desde aproximadamente 1970.

* ##### Comércio eletrônico
![abreviacao](images/abreviacoes.png)

* #### DCS1000 (Carnivore)
Carnivore foi um sistema implementado pelo Federal Bureau of investigation - FBI, projetado para monitorar as comunicações de e-mail e eletrônicos. É utilizado um packet siniffer personalizável que pode monitorar todo o tráfego de um usuário da internet.

* #### Phishing
é o crime de enganar as pessoas para que compartilhem informações confidenciais como senhas e número de cartões de crédito. Como uma verdadeira pescaria, há mais de uma maneira fisgar uma vítima, mas uma tática de phishing é a mais comum.

* #### Ken Olsen
'Não há nenhuma razão para qualquer indivíduo ter um computador em casa'.
