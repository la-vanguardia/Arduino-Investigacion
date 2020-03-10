# Proyecto *El Chacras* 🚗

## Integrantes 

* Martin, Santiago
* Gatica, Isaias
* Saez, Lautaro Andres

## Articulos utilizados 🔌

- Microcontrolador: Arduino Mega
- Motores: 24V **datos**
- Reducciones: **datos**
- encoders: opticos

## Tareas 🧾

- [ ] Seleccionar baterias

- [ ] Retroalimentar la velocidad de girod de los 4 motores de forma individual

- [x] Lograr movimiento de los motores de forma independiente

- [ ] Rutina de bloqueo de ruedas

- [ ] Fabricar los acoples para los encoders

## Funcionamiento

El vehiculo cuenta con una retroalimentacion la velocidad de cada motor, esto permite realizar diferentes acciones sobre el vehiculo, permitiendo un mayor control sobre el mismo. Las tareas que permite realizar este sistema de conexion es:

1. Frenar una rueda bloqueada y aumentar el ciclo de trabajo del resto.
2. Controlar de forma optima la velocidad del vehiculo, permitiendo asi fijar una velocidad fija para cada motor independiente
de su estado.
3. Controlar de forma optima su trayectoria.

Otros apartados importantes del funcionamiento son

### Libreria MOTOR

La libreria *MOTOR* permite el control de un motor, incluyendo acciones basicas tales como:

1. Fijar el ciclo de trabajo ( **setDutyCicle** ).
2. Fijar una accion como:
    1. START.
    2. STOP.
3. Perimite seleccionar un sentido de giro ( **setState** )

Estas funcionalidades fueron implementadas pensando en las funciones basicas de un motor.

#### FUNCIONES

Las funciones de esta libreria son:

1. **setDutyCicle**: Permite fijar el ciclo de trabajo de forma porcentual.
2. **setState**: Perimite fijar el estado del motor (adelante o atras).\
3. **setAction**: Setea la accion a realizar (start o stop).
4. **getDutyCicle**: Devuelve el ciclo de trabajo.
5. **start**: Enciende el motor.
6. **stop**: Apaga el motor, poniendo los pines en 0.

### Libreria MOTORS

Esta libreria incluye el control de 4 motores, ubicandolos relativamente en el vehiculo. Esto permite un mayor control y facilidad a la hora de utilizar un motor en particular, permitiendo realizar tareas avanzadas como setear el ciclo de trabajo de 1 motor o de todos, (se esta trabajando para incluir en cambio de **j** ciclos de trabajo), frenar/encender 1 o todos los motores.

#### FUNCIONES

Esta libreria cuenta con:

1. **setAllDutyCicle**: Setea todos los ciclos de trabajo de los motores a un valor.
2. **setAllState**: Setea todos los estados de los motores a uno.
3. **setDutyCicle**: Setea el ciclo de trabajo de 1 motor.
4. **getDutyCicle**: Retorna el ciclo de trabajo de 1 motor.
5. **motorAction**: Ejectuta una accion sobre 1 motor.
6. **setAction**: Ejecuta una accion sobre todos los motores.

### Implementacion de interrupciones para la medicion de velocidad

Se logro implementar la medicion de las velocidad angulares de los motores mediante interrupciones, aunque todavia no fue posible determinar su verocimilitud, el grupo se encuentra en una etapa de diseño de los sistemas que permitan realizar dicha medicion.

Este apartado sigue en desarrollo, siendo uno de los mas complicados debido a diferentes factores tales como:

1. Limitaciones de tiempos de interrupcion de uC.
2. Escases del material necesario para las pruebas.

Actualmente se estudia la posibilidad de implementar esta funcionalidad dentro de las libreria **MOTOR**, permitiendo asi un control automatico de cada motor y facilitando dicho control.


