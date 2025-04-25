<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
</head>
<body>
  <h1>🍷 Vinheria Agnello - Sistema de Monitoramento de Luminosidade com Arduino</h1>

  <p>Projeto desenvolvido para o Checkpoint 01 da disciplina <strong>Edge Computing & Computer Systems</strong> do curso de <strong>Engenharia de Software - FIAP</strong>.</p>

  <h2>🧠 Objetivo</h2>
  <p>Desenvolver um sistema embarcado com <strong>Arduino</strong> para <strong>monitorar os níveis de luminosidade</strong> no ambiente onde os vinhos são armazenados, visando preservar sua qualidade. O sistema deve sinalizar visual e sonoramente os diferentes níveis de luz, além de exibir informações em um <strong>display LCD</strong>.</p>

  <h2>⚙️ Funcionalidades</h2>
  <ul>
    <li>💡 Monitoramento contínuo da luminosidade com sensor LDR</li>
    <li>🟢🟡🔴 Indicação visual com LEDs para níveis de luz:
      <ul>
        <li>Verde: OK</li>
        <li>Amarelo: Alerta</li>
        <li>Vermelho: Problema</li>
      </ul>
    </li>
    <li>🔊 Alarme com buzzer em nível de alerta</li>
    <li>📟 Display LCD com mensagem de boas-vindas e status atual</li>
    <li>🔁 Leitura periódica com atualização a cada segundo</li>
  </ul>

  <h2>🧰 Componentes Utilizados</h2>
  <table border="1" cellspacing="0" cellpadding="4">
    <tr><th>Componente</th><th>Quantidade</th><th>Função</th></tr>
    <tr><td>Arduino Uno</td><td>1</td><td>Microcontrolador do sistema</td></tr>
    <tr><td>Sensor LDR</td><td>1</td><td>Sensor de luminosidade (entrada analógica)</td></tr>
    <tr><td>Resistor 10kΩ</td><td>1</td><td>Pull-down para o LDR</td></tr>
    <tr><td>LED Verde</td><td>1</td><td>Indica condição ideal</td></tr>
    <tr><td>LED Amarelo</td><td>1</td><td>Indica condição de alerta</td></tr>
    <tr><td>LED Vermelho</td><td>1</td><td>Indica condição crítica</td></tr>
    <tr><td>Buzzer</td><td>1</td><td>Alarme sonoro em caso de alerta</td></tr>
    <tr><td>Display LCD 16x2</td><td>1</td><td>Exibição de status e boas-vindas</td></tr>
    <tr><td>Potenciômetro (10kΩ)</td><td>1</td><td>Ajuste de contraste do LCD</td></tr>
    <tr><td>Jumpers e Protoboard</td><td>Diversos</td><td>Conexões elétricas</td></tr>
  </table>

  <h2>🔌 Esquema do Circuito</h2>
  <p><strong>Resumo do circuito:</strong></p>
  <ul>
    <li>O LDR está conectado ao pino A0 do Arduino, com resistor de 10kΩ ao GND.</li>
    <li>LEDs: pinos 2 (verde), 3 (amarelo), 4 (vermelho)</li>
    <li>Buzzer: pino 5</li>
    <li>LCD: pinos 7 a 12</li>
    <li>Potenciômetro ajusta o contraste no pino V0 do LCD</li>
  </ul>

  <h2>🧮 Lógica do Sistema</h2>
  <ol>
    <li>O Arduino lê o valor do LDR (0–1023).</li>
    <li>Esse valor é convertido para percentual de 0 a 100% com <code>map()</code>.</li>
    <li>Com base nesse valor:
      <ul>
        <li>0% a 30%: LED verde aceso</li>
        <li>31% a 60%: LED amarelo aceso + buzzer</li>
        <li>Acima de 60%: LED vermelho aceso</li>
      </ul>
    </li>
    <li>O LCD exibe a porcentagem de luz e o status atual.</li>
  </ol>

  <h2>🛠 Estrutura do Projeto</h2>
  <pre><code>
VinheriaAgnello/
├── codigo.ino               # Código-fonte comentado (Arduino C++)
├── README.md                # Este arquivo
├── tinkercad_link.txt       # Link para simulação no Tinkercad
├── video_apresentacao.mp4   # Vídeo explicativo (até 3 minutos)
└── imagens/                 # Prints do circuito e LCD (opcional)
  </code></pre>

  <h2>🔁 Como Reproduzir</h2>
  <p><strong>Requisitos:</strong></p>
  <ul>
    <li>Conta no <a href="https://www.wokwi.com/" target="_blank">Tinkercad</a></li>
    <li>Arduino Uno virtual</li>
    <li>Componentes listados acima</li>
  </ul>
  <p><strong>Passos:</strong></p>
  <ol>
    <li>Acesse o <a href="#">link da simulação no Wokwi</a>.</li>
    <li>Copie o código para o editor de código.</li>
    <li>Monte o circuito conforme o esquema.</li>
    <li>Clique em "Iniciar Simulação".</li>
    <li>Observe os LEDs, o buzzer e o display em ação.</li>
  </ol>

  <h2>🎥 Vídeo Explicativo</h2>
  <p>📺 Assista ao vídeo explicando o projeto: <a href="#">Link para o vídeo</a></p>

  <h2>✨ Possíveis Melhorias Futuras</h2>
  <ul>
    <li>Adicionar sensores de temperatura e umidade</li>
    <li>Envio de dados para nuvem com ESP8266</li>
    <li>Log histórico de luminosidade</li>
    <li>Interface web para visualização remota</li>
  </ul>

  <h2>👨‍💻 Autoria</h2>
  <p>Projeto desenvolvido por <strong>Visionary Solutions</strong><br>
  Equipe: Arthur Araujo Tenorio, Breno Gonçalves Báo, Rodrigo Cardoso Tadeo, Vinicius Cavalcanti dos Reis<br>
  Curso: Engenharia de Software – FIAP<br>
  Disciplina: Edge Computing & Computer Systems<br>
  Professor: Dr. Fábio H. Cabrini</p>
</body>
</html>