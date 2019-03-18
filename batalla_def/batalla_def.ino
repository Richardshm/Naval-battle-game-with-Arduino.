#include "LedControl.h"
/*
 pin 5 is connected to the DataIn 
 pin 7 is connected to the CLK 
 pin 6 is connected to LOAD 
 */
LedControl lcA=LedControl(5,7,6,1);
LedControl lcB=LedControl(8,10,9,1);

const byte EstadoInicio = 0;
const byte EstadoAAcorazado = 3;
const byte EstadoACrucero = 2;
const byte EstadoADestructor = 1;
const byte EstadoBAcorazado = 6;
const byte EstadoBCrucero = 5;
const byte EstadoBDestructor = 4;
const byte EstadoADisparo = 7;
const byte EstadoBDisparo = 8;
const byte EstadoFin = 9;
byte Estado = EstadoInicio;
byte Abattleshipv;
byte Abattleshiph;
byte Acruiserv;
byte Acruiserh;
byte Adestroyerv;
byte Adestroyerh;
byte Atorpedov;
byte Atorpedoh;
byte Ahundidos;
byte ArrayAtorpv[16];
byte ArrayAtorph[16];
bool Asunk[3];
byte Bbattleshipv;
byte Bbattleshiph;
byte Bcruiserv;
byte Bcruiserh;
byte Bdestroyerv;
byte Bdestroyerh;
byte Btorpedov;
byte Btorpedoh;
byte Bhundidos;
byte ArrayBtorpv[16];
byte ArrayBtorph[16];
bool Bsunk[3];
byte APulsadorVerticalAntes = LOW;
byte APulsadorVerticalAhora = LOW;
byte APulsadorHorizontalAntes = LOW;
byte APulsadorHorizontalAhora = LOW;
byte APulsadorAceptarAntes = LOW;
byte APulsadorAceptarAhora = LOW;
byte BPulsadorVerticalAntes = LOW;
byte BPulsadorVerticalAhora = LOW;
byte BPulsadorHorizontalAntes = LOW;
byte BPulsadorHorizontalAhora = LOW;
byte BPulsadorAceptarAntes = LOW;
byte BPulsadorAceptarAhora = LOW;
void setup() {
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  lcA.shutdown(0,false);
  lcA.setIntensity(0,4);
  lcA.clearDisplay(0);
  lcB.shutdown(0,false);
  lcB.setIntensity(0,4);
  lcB.clearDisplay(0);
  Estado = EstadoInicio;
}
void loop() {
  APulsadorVerticalAntes = APulsadorVerticalAhora;
  APulsadorVerticalAhora = digitalRead(4);  
  APulsadorHorizontalAntes = APulsadorHorizontalAhora;
  APulsadorHorizontalAhora = digitalRead(3);
  APulsadorAceptarAntes = APulsadorAceptarAhora;
  APulsadorAceptarAhora = digitalRead(2);
  BPulsadorVerticalAntes = BPulsadorVerticalAhora;
  BPulsadorVerticalAhora = digitalRead(11);  
  BPulsadorHorizontalAntes = BPulsadorHorizontalAhora;
  BPulsadorHorizontalAhora = digitalRead(12);
  BPulsadorAceptarAntes = BPulsadorAceptarAhora;
  BPulsadorAceptarAhora = digitalRead(13);
  delay(100);
  switch(Estado) {
    case EstadoInicio:
    lcA.clearDisplay(0);
    lcB.clearDisplay(0);
    Abattleshipv = 240;
    Abattleshiph = 0;
    Acruiserv = 3;
    Acruiserh = 224;
    Adestroyerv = 3;
    Adestroyerh = 192;
    Atorpedov = 0;
    Atorpedoh = 0;
    Ahundidos = 0;
    ArrayAtorpv[0]=4;ArrayAtorpv[1]=4;ArrayAtorpv[2]=4;ArrayAtorpv[3]=4;ArrayAtorpv[4]=4;ArrayAtorpv[5]=4;ArrayAtorpv[6]=4;ArrayAtorpv[7]=4;ArrayAtorpv[8]=4;ArrayAtorpv[9]=4;ArrayAtorpv[10]=4;ArrayAtorpv[11]=4;ArrayAtorpv[12]=4;ArrayAtorpv[13]=4;ArrayAtorpv[14]=4;ArrayAtorpv[15]=4;
    ArrayAtorph[0]=0;ArrayAtorph[1]=0;ArrayAtorph[2]=0;ArrayAtorph[3]=0;ArrayAtorph[4]=0;ArrayAtorph[5]=0;ArrayAtorph[6]=0;ArrayAtorph[7]=0;ArrayAtorph[8]=0;ArrayAtorph[9]=0;ArrayAtorph[10]=0;ArrayAtorph[11]=0;ArrayAtorph[12]=0;ArrayAtorph[13]=0;ArrayAtorph[14]=0;ArrayAtorph[15]=0;
    Asunk[0]=false;Asunk[1]=false;Asunk[2]=false;
    Bbattleshipv = 240;
    Bbattleshiph = 0;
    Bcruiserv = 3;
    Bcruiserh = 224;
    Bdestroyerv = 3;
    Bdestroyerh = 192;
    Btorpedov = 0;
    Btorpedoh = 0;
    Bhundidos = 0;
    ArrayBtorpv[0]=4;ArrayBtorpv[1]=4;ArrayBtorpv[2]=4;ArrayBtorpv[3]=4;ArrayBtorpv[4]=4;ArrayBtorpv[5]=4;ArrayBtorpv[6]=4;ArrayBtorpv[7]=4;ArrayBtorpv[8]=4;ArrayBtorpv[9]=4;ArrayBtorpv[10]=4;ArrayBtorpv[11]=4;ArrayBtorpv[12]=4;ArrayBtorpv[13]=4;ArrayBtorpv[14]=4;ArrayBtorpv[15]=4;
    ArrayBtorph[0]=0;ArrayBtorph[1]=0;ArrayBtorph[2]=0;ArrayBtorph[3]=0;ArrayBtorph[4]=0;ArrayBtorph[5]=0;ArrayBtorph[6]=0;ArrayBtorph[7]=0;ArrayBtorph[8]=0;ArrayBtorph[9]=0;ArrayBtorph[10]=0;ArrayBtorph[11]=0;ArrayBtorph[12]=0;ArrayBtorph[13]=0;ArrayBtorph[14]=0;ArrayBtorph[15]=0;
    Bsunk[0]=false;Bsunk[1]=false;Bsunk[2]=false;
    if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW)) {
      Estado = EstadoAAcorazado;
    }
    break;
    case EstadoAAcorazado:
    lcA.setRow(0,Abattleshiph,Abattleshipv);
    if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (Abattleshiph<7)) {
      Abattleshiph = Abattleshiph+1;
      lcA.setRow(0,Abattleshiph-1,0);
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (Abattleshiph==7)) {
      Abattleshiph = 0;
      lcA.setRow(0,7,0);
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph>2)) {
      Estado = EstadoACrucero;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph==0)) {
      Acruiserh = 112;
      Estado = EstadoACrucero;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph==1)) {
      Acruiserh = 56;
      Estado = EstadoACrucero;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph==2)) {
      Acruiserh = 28;
      Estado = EstadoACrucero;
      }
    break;
    case EstadoACrucero:
    lcA.setColumn(0,Acruiserv,Acruiserh);
    lcA.setRow(0,Abattleshiph,Abattleshipv);
    if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (Acruiserv>0)) {
      Acruiserv = Acruiserv-1;
      lcA.setColumn(0,Acruiserv+1,0);
      }
    else if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (Acruiserv==0)) {
      Acruiserv = 3;
      lcA.setColumn(0,0,0);
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Acruiserh==224 && Abattleshiph!=3) || (Acruiserh==112 && Abattleshiph!=4) || (Acruiserh==56 && Abattleshiph!=5) || (Acruiserh==28 && Abattleshiph!=6) || (Acruiserh==14 && Abattleshiph!=7))) {//no está en el siguiente
      Acruiserh = Acruiserh/2;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Acruiserh==224 && Abattleshiph==3) || (Acruiserh==112 && Abattleshiph==4))) {//está en el siguiente
      Acruiserh = Acruiserh/16;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Acruiserh==56 && Abattleshiph==5) || (Acruiserh==28 && Abattleshiph==6) || (Acruiserh==14 && Abattleshiph==7) || (Acruiserh==7 && Abattleshiph>2))) {//está en el siguiente
      Acruiserh = 224;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (Acruiserh==7 && Abattleshiph==0)) {
      Acruiserh = 112;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (Acruiserh==7 && Abattleshiph==1)) {
      Acruiserh = 56;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (Acruiserh==7 && Abattleshiph==2)) {
      Acruiserh = 28;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph>1) && ((Acruiserv!=3) || (Acruiserv==3 && Acruiserh<112))) {
      Estado = EstadoADestructor;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph==0) && ((Acruiserv!=3) || (Acruiserv==3 && Acruiserh<56))) {
      Adestroyerh = 96;
      Estado = EstadoADestructor;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph==0) && (Acruiserv==3) && (Acruiserh>28)) {
      Adestroyerh = 96;
      Adestroyerv = 2;
      Estado = EstadoADestructor;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph==1) && ((Acruiserv!=3) || (Acruiserv==3 && Acruiserh<28))) {
      Adestroyerh = 48;
      Estado = EstadoADestructor;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph==1) && (Acruiserv==3) && (Acruiserh>14)) {
      Adestroyerh = 48;
      Adestroyerv = 2;
      Estado = EstadoADestructor;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (Abattleshiph>1) && (Acruiserv==3) && (Acruiserh>56)) {
      Adestroyerv = 2;
      Estado = EstadoADestructor;
      }
    break;
    case EstadoADestructor:
    lcA.setColumn(0,Acruiserv,Acruiserh);
    lcA.setRow(0,Abattleshiph,Abattleshipv);
    lcA.setColumn(0,Adestroyerv,Adestroyerh);
    if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (Adestroyerv!=0) && ((Acruiserv==Adestroyerv-1 && ((Adestroyerh==192 && Acruiserh<112) || (Adestroyerh==96 && Acruiserh<56) || (Adestroyerh==48 && Acruiserh<28) || (Adestroyerh==24 && (Acruiserh==224 || Acruiserh==7)) || (Adestroyerh==12 && Acruiserh>56) || (Adestroyerh==6 && Acruiserh>28) || (Adestroyerh==3 && Acruiserh>14))) || (Acruiserv!=Adestroyerv-1))) {
      Adestroyerv = Adestroyerv-1;
      lcA.setColumn(0,Adestroyerv+1,0);
      }
    else if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (Adestroyerv>1) && (Acruiserv==Adestroyerv-1 && ((Adestroyerh==192 && Acruiserh>56) || (Adestroyerh==96 && Acruiserh>28) || (Adestroyerh==48 && Acruiserh>14) || (Adestroyerh==24 && (Acruiserh!=224 || Acruiserh!=7)) || (Adestroyerh==12 && Acruiserh<112) || (Adestroyerh==6 && Acruiserh<56) || (Adestroyerh==3 && Acruiserh<28)))) {
      Adestroyerv = Adestroyerv-2;
      lcA.setColumn(0,Adestroyerv+2,0);
      }
    else if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (((Adestroyerv==1) && (Acruiserv==0 && ((Adestroyerh==192 && Acruiserh>56) || (Adestroyerh==96 && Acruiserh>28) || (Adestroyerh==48 && Acruiserh>14) || (Adestroyerh==24 && (Acruiserh!=224 || Acruiserh!=7)) || (Adestroyerh==12 && Acruiserh<112) || (Adestroyerh==6 && Acruiserh<56) || (Adestroyerh==3 && Acruiserh<28)))) || (Adestroyerv==0) && ((Acruiserv==3 && ((Adestroyerh==192 && Acruiserh<112) || (Adestroyerh==96 && Acruiserh<56) || (Adestroyerh==48 && Acruiserh<28) || (Adestroyerh==24 && (Acruiserh==224 || Acruiserh==7)) || (Adestroyerh==12 && Acruiserh>56) || (Adestroyerh==6 && Acruiserh>28) || (Adestroyerh==3 && Acruiserh>14))) || (Acruiserv!=3)))) {      
      lcA.setColumn(0,Adestroyerv,0);
      Adestroyerv = 3;
      }
    else if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (Adestroyerv==0) && (Acruiserv==3 && ((Adestroyerh==192 && Acruiserh>56) || (Adestroyerh==96 && Acruiserh>28) || (Adestroyerh==48 && Acruiserh>14) || (Adestroyerh==24 && (Acruiserh!=224 || Acruiserh!=7)) || (Adestroyerh==12 && Acruiserh<112) || (Adestroyerh==6 && Acruiserh<56) || (Adestroyerh==3 && Acruiserh<28)))) {      
      lcA.setColumn(0,Adestroyerv,0);
      Adestroyerv = 2;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==192 && Abattleshiph!=2 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh!=56))) || (Adestroyerh==96 && Abattleshiph!=3 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh!=28))) || (Adestroyerh==48 && Abattleshiph!=4 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh!=14))) || (Adestroyerh==24 && Abattleshiph!=5 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh!=7))) || (Adestroyerh==12 && Abattleshiph!=6) || (Adestroyerh==6 && Abattleshiph!=7))) {//no está ninguno
      Adestroyerh = Adestroyerh/2;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==192 && Abattleshiph==2 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh==7))) || (Adestroyerh==96 && Abattleshiph==3 && Acruiserv!=Adestroyerv) || (Adestroyerh==48 && Abattleshiph==4 && Acruiserv!=Adestroyerv) || (Adestroyerh==24 && Abattleshiph==5))) {//está el acorazado
      Adestroyerh = Adestroyerh/8;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==192 && Abattleshiph==7 && Acruiserv==Adestroyerv && Acruiserh==56) || (Adestroyerh==96 && Abattleshiph==0 && Acruiserv==Adestroyerv && Acruiserh==28))) {//está crucero
      Adestroyerh = Adestroyerh/32;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==192 && Abattleshiph==2 && Acruiserv==Adestroyerv && Acruiserh==28) || (Adestroyerh==96 && Abattleshiph==5 && Acruiserv==Adestroyerv && Acruiserh==56))) {//están ambos
      Adestroyerh = 3;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==3 && Abattleshiph>1 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh<112))) || (Adestroyerh==6 && Abattleshiph==7 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh==56))) || (Adestroyerh==12 && Abattleshiph==6 && Acruiserv!=Adestroyerv) || (Adestroyerh==24 && Abattleshiph==2 && Acruiserv==Adestroyerv && Acruiserh==7) ||(Adestroyerh==48 && Abattleshiph>1 && Acruiserv==Adestroyerv) ||(Adestroyerh==96 && Abattleshiph!=0 && Acruiserv==Adestroyerv))) {
      Adestroyerh = 192;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==3 && Abattleshiph==0 && (Acruiserv!=Adestroyerv || (Acruiserv==Adestroyerv && Acruiserh==28))) || (Adestroyerh==24 && Abattleshiph==0 && Acruiserv==Adestroyerv && Acruiserh==7))) {
      Adestroyerh = 96;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (Adestroyerh==3 && Abattleshiph==1 && Acruiserv!=Adestroyerv)) {
      Adestroyerh = 48;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==3 && Abattleshiph==5 && Acruiserv==Adestroyerv && Acruiserh==224) || (Adestroyerh==6 && Abattleshiph==7 && Acruiserv==Adestroyerv && Acruiserh==224) || (Adestroyerh==12 && Abattleshiph==6 && Acruiserv==Adestroyerv && Acruiserh==224))) {
      Adestroyerh = 24;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && ((Adestroyerh==3 && Abattleshiph<4 && Acruiserv==Adestroyerv && Acruiserh>56) || (Adestroyerh==6 && Abattleshiph==7 && Acruiserv==Adestroyerv && Acruiserh==224) || (Adestroyerh==12 && Abattleshiph==6 && Acruiserv==Adestroyerv && Acruiserh==224))) {
      Adestroyerh = 12;
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && Adestroyerh==3 && Abattleshiph<5 && Acruiserv==Adestroyerv && Acruiserh>28) {
      Adestroyerh = 6;
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW)) {
      if (Acruiserv==Adestroyerv) {lcA.setColumn(0,Acruiserv,Acruiserh+Adestroyerh);}
      lcA.setRow(0,Abattleshiph,Abattleshipv);
      Estado = EstadoBAcorazado;
      }
    break;
    case EstadoBAcorazado:
    lcB.setRow(0,Bbattleshiph,Bbattleshipv);
    if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (Bbattleshiph<7)) {
      Bbattleshiph = Bbattleshiph+1;
      lcB.setRow(0,Bbattleshiph-1,0);
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (Bbattleshiph==7)) {
      Bbattleshiph = 0;
      lcB.setRow(0,7,0);
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph>2)) {
      Estado = EstadoBCrucero;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph==0)) {
      Bcruiserh = 112;
      Estado = EstadoBCrucero;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph==1)) {
      Bcruiserh = 56;
      Estado = EstadoBCrucero;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph==2)) {
      Bcruiserh = 28;
      Estado = EstadoBCrucero;
      }
    break;
    case EstadoBCrucero:
    lcB.setColumn(0,Bcruiserv,Bcruiserh);
    lcB.setRow(0,Bbattleshiph,Bbattleshipv);
    if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (Bcruiserv>0)) {
      Bcruiserv = Bcruiserv-1;
      lcB.setColumn(0,Bcruiserv+1,0);
      }
    else if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (Bcruiserv==0)) {
      Bcruiserv = 3;
      lcB.setColumn(0,0,0);
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bcruiserh==224 && Bbattleshiph!=3) || (Bcruiserh==112 && Bbattleshiph!=4) || (Bcruiserh==56 && Bbattleshiph!=5) || (Bcruiserh==28 && Bbattleshiph!=6) || (Bcruiserh==14 && Bbattleshiph!=7))) {//no está en el siguiente
      Bcruiserh = Bcruiserh/2;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bcruiserh==224 && Bbattleshiph==3) || (Bcruiserh==112 && Bbattleshiph==4))) {//está en el siguiente
      Bcruiserh = Bcruiserh/16;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bcruiserh==56 && Bbattleshiph==5) || (Bcruiserh==28 && Bbattleshiph==6) || (Bcruiserh==14 && Bbattleshiph==7) || (Bcruiserh==7 && Bbattleshiph>2))) {//está en el siguiente
      Bcruiserh = 224;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (Bcruiserh==7 && Bbattleshiph==0)) {
      Bcruiserh = 112;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (Bcruiserh==7 && Bbattleshiph==1)) {
      Bcruiserh = 56;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (Bcruiserh==7 && Bbattleshiph==2)) {
      Bcruiserh = 28;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph>1) && ((Bcruiserv!=3) || (Bcruiserv==3 && Bcruiserh<112))) {
      Estado = EstadoBDestructor;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph==0) && ((Bcruiserv!=3) || (Bcruiserv==3 && Bcruiserh<56))) {
      Bdestroyerh = 96;
      Estado = EstadoBDestructor;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph==0) && (Bcruiserv==3) && (Bcruiserh>28)) {
      Bdestroyerh = 96;
      Bdestroyerv = 2;
      Estado = EstadoBDestructor;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph==1) && ((Bcruiserv!=3) || (Bcruiserv==3 && Bcruiserh<28))) {
      Bdestroyerh = 48;
      Estado = EstadoBDestructor;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph==1) && (Bcruiserv==3) && (Bcruiserh>14)) {
      Bdestroyerh = 48;
      Bdestroyerv = 2;
      Estado = EstadoBDestructor;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (Bbattleshiph>1) && (Bcruiserv==3) && (Bcruiserh>56)) {
      Bdestroyerv = 2;
      Estado = EstadoBDestructor;
      }
    break;
    case EstadoBDestructor:
    lcB.setColumn(0,Bcruiserv,Bcruiserh);
    lcB.setRow(0,Bbattleshiph,Bbattleshipv);
    lcB.setColumn(0,Bdestroyerv,Bdestroyerh);
    if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (Bdestroyerv!=0) && ((Bcruiserv==Bdestroyerv-1 && ((Bdestroyerh==192 && Bcruiserh<112) || (Bdestroyerh==96 && Bcruiserh<56) || (Bdestroyerh==48 && Bcruiserh<28) || (Bdestroyerh==24 && (Bcruiserh==224 || Bcruiserh==7)) || (Bdestroyerh==12 && Bcruiserh>56) || (Bdestroyerh==6 && Bcruiserh>28) || (Bdestroyerh==3 && Bcruiserh>14))) || (Bcruiserv!=Bdestroyerv-1))) {
      Bdestroyerv = Bdestroyerv-1;
      lcB.setColumn(0,Bdestroyerv+1,0);
      }
    else if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (Bdestroyerv>1) && (Bcruiserv==Bdestroyerv-1 && ((Bdestroyerh==192 && Bcruiserh>56) || (Bdestroyerh==96 && Bcruiserh>28) || (Bdestroyerh==48 && Bcruiserh>14) || (Bdestroyerh==24 && (Bcruiserh!=224 || Bcruiserh!=7)) || (Bdestroyerh==12 && Bcruiserh<112) || (Bdestroyerh==6 && Bcruiserh<56) || (Bdestroyerh==3 && Bcruiserh<28)))) {
      Bdestroyerv = Bdestroyerv-2;
      lcB.setColumn(0,Bdestroyerv+2,0);
      }
    else if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (((Bdestroyerv==1) && (Bcruiserv==0 && ((Bdestroyerh==192 && Bcruiserh>56) || (Bdestroyerh==96 && Bcruiserh>28) || (Bdestroyerh==48 && Bcruiserh>14) || (Bdestroyerh==24 && (Bcruiserh!=224 || Bcruiserh!=7)) || (Bdestroyerh==12 && Bcruiserh<112) || (Bdestroyerh==6 && Bcruiserh<56) || (Bdestroyerh==3 && Bcruiserh<28)))) || (Bdestroyerv==0) && ((Bcruiserv==3 && ((Bdestroyerh==192 && Bcruiserh<112) || (Bdestroyerh==96 && Bcruiserh<56) || (Bdestroyerh==48 && Bcruiserh<28) || (Bdestroyerh==24 && (Bcruiserh==224 || Bcruiserh==7)) || (Bdestroyerh==12 && Bcruiserh>56) || (Bdestroyerh==6 && Bcruiserh>28) || (Bdestroyerh==3 && Bcruiserh>14))) || (Bcruiserv!=3)))) {      
      lcB.setColumn(0,Bdestroyerv,0);
      Bdestroyerv = 3;
      }
    else if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (Bdestroyerv==0) && (Bcruiserv==3 && ((Bdestroyerh==192 && Bcruiserh>56) || (Bdestroyerh==96 && Bcruiserh>28) || (Bdestroyerh==48 && Bcruiserh>14) || (Bdestroyerh==24 && (Bcruiserh!=224 || Bcruiserh!=7)) || (Bdestroyerh==12 && Bcruiserh<112) || (Bdestroyerh==6 && Bcruiserh<56) || (Bdestroyerh==3 && Bcruiserh<28)))) {      
      lcB.setColumn(0,Bdestroyerv,0);
      Bdestroyerv = 2;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==192 && Bbattleshiph!=2 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh!=56))) || (Bdestroyerh==96 && Bbattleshiph!=3 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh!=28))) || (Bdestroyerh==48 && Bbattleshiph!=4 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh!=14))) || (Bdestroyerh==24 && Bbattleshiph!=5 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh!=7))) || (Bdestroyerh==12 && Bbattleshiph!=6) || (Bdestroyerh==6 && Bbattleshiph!=7))) {//no está ninguno
      Bdestroyerh = Bdestroyerh/2;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==192 && Bbattleshiph==2 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh==7))) || (Bdestroyerh==96 && Bbattleshiph==3 && Bcruiserv!=Bdestroyerv) || (Bdestroyerh==48 && Bbattleshiph==4 && Bcruiserv!=Bdestroyerv) || (Bdestroyerh==24 && Bbattleshiph==5))) {//está el acorazado
      Bdestroyerh = Bdestroyerh/8;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==192 && Bbattleshiph==7 && Bcruiserv==Bdestroyerv && Bcruiserh==56) || (Bdestroyerh==96 && Bbattleshiph==0 && Bcruiserv==Bdestroyerv && Bcruiserh==28))) {//está crucero
      Bdestroyerh = Bdestroyerh/32;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==192 && Bbattleshiph==2 && Bcruiserv==Bdestroyerv && Bcruiserh==28) || (Bdestroyerh==96 && Bbattleshiph==5 && Bcruiserv==Bdestroyerv && Bcruiserh==56))) {//están ambos
      Bdestroyerh = 3;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==3 && Bbattleshiph>1 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh<112))) || (Bdestroyerh==6 && Bbattleshiph==7 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh==56))) || (Bdestroyerh==12 && Bbattleshiph==6 && Bcruiserv!=Bdestroyerv) || (Bdestroyerh==24 && Bbattleshiph==2 && Bcruiserv==Bdestroyerv && Bcruiserh==7) ||(Bdestroyerh==48 && Bbattleshiph>1 && Bcruiserv==Bdestroyerv) ||(Bdestroyerh==96 && Bbattleshiph!=0 && Bcruiserv==Bdestroyerv))) {
      Bdestroyerh = 192;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==3 && Bbattleshiph==0 && (Bcruiserv!=Bdestroyerv || (Bcruiserv==Bdestroyerv && Bcruiserh==28))) || (Bdestroyerh==24 && Bbattleshiph==0 && Bcruiserv==Bdestroyerv && Bcruiserh==7))) {
      Bdestroyerh = 96;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (Bdestroyerh==3 && Bbattleshiph==1 && Bcruiserv!=Bdestroyerv)) {
      Bdestroyerh = 48;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==3 && Bbattleshiph==5 && Bcruiserv==Bdestroyerv && Bcruiserh==224) || (Bdestroyerh==6 && Bbattleshiph==7 && Bcruiserv==Bdestroyerv && Bcruiserh==224) || (Bdestroyerh==12 && Bbattleshiph==6 && Bcruiserv==Bdestroyerv && Bcruiserh==224))) {
      Bdestroyerh = 24;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && ((Bdestroyerh==3 && Bbattleshiph<4 && Bcruiserv==Bdestroyerv && Bcruiserh>56) || (Bdestroyerh==6 && Bbattleshiph==7 && Bcruiserv==Bdestroyerv && Bcruiserh==224) || (Bdestroyerh==12 && Bbattleshiph==6 && Bcruiserv==Bdestroyerv && Bcruiserh==224))) {
      Bdestroyerh = 12;
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && Bdestroyerh==3 && Bbattleshiph<5 && Bcruiserv==Bdestroyerv && Bcruiserh>28) {
      Bdestroyerh = 6;
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW)) {
      if (Bcruiserv==Bdestroyerv) {lcB.setColumn(0,Bcruiserv,Bcruiserh+Bdestroyerh);}
      lcB.setRow(0,Bbattleshiph,Bbattleshipv);
      Estado = EstadoADisparo;
      }
    break;
    case EstadoADisparo:    
    if (Atorpedoh == 0 && Atorpedov == 0) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);}
    else if (Atorpedoh == 1 && Atorpedov == 1) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);}
    else if (Atorpedoh == 2 && Atorpedov == 2) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);}
    else if (Atorpedoh == 3 && Atorpedov == 3) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);}
    else if (Atorpedoh == 4 && Atorpedov == 4) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);}
    else if (Atorpedoh == 5 && Atorpedov == 5) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);}
    else if (Atorpedoh == 6 && Atorpedov == 6) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);}
    else if (Atorpedoh == 7 && Atorpedov == 7) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);}
    else if (Atorpedoh == 8 && Atorpedov == 8) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);}
    else if (Atorpedoh == 9 && Atorpedov == 9) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-9],ArrayAtorpv[Atorpedov-9],true);}
    else if (Atorpedoh == 10 && Atorpedov == 10) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-9],ArrayAtorpv[Atorpedov-9],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-10],ArrayAtorpv[Atorpedov-10],true);}
    else if (Atorpedoh == 11 && Atorpedov == 11) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-9],ArrayAtorpv[Atorpedov-9],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-10],ArrayAtorpv[Atorpedov-10],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-11],ArrayAtorpv[Atorpedov-11],true);}
    else if (Atorpedoh == 12 && Atorpedov == 12) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-9],ArrayAtorpv[Atorpedov-9],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-10],ArrayAtorpv[Atorpedov-10],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-11],ArrayAtorpv[Atorpedov-11],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-12],ArrayAtorpv[Atorpedov-12],true);}
    else if (Atorpedoh == 13 && Atorpedov == 13) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-9],ArrayAtorpv[Atorpedov-9],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-10],ArrayAtorpv[Atorpedov-10],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-11],ArrayAtorpv[Atorpedov-11],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-12],ArrayAtorpv[Atorpedov-12],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-13],ArrayAtorpv[Atorpedov-13],true);}
    else if (Atorpedoh == 14 && Atorpedov == 14) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-9],ArrayAtorpv[Atorpedov-9],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-10],ArrayAtorpv[Atorpedov-10],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-11],ArrayAtorpv[Atorpedov-11],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-12],ArrayAtorpv[Atorpedov-12],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-13],ArrayAtorpv[Atorpedov-13],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-14],ArrayAtorpv[Atorpedov-14],true);}
    else if (Atorpedoh == 15 && Atorpedov == 15) {lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-1],ArrayAtorpv[Atorpedov-1],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-2],ArrayAtorpv[Atorpedov-2],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-3],ArrayAtorpv[Atorpedov-3],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-4],ArrayAtorpv[Atorpedov-4],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-5],ArrayAtorpv[Atorpedov-5],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-6],ArrayAtorpv[Atorpedov-6],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-7],ArrayAtorpv[Atorpedov-7],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-8],ArrayAtorpv[Atorpedov-8],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-9],ArrayAtorpv[Atorpedov-9],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-10],ArrayAtorpv[Atorpedov-10],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-11],ArrayAtorpv[Atorpedov-11],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-12],ArrayAtorpv[Atorpedov-12],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-13],ArrayAtorpv[Atorpedov-13],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-14],ArrayAtorpv[Atorpedov-14],true);lcA.setLed(0,ArrayAtorph[Atorpedoh-15],ArrayAtorpv[Atorpedov-15],true);}
    if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (ArrayAtorpv[Atorpedov] < 7)) {
      ArrayAtorpv[Atorpedov] = ArrayAtorpv[Atorpedov]+1;
      lcA.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-1,false);
      }
    else if ((APulsadorVerticalAntes == HIGH) && (APulsadorVerticalAhora == LOW) && (ArrayAtorpv[Atorpedov] == 7)) {
      ArrayAtorpv[Atorpedov] = 4;
      lcA.setLed(0,ArrayAtorph[Atorpedoh],7,false);
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (ArrayAtorph[Atorpedoh] < 7)) {
      ArrayAtorph[Atorpedoh] = ArrayAtorph[Atorpedoh]+1;
      lcA.setLed(0,ArrayAtorph[Atorpedoh]-1,ArrayAtorpv[Atorpedov],false);
      }
    else if ((APulsadorHorizontalAntes == HIGH) && (APulsadorHorizontalAhora == LOW) && (ArrayAtorph[Atorpedoh] == 7)) {
      ArrayAtorph[Atorpedoh] = 0;
      lcA.setLed(0,7,ArrayAtorpv[Atorpedov],false);
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (ArrayAtorph[Atorpedoh] == Bbattleshiph)) {
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setRow(0,Bbattleshiph,0);
      Bhundidos = Bhundidos+1;
      Bsunk[0] = true;
      if (((Atorpedoh == 15) && (Atorpedov == 15)) || (Bsunk[1] == true && Bsunk[2] == true)) {Estado = EstadoFin;}
      else {Atorpedoh = Atorpedoh+1;Atorpedov = Atorpedov+1;Estado = EstadoBDisparo;}
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (ArrayAtorpv[Atorpedov] == Bcruiserv+4) && ((ArrayAtorph[Atorpedoh] == 0 && Bcruiserh == 224) || (ArrayAtorph[Atorpedoh] == 1 && Bcruiserh > 56) || (ArrayAtorph[Atorpedoh] == 2 && Bcruiserh > 28) || (ArrayAtorph[Atorpedoh] == 3 && Bcruiserh > 14 && Bcruiserh < 224) || (ArrayAtorph[Atorpedoh] == 4 && Bcruiserh > 7 && Bcruiserh < 112) || (ArrayAtorph[Atorpedoh] == 5 && Bcruiserh < 56) || (ArrayAtorph[Atorpedoh] == 6 && Bcruiserh < 28) || (ArrayAtorph[Atorpedoh] == 7 && Bcruiserh == 7))) {
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setColumn(0,Bcruiserv,0);
      Bhundidos = Bhundidos+1;
      Bsunk[1] = true;
      if (Bcruiserv==Bdestroyerv && Bsunk[2] == false) {lcB.setColumn(0,Bdestroyerv,Bdestroyerh);}
      if (Bsunk[0] == false) {lcB.setRow(0,Bbattleshiph,Bbattleshipv);}
      if (((Atorpedoh == 15) && (Atorpedov == 15)) || (Bsunk[0] == true && Bsunk[2] == true)) {Estado = EstadoFin;}
      else {Atorpedoh = Atorpedoh+1;Atorpedov = Atorpedov+1;Estado = EstadoBDisparo;}
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW) && (ArrayAtorpv[Atorpedov] == Bdestroyerv+4) && ((ArrayAtorph[Atorpedoh] == 0 && Bdestroyerh == 192) || (ArrayAtorph[Atorpedoh] == 1 && Bdestroyerh > 48) || (ArrayAtorph[Atorpedoh] == 2 && Bdestroyerh > 24 && Bdestroyerh < 192) || (ArrayAtorph[Atorpedoh] == 3 && Bdestroyerh > 12 && Bdestroyerh < 96) || (ArrayAtorph[Atorpedoh] == 4 && Bdestroyerh > 6 && Bdestroyerh < 48) || (ArrayAtorph[Atorpedoh] == 5 && Bdestroyerh > 3 && Bdestroyerh < 24) || (ArrayAtorph[Atorpedoh] == 6 && Bdestroyerh < 12) || (ArrayAtorph[Atorpedoh] == 7 && Bdestroyerh == 3))) {
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setColumn(0,Bdestroyerv,0);
      Bhundidos = Bhundidos+1;
      Bsunk[2] = true;
      if (Bcruiserv==Bdestroyerv && Bsunk[1] == false) {lcB.setColumn(0,Bcruiserv,Bcruiserh);}
      if (Bsunk[0] == false) {lcB.setRow(0,Bbattleshiph,Bbattleshipv);}
      if (((Atorpedoh == 15) && (Atorpedov == 15)) || (Bsunk[0] == true && Bsunk[1] == true)) {Estado = EstadoFin;}
      else {Atorpedoh = Atorpedoh+1;Atorpedov = Atorpedov+1;Estado = EstadoBDisparo;}
      }
    else if ((APulsadorAceptarAntes == HIGH) && (APulsadorAceptarAhora == LOW)) {
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,true);delay(500);
      lcB.setLed(0,ArrayAtorph[Atorpedoh],ArrayAtorpv[Atorpedov]-4,false);delay(500);
      if ((Atorpedoh == 15) && (Atorpedov == 15)) {Estado = EstadoBDisparo;}
      else {Atorpedoh = Atorpedoh+1;Atorpedov = Atorpedov+1;Estado = EstadoBDisparo;}
      }
    break;
    case EstadoBDisparo:    
    if (Btorpedoh == 0 && Btorpedov == 0) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);}
    else if (Btorpedoh == 1 && Btorpedov == 1) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);}
    else if (Btorpedoh == 2 && Btorpedov == 2) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);}
    else if (Btorpedoh == 3 && Btorpedov == 3) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);}
    else if (Btorpedoh == 4 && Btorpedov == 4) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);}
    else if (Btorpedoh == 5 && Btorpedov == 5) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);}
    else if (Btorpedoh == 6 && Btorpedov == 6) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);}
    else if (Btorpedoh == 7 && Btorpedov == 7) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);}
    else if (Btorpedoh == 8 && Btorpedov == 8) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);}
    else if (Btorpedoh == 9 && Btorpedov == 9) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-9],ArrayBtorpv[Btorpedov-9],true);}
    else if (Btorpedoh == 10 && Btorpedov == 10) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-9],ArrayBtorpv[Btorpedov-9],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-10],ArrayBtorpv[Btorpedov-10],true);}
    else if (Btorpedoh == 11 && Btorpedov == 11) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-9],ArrayBtorpv[Btorpedov-9],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-10],ArrayBtorpv[Btorpedov-10],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-11],ArrayBtorpv[Btorpedov-11],true);}
    else if (Btorpedoh == 12 && Btorpedov == 12) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-9],ArrayBtorpv[Btorpedov-9],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-10],ArrayBtorpv[Btorpedov-10],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-11],ArrayBtorpv[Btorpedov-11],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-12],ArrayBtorpv[Btorpedov-12],true);}
    else if (Btorpedoh == 13 && Btorpedov == 13) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-9],ArrayBtorpv[Btorpedov-9],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-10],ArrayBtorpv[Btorpedov-10],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-11],ArrayBtorpv[Btorpedov-11],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-12],ArrayBtorpv[Btorpedov-12],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-13],ArrayBtorpv[Btorpedov-13],true);}
    else if (Btorpedoh == 14 && Btorpedov == 14) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-9],ArrayBtorpv[Btorpedov-9],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-10],ArrayBtorpv[Btorpedov-10],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-11],ArrayBtorpv[Btorpedov-11],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-12],ArrayBtorpv[Btorpedov-12],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-13],ArrayBtorpv[Btorpedov-13],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-14],ArrayBtorpv[Btorpedov-14],true);}
    else if (Btorpedoh == 15 && Btorpedov == 15) {lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-1],ArrayBtorpv[Btorpedov-1],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-2],ArrayBtorpv[Btorpedov-2],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-3],ArrayBtorpv[Btorpedov-3],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-4],ArrayBtorpv[Btorpedov-4],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-5],ArrayBtorpv[Btorpedov-5],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-6],ArrayBtorpv[Btorpedov-6],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-7],ArrayBtorpv[Btorpedov-7],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-8],ArrayBtorpv[Btorpedov-8],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-9],ArrayBtorpv[Btorpedov-9],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-10],ArrayBtorpv[Btorpedov-10],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-11],ArrayBtorpv[Btorpedov-11],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-12],ArrayBtorpv[Btorpedov-12],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-13],ArrayBtorpv[Btorpedov-13],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-14],ArrayBtorpv[Btorpedov-14],true);lcB.setLed(0,ArrayBtorph[Btorpedoh-15],ArrayBtorpv[Btorpedov-15],true);}
    if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (ArrayBtorpv[Btorpedov] < 7)) {
      ArrayBtorpv[Btorpedov] = ArrayBtorpv[Btorpedov]+1;
      lcB.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-1,false);
      }
    else if ((BPulsadorVerticalAntes == HIGH) && (BPulsadorVerticalAhora == LOW) && (ArrayBtorpv[Btorpedov] == 7)) {
      ArrayBtorpv[Btorpedov] = 4;
      lcB.setLed(0,ArrayBtorph[Btorpedoh],7,false);
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (ArrayBtorph[Btorpedoh] < 7)) {
      ArrayBtorph[Btorpedoh] = ArrayBtorph[Btorpedoh]+1;
      lcB.setLed(0,ArrayBtorph[Btorpedoh]-1,ArrayBtorpv[Btorpedov],false);
      }
    else if ((BPulsadorHorizontalAntes == HIGH) && (BPulsadorHorizontalAhora == LOW) && (ArrayBtorph[Btorpedoh] == 7)) {
      ArrayBtorph[Btorpedoh] = 0;
      lcB.setLed(0,7,ArrayBtorpv[Btorpedov],false);
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (ArrayBtorph[Btorpedoh] == Abattleshiph)) {
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setRow(0,Abattleshiph,0);
      Ahundidos = Ahundidos+1;
      Asunk[0] = true;
      if (((Btorpedoh == 15) && (Btorpedov == 15)) || (Asunk[1] == true && Asunk[2] == true)) {Estado = EstadoFin;}
      else {Btorpedoh = Btorpedoh+1;Btorpedov = Btorpedov+1;Estado = EstadoADisparo;}
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (ArrayBtorpv[Btorpedov] == Acruiserv+4) && ((ArrayBtorph[Btorpedoh] == 0 && Acruiserh == 224) || (ArrayBtorph[Btorpedoh] == 1 && Acruiserh > 56) || (ArrayBtorph[Btorpedoh] == 2 && Acruiserh > 28) || (ArrayBtorph[Btorpedoh] == 3 && Acruiserh > 14 && Acruiserh < 224) || (ArrayBtorph[Btorpedoh] == 4 && Acruiserh > 7 && Acruiserh < 112) || (ArrayBtorph[Btorpedoh] == 5 && Acruiserh < 56) || (ArrayBtorph[Btorpedoh] == 6 && Acruiserh < 28) || (ArrayBtorph[Btorpedoh] == 7 && Acruiserh == 7))) {
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setColumn(0,Acruiserv,0);
      Ahundidos = Ahundidos+1;
      Asunk[1] = true;
      if (Acruiserv==Adestroyerv && Asunk[2] == false) {lcA.setColumn(0,Adestroyerv,Adestroyerh);}
      if (Asunk[0] == false) {lcA.setRow(0,Abattleshiph,Abattleshipv);}
      if (((Btorpedoh == 15) && (Btorpedov == 15)) || (Asunk[0] == true && Asunk[2] == true)) {Estado = EstadoFin;}
      else {Btorpedoh = Btorpedoh+1;Btorpedov = Btorpedov+1;Estado = EstadoADisparo;}
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW) && (ArrayBtorpv[Btorpedov] == Adestroyerv+4) && ((ArrayBtorph[Btorpedoh] == 0 && Adestroyerh == 192) || (ArrayBtorph[Btorpedoh] == 1 && Adestroyerh > 48) || (ArrayBtorph[Btorpedoh] == 2 && Adestroyerh > 24 && Adestroyerh < 192) || (ArrayBtorph[Btorpedoh] == 3 && Adestroyerh > 12 && Adestroyerh < 96) || (ArrayBtorph[Btorpedoh] == 4 && Adestroyerh > 6 && Adestroyerh < 48) || (ArrayBtorph[Btorpedoh] == 5 && Adestroyerh > 3 && Adestroyerh < 24) || (ArrayBtorph[Btorpedoh] == 6 && Adestroyerh < 12) || (ArrayBtorph[Btorpedoh] == 7 && Adestroyerh == 3))) {
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setColumn(0,Adestroyerv,0);
      Ahundidos = Ahundidos+1;
      Asunk[2] = true;
      if (Acruiserv==Adestroyerv && Asunk[1] == false) {lcA.setColumn(0,Acruiserv,Acruiserh);}
      if (Asunk[0] == false) {lcA.setRow(0,Abattleshiph,Abattleshipv);}
      if (((Btorpedoh == 15) && (Btorpedov == 15)) || (Asunk[0] == true && Asunk[1] == true)) {Estado = EstadoFin;}
      else {Btorpedoh = Btorpedoh+1;Btorpedov = Btorpedov+1;Estado = EstadoADisparo;}
      }
    else if ((BPulsadorAceptarAntes == HIGH) && (BPulsadorAceptarAhora == LOW)) {
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,true);delay(500);
      lcA.setLed(0,ArrayBtorph[Btorpedoh],ArrayBtorpv[Btorpedov]-4,false);delay(500);
      if ((Btorpedoh == 15) && (Btorpedov == 15)) {Estado = EstadoFin;}
      else {Btorpedoh = Btorpedoh+1;Btorpedov = Btorpedov+1;Estado = EstadoADisparo;}
      }
    break;
    case EstadoFin:
    lcA.clearDisplay(0);
    lcB.clearDisplay(0);
    if (Ahundidos > Bhundidos) {lcB.setColumn(0,3,24);lcB.setColumn(0,2,36);lcB.setColumn(0,1,66);lcB.setRow(0,0,255);lcB.setRow(0,7,255);lcA.setColumn(0,0,255);lcA.setRow(0,0,255);delay(5000);Estado = EstadoInicio;}//gana B
    else if (Bhundidos > Ahundidos) {lcA.setColumn(0,3,24);lcA.setColumn(0,2,36);lcA.setColumn(0,1,66);lcA.setRow(0,0,255);lcA.setRow(0,7,255);lcB.setColumn(0,0,255);lcB.setRow(0,0,255);delay(5000);Estado = EstadoInicio;}//gana A    
    break;
  }
}
