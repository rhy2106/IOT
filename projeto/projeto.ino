#include <LiquidCrystal.h>
#include <Servo.h>


#define vermelho 10
#define verde 9
#define buzzer 8
#define botao_esquerda 3
#define botao_direita 2

int pos = 0;
int erro_cnt = 0;
int pos_servo = 0;
int digito = 0;
String input = "";
String senha = "01234";
String estado = "fechado";

Servo servo;
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Numero de colunas e linhas do LCD
  print_digite_senha();

  servo.attach(13,550,2500);

  pinMode(vermelho,OUTPUT); // led vermelho
  pinMode(verde, OUTPUT); // led verde
  pinMode(buzzer, OUTPUT); // buzzer

  pinMode(botao_direita,INPUT_PULLUP); // Botao 1
  pinMode(botao_esquerda,INPUT_PULLUP); // Botao 2
                                        //
  attachInterrupt(digitalPinToInterrupt(botao_direita), mudar_digito, FALLING); // 0 - 9
  attachInterrupt(digitalPinToInterrupt(botao_esquerda), proximo_digito, FALLING); // _0000 -> 0_000
}

void loop(){
  if(estado == "fechado" || estado == "alarme"){
    digitalWrite(vermelho,HIGH);
    digitalWrite(verde,LOW);
    if(pos_servo > 0) pos_servo--;
    if(estado == "alarme"){
      tone(buzzer,440);
      delay(1000 * erro_cnt*erro_cnt);
      noTone(buzzer);
      estado = "fechado";
    }
  } else if(estado == "aberto"){
    digitalWrite(vermelho,LOW);
    digitalWrite(verde,HIGH);
    if(pos_servo < 90) pos_servo++;
  }
  servo.write(pos_servo);
  delay(15);
}

void print_digite_senha(){
  lcd.setCursor(0,0);
  lcd.print("Digite a senha: ");
  lcd.setCursor(0, 1);
  lcd.print("00000           ");
  lcd.setCursor(0, 1);
  lcd.print(input);
  lcd.setCursor(pos, 1);
  lcd.print(digito);
  lcd.setCursor(15,1); // posicao do digito na ultima posicao do lcd
  lcd.print(pos);
}

void print_senha_errada(){
  lcd.setCursor(0, 0);
  lcd.print("Senha Errada    ");
  lcd.setCursor(0, 1);
  lcd.print("Erro N:         ");
  lcd.setCursor(8, 1);
  lcd.print(erro_cnt);
}

void print_aberto(){
  lcd.setCursor(0, 0);
  lcd.print("Cofre Aberto    ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void mudar_digito(){ // 0 - 9
  delay(15);
  if(estado == "alarme") return;
  digito = (digito + 1) % 10;
  if(pos < 5) print_digite_senha();
}

void proximo_digito(){ // _0000 -> 0_000
  delay(15);
  if(estado == "alarme") return;
  input += digito;
  digito = 0;
  pos++;
  if(pos < 5) print_digite_senha();
  else if(pos == 5){ // senha digitada
    if(senha != input){
      estado = "fechado";
      erro_cnt++;
      if(erro_cnt >= 3) estado = "alarme";
      print_senha_errada();
    } else {
      estado = "aberto";
      erro_cnt = 0;
      print_aberto();
    }
  } else if(pos == 6){ // prox senha
    estado = "fechado"; // fechar caso esteja aberto
    pos = 0;
    input = "";
    digito = 0;
    print_digite_senha();
  }
}
