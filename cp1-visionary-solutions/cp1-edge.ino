#include <LiquidCrystal.h> // Biblioteca para controle do display LCD
#include <string.h>        // Biblioteca padrão para manipulação de strings (strlen)

// Inicializa o display LCD nos pinos (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// Pino analógico conectado ao sensor LDR (fotoresistor)
const short int pinoLDR = A0;

// LEDs de sinalização (verde = ok, amarelo = alerta, vermelho = perigo)
const short int ledVermelho = 6;
const short int ledAmarelo  = 5;
const short int ledVerde    = 4;

// Buzzer que emite som de alerta
const short int pinoBuzzer = 3;

// Botão físico usado para calibração dos níveis de luz
const short int botaoIniciar = 2;

// Limites durante o setup
int limiarBaixo = 30;
int limiarAlto = 70;

// Tempo de espera entre leituras (em milissegundos)
const int tempoPrecisao = 100;

// Animação logo Visionary Solutions
int i;
//Cria caracter A personalizado
byte AA[8] = {
  B00001,
  B00010,
  B00100,
  B00100,
  B01000,
  B10000,
  B10000,
  B10000
};
//Cria caracter B personalizado
byte BB[8] = {
  B10000,
  B10000,
  B10000,
  B01000,
  B00100,
  B00100,
  B00010,
  B00001
};
//Cria caracter V personalizado
byte VV[8] = {   
  B10001,
  B10001,
  B10001,
  B10001,
  B10011,
  B01010,
  B01010,
  B00110,
};
 
//Cria caracter S personalizado
byte S[8] = {   
  B11000,
  B11111,
  B10000,
  B10000,
  B01111,
  B00010,
  B00110,
  B11000
};
 
//Cria caracter G personalizado
byte GG[8] = {   
  B10000,
  B01000,
  B00100,
  B00100,
  B00010,
  B00001,
  B00001,
  B00001
}; 
//Cria caracter H personalizado
byte H[8] = {
  B00001,
  B00001,
  B00001,
  B00010,
  B00100,
  B00100,
  B01000,
  B10000
};

void setup() {
  // Configura os pinos como entrada ou saída
  pinMode(pinoLDR, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(botaoIniciar, INPUT_PULLUP); // Usa resistor interno de pull-up

  //Cria os caractéres especiais na memória do LCD
  lcd.createChar(0, AA);
  lcd.createChar(1, BB);
  lcd.createChar(2, VV);   
  lcd.createChar(3, S);   
  lcd.createChar(4, GG);   
  lcd.createChar(5, H);
  // Inicializa o display LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD   
  lcd.setCursor(16, 0);   
  lcd.print("   Visionary "); //Escreve no LCD "Visionary!"   
  lcd.setCursor(16, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD   
  lcd.print("    Solutions "); //Escreve no LCD "Solutions"   
  delay(3000);   
  
  //efeito de deslocamento para esquerda   
  for (i =0; i <16; i++){     
  lcd.scrollDisplayLeft();     
  delay(20);   
  }   
  delay(1000); //Aguarda 1 segundo   
  
  //Blinkando   
  delay(400);    
  lcd.noDisplay();   
  delay(400);   
  lcd.display();   
  delay(400);   
  lcd.noDisplay();   
  delay(400);   
  lcd.display();   
  delay(400);   
  lcd.display();   
  delay(400);   
  
  //para esquerda   
  for (i =0; i <16; i++){     
  lcd.scrollDisplayLeft();     
  delay(40);   
  }    
  
  lcd.clear();   
  
  //caracteres especiais   
  lcd.setCursor(17,0);  
  lcd.write(byte(2));
  lcd.setCursor(18,1);
  lcd.write(byte(3));
  lcd.setCursor(16,0);
  lcd.write(byte(0));
  
  lcd.setCursor(16,1);
  lcd.write(byte(1));
  lcd.setCursor(19,0);
  lcd.write(byte(4));
  lcd.setCursor(19,1);
  lcd.write(byte(5));
  delay(500);   
  
  // para esquerda   
  for (i =0; i <10; i++){     
  lcd.scrollDisplayLeft();     
  delay(20); //Aguarda 1 segundo   
  }   
  delay(1000); //1 segundo      
  
  //Pisca  
  delay(400);   
  lcd.noDisplay();   
  delay(400);   
  lcd.display();   
  delay(400);   
  lcd.noDisplay();   
  delay(400);   
  lcd.display();   
  delay(400);   
  lcd.display();   
  delay(400);   
  
  //deslocamento para Direita   
  for (i =0; i <12; i++){     
  lcd.scrollDisplayRight();     
  delay(20); //Aguarda 1 segundo   
  }   
  delay(500); //Aguarda 1/0.5 segundo   
  
  lcd.clear();

  lcd.print("      BEM"); // Mensagem inicial
  lcd.setCursor(0, 1); // Vai para a segunda linha
  lcd.print("     VINDO!"); 
  delay(3000); // Exibe a mensagem por 3 segundos
  lcd.clear(); // Limpa o display

  // Inicia processo de calibração do LDR
  setupLDR();
  delay(1000);
}

void loop() {
  // Leitura do valor do sensor LDR (0 a 1023)
 int leituraLDR = analogRead(pinoLDR);
  // Mapeia o valor lido para escala de 0 a 100%
 int porcentagemLum = map(leituraLDR, 0, 1023, 100, 0); // 0 = escuro, 100 = muito claro
  // // Exibe o nível de luz no LCD
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Lum: "); 
 lcd.print(porcentagemLum); 
 lcd.print("%          ");
  // Verifica os níveis de luminosidade
 if (porcentagemLum <= limiarBaixo) {
    // Nível ideal: LED verde ligado
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(pinoBuzzer, LOW);
    lcd.setCursor(0, 1); 
    lcd.print("Status: OK!             ");
    noTone(pinoBuzzer);
 } else if (porcentagemLum > limiarBaixo && porcentagemLum <= limiarAlto){
    // Nível de alerta: LED amarelo ligado
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    lcd.setCursor(0, 1); 
    lcd.print("Status: ALERTA!         ");
    // Ativa o buzzer por 3s
    digitalWrite(pinoBuzzer, HIGH);
    tone(pinoBuzzer, 1000); // Emite som em 1000 Hz
    delay(3000);
    noTone(pinoBuzzer);
 }
  else{
    // Nível problemático
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    lcd.setCursor(0, 1); 
    lcd.print("Status: PERIGO!           ");
    // Ativa o buzzer por 1s
    digitalWrite(pinoBuzzer, HIGH);
    tone(pinoBuzzer, 500); // Emite som em 500 Hz
    delay(1000);
    noTone(pinoBuzzer);  
  }
 delay(1000);
}

// Inicialização do sensor LDR, guiado por mensagens no display
void setupLDR() {
  lcd.clear();
  lcd.setCursor(0, 0);

  // Mensagem de início do setup
  char mensagem[] = "Iniciando SETUP";
  animacaoPrint(mensagem, 150);
  lcd.setCursor(0, 1);
  lcd.print("Pressione");

  // Pressionar para continuar
  while (digitalRead(botaoIniciar) == HIGH);
  delay(100);
  while (digitalRead(botaoIniciar) == LOW);
}

// Texto no LCD com efeito de digitação
// Aparece a logo
void animacaoPrint(char mensagem[], int tempo) {
  lcd.clear();

  for (int i = 0; i < strlen(mensagem); i++) {
    lcd.print(mensagem[i]);
    delay(tempo);

    if (i > 14) {
      lcd.setCursor(i - 15, 1);
    }
  }
}