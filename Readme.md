🎢 Guia Completo para Testar Seus Circuitos: Do Zero à Simulação! 🚀
Este guia te levará numa jornada emocionante, desde a criação do seu circuito até a análise dos resultados da simulação! Prepare-se para dominar as duas abordagens: Bottom-Up (começando pelas portas lógicas) e Top-Down (começando pela descrição do hardware).

🧰 Abordagem Bottom-Up: Construindo Bloco por Bloco 🧱
Objetivo: Criar um multiplicador de 4 bits com saída de 8 bits e testá-lo usando o SpiceOpus.

Passo-a-Passo:

🎨 Criando o Circuito no Logisim: Comece desenhando seu multiplicador no Logisim, usando portas lógicas e conexões.

💻 Escrevendo o Código Genlib: Traduza seu circuito do Logisim para código usando a biblioteca Genlib.

📄 Gerando o Arquivo VST: Este arquivo é essencial para visualizar o esquema do seu circuito. Use os comandos:

Bash

Insert code
$ export MBK_IN_LO=spi
    $ export MBK_OUT_LO=spi
    $ genlib -v nome_genlib
🔍 Visualizando o Esquema: Veja como seu circuito se conecta usando o comando:
Bash

Insert code
$ xsch -l nome
🗺️ Criando o Layout Físico: Organize as células do seu circuito no espaço físico com o comando:
Bash

Insert code
$ alliance-ocp nome nome_posicionado
🔄 Roteando as Células: Conecte as células do seu circuito usando o Nero:
Bash

Insert code
$ nero -p nome_posicionado nome nome_roteado
⚙️ Extraindo Parâmetros do Spice: Obtenha os parâmetros para simulação usando o Cougar:
Bash

Insert code
$ cougar -t -ac nome_ap
📄 Criando o Arquivo .cir: Crie o arquivo de netlists, importando o arquivo .spi.

⚡️ Simulando no SpiceOpus: Simule seu circuito e gere gráficos!

Bash

Insert code
$ spiceopus
    $ nomeDoCircuito.cir
📈 Analisando os Resultados: Examine os gráficos gerados pelo SpiceOpus para entender o comportamento do seu circuito.
🏗️ Abordagem Top-Down: Do Geral aos Detalhes 🗺️
Objetivo: Criar um multiplicador de 4 bits usando VHDL e testá-lo com o Asimut.

Passo-a-Passo:

📝 Escrevendo o Código VHDL: Descreva o comportamento do seu multiplicador em VHDL.

🧪 Criando o Arquivo de Testes: Defina as entradas e saídas esperadas para testar seu multiplicador.

⚙️ Gerando o Arquivo .vbe: Use o Vasy para criar o arquivo .vbe:

Bash

Insert code
$ vasy -a -I vhdl -a mult4
💪 Otimizando com o Boom: Reduza o número de portas lógicas do seu circuito:
Bash

Insert code
$ boom -A -d 100 mult4 mult4_boom
✅ Verificando com o Proof: Certifique-se de que a lógica do seu circuito não foi alterada:
Bash

Insert code
$ proof -a -d mult4 mult4_boom
📄 Gerando o VST: Crie o arquivo VST a partir do .vbe usando o Boog:
Bash

Insert code
$ boog mult4_boom mult4_boog
🚀 Otimizando Fisicamente com o Loon: Otimize o layout físico do seu circuito:
Bash

Insert code
$ loon -m 4 mult4_boog mult4_bbl
⚙️ Gerando Entradas de Teste: Use o Alliance-Genpat para criar entradas de teste a partir do arquivo .C:
Bash

Insert code
$ alliance-genpat -v pattern_mult4
🔍 Visualizando os Testes: Veja as entradas de teste usando o XPat:
Bash

Insert code
$ xpat -l pat_multi.pat
🗺️ Criando o Layout Físico: Organize as células do seu circuito no espaço físico:
Bash

Insert code
$ alliance-ocp mult4_bbl mult4_ocp
🔄 Roteando as Células: Conecte as células do seu circuito usando o Nero:
Bash

Insert code
$ nero -p mult4_ocp mult4_bbl mult4_nero
🔄 Mudando a Variável de Ambiente: Configure a variável de ambiente:
Bash

Insert code
$ export MBK_OUT_LO=vst
⚙️ Extraindo Parâmetros do Spice: Obtenha os parâmetros para simulação:
Bash

Insert code
$ cougar -t -ac mult4_nero mult4_cougar
🧪 Testando com o Asimut: Execute testes exaustivos no seu circuito:
Bash

Insert code
$ asimut mult4_cougar pat_multi pat_mult_result
📝 Analisando os Resultados: Examine o arquivo de testes para entender o comportamento do seu circuito.
🎉 Parabéns! Você concluiu o guia e está pronto para criar e testar seus próprios circuitos! 🎉