# DOJO NUMERO UNO - GRUPO F

![Tinkercard](https://github.com/trinifaccini/dojo-uno/blob/main/img/PARCIAL_FACCINI_TRINIDAD_1°D.png)

## Consigna

## Requisitos del proyecto

- 1: Interfaz de usuario
* Deberá haber 3 botones, uno para subir pisos, otro para bajar pisos y otro para detener el montacarga.
* Deberá tener 2 LEDs, uno verde que indicará cuando el montacarga este en movimiento, otro rojo que indique cuando el montacarga esté pausado.
* En el display 7 segmentos deberán informar en tiempo real en qué piso se
encuentra el elevador.
* Se sabe que el tiempo de trayecto entre pisos es de 3 segundos (3000 ms). •
Se deberá informar por monitor serial el piso en el que se encuentra el
montacarga, este en funcionamiento o en pausa.

- 2: Funcionamiento del montacarga
* Implementa un algoritmo que permita que el elevador suba y baje o frene presionando los botones correspondientes.
* Deberán buscar una forma para pausar el montacargas cuando el usuario lo
determine.

- 3: Documentación:
* Deberán presentar un diagrama esquemático del circuito y explicar el funcionamiento aplicado de cada componente.
* Presentar el código fuente del proyecto de Arduino listo para ser implementado.
* Deberán explicar el funcionamiento integral utilizando documentación MarkDown.

## Descripción

## Finalidad del proyecto
Demostrar los conocimientos aprendidos en la materia Sistema de Procesamiento de Datos.

## Función principal

Esta función se encarga de cambiar el estado del sistema del montacargas.

~~~ C++ 

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
~~~

## :robot: Link al proyecto
- [Tinkercard-Trinidad-Faccini](https://www.tinkercad.com/things/9P5PWI00o0g-copy-of-parcial-faccini-trinidad-1d/editel?sharecode=AXw5kHL_Jth6nJx7EqBY9xx2F4ZfyMcmLQTsSouAg4A)