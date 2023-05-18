#define PIN_A 12
#define PIN_B 13
#define PIN_C 7
#define PIN_D 8
#define PIN_E 9
#define PIN_F 11
#define PIN_G 10

#define BOTON_PAUSAR A1
#define BOTON_SUBIR A2
#define BOTON_BAJAR A3

#define LED_ROJO 6
#define LED_VERDE 5

int pausado;
int subiendo;
int bajando;
int estado_sistema;

int piso_actual; 
int tiempo_delay;

// Prototipos de funciones

void CambiarEstadoSistema(int pausa, int sube, int baja, int primer_piso, int ultimo_piso);
void EnciendeApagaLeds(int led_prender, int led_apagar);
void SubirPisos(int ultimo_piso);
void BajarPisos(int primer_piso);
void SubirBajarPisos(int primer_piso, int ultimo_piso); 
void EncenderDisplay7Segmentos(int piso);

void setup()
{
  
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);  
  
  pinMode(PIN_A, OUTPUT);   
  pinMode(PIN_B, OUTPUT);  
  pinMode(PIN_C, OUTPUT);  
  pinMode(PIN_D, OUTPUT);  
  pinMode(PIN_E, OUTPUT);  
  pinMode(PIN_F, OUTPUT);  
  pinMode(PIN_G, OUTPUT);    
  
  pinMode(BOTON_SUBIR, INPUT); // PULLDOWN
  pinMode(BOTON_BAJAR, INPUT); // PULLUP  
  pinMode(BOTON_PAUSAR, INPUT_PULLUP); //INPUT PULLUP
  
  pausado = 0;
  subiendo = 1;
  bajando = -1;
  
  estado_sistema = pausado;
  
  piso_actual = 0;
    
  Serial.begin(9600);
  
  

}

void loop()
{

  int boton_subir;
  boton_subir = digitalRead(BOTON_SUBIR);

  int boton_bajar;
  boton_bajar = digitalRead(BOTON_BAJAR);
  
  int boton_pausar;
  boton_pausar = digitalRead(BOTON_PAUSAR);
  
  Serial.print("PISO ACTUAL: ");    
  Serial.println(piso_actual);
  
  EncenderDisplay7Segmentos(piso_actual);

  CambiarEstadoSistema(boton_pausar, boton_subir, boton_bajar, 0, 9); 
 
  if(estado_sistema == pausado) 
  {
    EnciendeApagaLeds(LED_ROJO, LED_VERDE); 
    tiempo_delay = 1000;
  }
  
  else 
  {
    EnciendeApagaLeds(LED_VERDE, LED_ROJO); 
    SubirBajarPisos(0,9);
    tiempo_delay = 3000;
  }
  
  delay(tiempo_delay);

}


void EnciendeApagaLeds(int led_prender, int led_apagar)
{
  digitalWrite(led_prender, HIGH);
  digitalWrite(led_apagar, LOW);
}


void CambiarEstadoSistema(int pausa, int sube, int baja, int primer_piso, int ultimo_piso){
  
  if (pausa == LOW)
  {
    estado_sistema = pausado;
    Serial.println("PAUSANDO MONTACARGAS");
  }
  
  else if (sube == HIGH && estado_sistema != subiendo && piso_actual < ultimo_piso)
  {
    estado_sistema = subiendo;
    Serial.println("COMENZANDO A SUBIR");
  }
  
  else if (baja == LOW && estado_sistema != bajando && piso_actual > primer_piso)
  {
    estado_sistema = bajando;
    Serial.println("COMENZANDO A BAJAR"); 
  }
  
}
  

