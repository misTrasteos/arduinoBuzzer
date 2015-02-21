short pinBuzzer = 9; //a este pin conecto el cable rojo del buzzer

/*
  // AMAGO DE CUMPLEAÑOS FELIZ
short longitudMelodia = 14;
char melodia[] = "ddrdfmddrdsf ";
short duracionNota[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //duración de cada nota
*/

short longitudMelodia = 9; // longitud de la melodía a tocar
char melodia[] = "drmfslsD "; //melodía
short duracionNota[] = {2,2,2,2,2,2,2,2,4}; //duración de cada nota


short ritmo = 300;


void tocarTono(short tono,short duracion){
    Serial.println("\t\t\t-- inicio función tocarTono --");

    for(long i=0;i<duracion*1000L;i+=tono*2){
      digitalWrite(pinBuzzer,HIGH);
      delayMicroseconds(tono);
      digitalWrite(pinBuzzer,LOW);
      delayMicroseconds(tono);
    }//for    
    
    Serial.println("\t\t\t-- fin función tocarTono --");
}//tocarTono

void tocarNota(char nota,short duracion){
  Serial.println("\t----- inicio función tocarNota -----");

  short numeroNotas = 8; //el sketch es capaz de tocar 8 notas, del do menor al do mayor
  //char nombres[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' }; //notación inglesa
  char nombres[] = {'d','r','m','f','s','l','s','D'}; //notación latina
  short tonos[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 }; // estos están ya de internet

  // busco a que nota corresponde y la toco
  for(int i=0;i<numeroNotas;i++){
    if(nombres[i]==nota){
      Serial.print("\tEncontrada nota ");Serial.println(nombres[i]);
      tocarTono(tonos[i],duracion);
    }
  }//recorro cada nota
  
  Serial.println("\t----- fin función tocarNota -----");
}//tocarNota


void setup(){
  pinMode(pinBuzzer,OUTPUT); // activo el pin al que he conectado el buzzer como salida
  Serial.begin(9600); // para depurar
}//setup

void loop() {
  Serial.println("---------- Inicio loop ----------");
  
  for(short i=0;i<longitudMelodia;i++){
    Serial.print("La nota número ");Serial.print(i);Serial.print(" es la ");Serial.print(melodia[i]);Serial.print(" y tiene una duración de ");Serial.println(duracionNota[i]);
    
    if(melodia[i] == ' ') // no toco nada
      delay(duracionNota[i] * ritmo);
    else // toco la nota correspondiente
      tocarNota(melodia[i],duracionNota[i] * ritmo);
      
    delay(ritmo/2);
  }//recorro la melodía
  
  Serial.println("---------- Fin loop ----------");
}//loop
