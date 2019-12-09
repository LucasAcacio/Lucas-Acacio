//BLOCO DE BIBLIOTECAS
#include <LiquidCrystal.h>

//***************ESQUEMA LCD*******************
//  00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 
//  10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F
//**               HEXA DECIMAL                  **

LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
//BLOCO DE VARIAVEIS(SEGUE LEGENDA):
// A= 5 centavos
// B= 25 centavos
// C= 50 centavos
// D= 1 real
// E= 10 centavos
int contA = 0;
int contB = 0;
int contC = 0;
int contD = 0;
int contE = 0;

String scontA ;
String scontB ;
String scontC ;
String scontD ;
String scontE ;
String quant1 ;
String quant2 ;

float Bruto_A =0;
float Bruto_B =0;
float Bruto_C =0;
float Bruto_D =0;
float Bruto_E =0;
float Valor_total = 0;

int Valor_botao = 2;

//BLOCO DE SET DE PINOS DO LDR
int ldrE = A0;
int ldrA = A1;
int ldrC = A2;
int ldrB = A3;
int ldrD = A4;

int botao = 12;

void setup(){
//BLOCO LCD (LIGAR)
  lcd.begin(16,2);

//BLOCO LDR (SETAR OS INPUTS)
  pinMode(ldrA,INPUT);
  pinMode(ldrB,INPUT);
  pinMode(ldrC,INPUT);
  pinMode(ldrD,INPUT);
  pinMode(ldrE,INPUT);

  pinMode(botao,INPUT_PULLUP);
  
 //BLOCO DE TESTE DO LCD
  lcd.setCursor(1, 0);
  lcd.print("Oi! Eu sou ");
  lcd.setCursor(3,1);
  lcd.print("contador");
  delay(2000);
  lcd.clear();
  Serial.begin(9600);
  
}

void loop(){
  String quant1 = String(" 5 10 25 50 100");
  String quant2 = String(scontA + " " + scontE + " " + scontB + " " + scontC + "  " + scontD);
  
  //BLOCO DE LEITURA DOS LDRS
  int valLdrA = analogRead(ldrA);
  int valLdrB = analogRead(ldrB);
  int valLdrC = analogRead(ldrC);
  int valLdrD = analogRead(ldrD);
  int valLdrE = analogRead(ldrE);

  ;
  
  //SOMA DOS CONTADORES
  if (valLdrA <= 940){
  contA += 1;
  String scontA = String(contA);
  String scontB = String(contB);
  String scontC = String(contC);
  String scontD = String(contD);
  String scontE = String(contE);
  
  String quant2 = String(scontA + " " + scontE + " " + scontB + " " + scontC + "  " + scontD);
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print(quant1);
  lcd.setCursor(1,1);
  lcd.print(quant2);
  delay(100);
  }
  
  if (valLdrB <= 930){
  contB += 1;
  String scontA = String(contA);
  String scontB = String(contB);
  String scontC = String(contC);
  String scontD = String(contD);
  String scontE = String(contE);
  String quant2 = String(scontA + " " + scontE + " " + scontB + " " + scontC + "  " + scontD);
  lcd.clear(); 
 lcd.setCursor(0,0);
 lcd.print(quant1);
 lcd.setCursor(1,1);
 lcd.print(quant2);
  delay(100);
  }
  
  if (valLdrC <= 930){
  contC += 1;
  String scontA = String(contA);
  String scontB = String(contB);
  String scontC = String(contC);
  String scontD = String(contD);
  String scontE = String(contE);
  String quant2 = String(scontA + " " + scontE + " " + scontB + " " + scontC + "  " + scontD);
  lcd.clear(); 
 lcd.setCursor(0,0);
 lcd.print(quant1);
 lcd.setCursor(1,1);
 lcd.print(quant2);
  delay(100);
  }
  
  if (valLdrD <= 930){
  contD += 1;
  String scontA = String(contA);
  String scontB = String(contB);
  String scontC = String(contC);
  String scontD = String(contD);
  String scontE = String(contE);
  String quant2 = String(scontA + " " + scontE + " " + scontB + " " + scontC + "  " + scontD);
  lcd.clear(); 
 lcd.setCursor(0,0);
 lcd.print(quant1);
 lcd.setCursor(1,1);
 lcd.print(quant2);
  delay(100);

  }
 
  if (valLdrE <= 940){
  contE += 1;
  String scontA = String(contA);
  String scontB = String(contB);
  String scontC = String(contC);
  String scontD = String(contD);
  String scontE = String(contE);
  String quant2 = String(scontA + " " + scontE + " " + scontB + " " + scontC + "  " + scontD);
  lcd.clear(); 
 lcd.setCursor(0,0);
 lcd.print(quant1);
 lcd.setCursor(1,1);
 lcd.print(quant2);
  delay(100);
  }
  
  //TRANSFORMAÇÃO DOS VALORES
  Bruto_E = contE * 0.10;
  Bruto_B = contB * 0.25;
  Bruto_C = contC * 0.50;
  Bruto_D = contD;
  Bruto_A = contA * 0.05;
  Valor_total = Bruto_A + Bruto_B + Bruto_C + Bruto_D + Bruto_E;

 String valor_rs = String(Valor_total);
 String rs = String("RS" + valor_rs);

 
 
  
 int botaoVal = digitalRead(botao);
 if (botaoVal == LOW){
 Valor_botao += 1;
 delay(500);
}

 if ((Valor_botao == 2) && (botaoVal == 0)){
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("VALOR RECEBIDO:");
 lcd.setCursor(1,3);
 lcd.print(rs);
 
 }
 else if((Valor_botao == 3) && (botaoVal == 0)){
 String scontA = String(contA);
  String scontB = String(contB);
  String scontC = String(contC);
  String scontD = String(contD);
  String scontE = String(contE);
  String quant1 = String(" 5 10 25 50 100");
  String quant2 = String(scontA + " " + scontE + " " + scontB + " " + scontC + "  " + scontD);
  
 lcd.clear(); 
 lcd.setCursor(0,0);
 lcd.print(quant1);
 lcd.setCursor(1,1);
 lcd.print(quant2);
 
 }
 else{
  Valor_botao = 1;
 }
  Serial.println(valLdrC);
}