void EncenderDisplay7Segmentos(int piso)
{
   switch(piso)
   {
     case 0: 
        digitalWrite(PIN_A, HIGH);   
        digitalWrite(PIN_B, HIGH);  
        digitalWrite(PIN_C, HIGH);  
        digitalWrite(PIN_D, HIGH);
        digitalWrite(PIN_E, HIGH);  
        digitalWrite(PIN_F, HIGH);
        digitalWrite(PIN_G, LOW);
     	break;
     case 1:
     	digitalWrite(PIN_A, LOW);   
     	digitalWrite(PIN_B, HIGH);  
        digitalWrite(PIN_C, HIGH);
        digitalWrite(PIN_D, LOW);
        digitalWrite(PIN_E, LOW);  
        digitalWrite(PIN_F, LOW);        
        digitalWrite(PIN_G, LOW);
        break;
      case 2: 
     	digitalWrite(PIN_A, HIGH);   
        digitalWrite(PIN_B, HIGH);        
     	digitalWrite(PIN_C, LOW);  
        digitalWrite(PIN_D, HIGH);
        digitalWrite(PIN_E, HIGH);  
     	digitalWrite(PIN_F, LOW);  
    	digitalWrite(PIN_G, HIGH);
        break;
      case 3:
     	digitalWrite(PIN_A, HIGH);   
        digitalWrite(PIN_B, HIGH);  
        digitalWrite(PIN_C, HIGH);  
        digitalWrite(PIN_D, HIGH);
     	digitalWrite(PIN_E, LOW);  
     	digitalWrite(PIN_F, LOW);  
    	digitalWrite(PIN_G, HIGH);
     	break;
     case 4:
		digitalWrite(PIN_A, LOW);		
		digitalWrite(PIN_B, HIGH);
     	digitalWrite(PIN_C, HIGH);  
		digitalWrite(PIN_D, LOW);
     	digitalWrite(PIN_E, LOW);	
        digitalWrite(PIN_F, HIGH);        
    	digitalWrite(PIN_G, HIGH);
        break;
     case 5:
        digitalWrite(PIN_A, HIGH);
     	digitalWrite(PIN_B, LOW);   
        digitalWrite(PIN_C, HIGH);  
        digitalWrite(PIN_D, HIGH);
     	digitalWrite(PIN_E, LOW);
        digitalWrite(PIN_F, HIGH);        
    	digitalWrite(PIN_G, HIGH);
     	break;
     case 6:
        digitalWrite(PIN_A, HIGH);
     	digitalWrite(PIN_B, LOW);
        digitalWrite(PIN_C, HIGH);  
        digitalWrite(PIN_D, HIGH);
        digitalWrite(PIN_E, HIGH);  
        digitalWrite(PIN_F, HIGH);        
    	digitalWrite(PIN_G, HIGH);
     	break;
     case 7:
        digitalWrite(PIN_A, HIGH);   
        digitalWrite(PIN_B, HIGH);  
        digitalWrite(PIN_C, HIGH); 
     	digitalWrite(PIN_D, LOW);
        digitalWrite(PIN_E, LOW);  
        digitalWrite(PIN_F, LOW);        
    	digitalWrite(PIN_G, LOW);
        break;
     case 8:
       digitalWrite(PIN_A, HIGH);   
       digitalWrite(PIN_B, HIGH);          
       digitalWrite(PIN_C, HIGH);  
       digitalWrite(PIN_D, HIGH);  
       digitalWrite(PIN_E, HIGH);
       digitalWrite(PIN_F, HIGH);          
       digitalWrite(PIN_G, HIGH);
       break;
     case 9:
       digitalWrite(PIN_A, HIGH);   
       digitalWrite(PIN_B, HIGH);          
       digitalWrite(PIN_C, HIGH);  
       digitalWrite(PIN_D, LOW);  
       digitalWrite(PIN_E, LOW);
       digitalWrite(PIN_F, HIGH);          
       digitalWrite(PIN_G, HIGH);
       break;
    }
  
}

void SubirPisos(int ultimo_piso)
{
  
  if(piso_actual < ultimo_piso)
  {
    piso_actual += 1;
    estado_sistema = subiendo;
    
  }
  
  else
  {
    estado_sistema = pausado;
  }
}


void BajarPisos(int primer_piso)
{
  if(piso_actual > primer_piso)
  {
    piso_actual -= 1;
  }
  
  else
  {
    estado_sistema = pausado;
  }
}


void SubirBajarPisos(int primer_piso, int ultimo_piso)
{
  if(estado_sistema == subiendo)
  {
  	SubirPisos(ultimo_piso);
  }
  
  else if(estado_sistema == bajando)
  {
  	BajarPisos(primer_piso);
  }
}
