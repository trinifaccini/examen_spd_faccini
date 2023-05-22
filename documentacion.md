# Documentacion 

## Componentes, conexiones y su funcionalidad

- 1 Display 7 segmentos para informar al usuario el piso en el que se encuentra el montacargas
Este se encuentra conectado a tierra y cada uno de sus segmentos led conectado a un pin de salida digital con una resistencia de 220 Ohms

- 1 led color rojo para informar que el montacargas se encuentra pausado
- 1 led color verde para informar que el montacargas se encuentra subiendo o bajando 
Cada led conectado a tierra desde su cátodo y conectado a un pin de salida digital con una resistencia de 220 Ohms

- 1 push button para pausar el montacargas
  Este boton, al estar configurado como INPUT PULLUP tienen su terminal 2a conectada directamente a tierra y su terminal 1a conectada directamente a un pin, no se usan resistencias. 

- 1 push button para hacer que el montacargas suba
  Este boton esta configurado como PULLDOWN, por lo tanto:
  Su terminal 1a esta conectada directamente al pin
  Su terminal 2a esta conectada a tierra con una resistencia de 10 Ohms
  Su terminal 2b esta conectada directamente a 5 volteos

- 1 push button para hacer que el montacargas baje 
  Este boton esta configurado como PULLUP, por lo tanto:
  Su terminal 1b esta conectada directamente al pin
  Su terminal 2a esta conectada directamente a tierra
  Su terminal 1a esta conectada a 5 volteos con una resisencia de 10 Ohms

## Mecanismo del proyecto

El proyecto se trata de un modelo de montacarga funcional que se usará como una maqueta para un hospital. 

Inicialmente el montacargas se encontrará pausado y en el piso cero (planta baja). Esto el usuario lo podrá saber porque la luz roja estará encendida y el display 7 segmentos, que informa el piso actual del montacargas, mostrará el número cero.

Si el usuario desea subir o bajar el montacargas, deberá tocar el boton correspondiente. Una vez apretado comenzará el movimiento elegido por el usuario. 

Una vez en movimiento la luz verde se encenderá, la luz roja se apagará y el display 7 segmentos irá mostrándo el número de cambio de piso.

Si quisiera parar el movimiento, tanto de subida o de bajada, deberá tocar el boton de pausa y el montacargas detendrá su movimiento, volviendo a encender la luz roja y apagando la luz verde.

Si el montacargas se encuentra en el piso 0 y el usuario decide que quiere bajar, no se verá ningún cambio ya que al encontrarse en el primer piso del edificio, este no puede continuar bajando. 
Lo mismo ocurrirá si se encuentra en el piso 9 y el usuario quiere subir, ya que estaría en el último piso del edificio y no puede seguir subiendo. 

Una vez que el montacargas esté en el primer o ultimo piso, este se pausará ya que no puede continuar el movimiento.

Siempre se informará desde el Monitor Serial el piso en el que se encuentra el montacargas. También se imprimirá el cambio de estado del mismo.

Por ejemplo, si el montacargas estaba pausado y el usuario apreto el botón de subir, se verá el mensaje "COMENZANDO A SUBIR", si luego se apreta el boton de bajar se verá "COMENZANDO A BAJAR" y si se apreta el de pausar "PAUSANDO MONTACARGAS".
Otro ejemplo sería que el montacargas esté subiendo y llegue al ultimo piso, una vez allí se verá el mensaje "PAUSANDO MONTACARGAS". 

Solo se verán estos mensajes cuando haya un cambio de estado, es decir, si el montacargas estaba subiendo y se apreta el boton de subir, no se mostrará ningun mensaje ya que ya se encontraba realizando ese movimiento. 
