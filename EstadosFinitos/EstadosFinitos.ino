enum State{s1,s2,s3};
enum Input{Unknown,uno,cero};
 
// Variables globales
State currentState;
Input currentInput;
 
// Acciones de los estados y condiciones de transiciones
void state1(){
  if (currentInput == Input::cero)
    changeState(State::s1);
  
  if (currentInput == Input::uno)
    changeState(State::s2);}
 
void state2(){
  if (currentInput == Input::cero)
    changeState(State::s3);
    
  if (currentInput == Input::uno)
    changeState(State::s2);}
 
void state3()
{
  if (currentInput == Input::uno)
    changeState(State::s2);
    
  if (currentInput == Input::cero)
    changeState(State::s1);}
  
void outputled(){digitalWrite(A0, HIGH);Serial.println("s3");}
void outputs1(){digitalWrite(10, LOW);digitalWrite(A0, LOW);Serial.println("s1");}
void outputs2(){digitalWrite(10, LOW);digitalWrite(A0, LOW);Serial.println("s2");}
 
void setup(){
  pinMode(A0,OUTPUT);//LED
  pinMode(3,INPUT);//pulsador 1
  pinMode(2,INPUT);//pulsador 0

  outputs1();
  Serial.begin(9600);
  currentState = s1;}
 
void loop(){
  readInput();
  updateStateMachine();}
 
// Actualiza el estado de la maquina
void updateStateMachine(){
  switch (currentState){
    case s1: state1(); break;
    case s2: state2(); break;
    case s3: state3(); break;}
}
 
// Lee la entrada por puerto serie
void readInput(){
  currentInput = Input::Unknown;
if(digitalRead(3) == HIGH){
  delay(100);
 if(digitalRead(3) == LOW){
  currentInput = Input::uno;Serial.println("1");delay(100);}}

if(digitalRead(2) == HIGH){
  delay(100);
 if(digitalRead(2) == LOW){
  currentInput = Input::cero;Serial.println("0");delay(100);}} 
}
 
// Funcion que cambia el estado y dispara las transiciones
void changeState(int newState)
{
  currentState = newState;
 
  switch (currentState)
  {
    case State::s1: outputs1();   break;
    case State::s2: outputs2();   break;
    case State::s3: outputled();   break;
    default: break;
  }
}
