# Sistema de Gestión de Pacientes en Hospital

## Descripción

Este sistema permite a los usuarios gestionar la atención de pacientes en un hospital. Los usuarios pueden ingresar nuevos pacientes, asignar su prioridad, mostrar la lista de espera, ver quien es el siguiente en atender, etc.. Esto esta diseñado para mejorar la eficiencia de atencion poniendo como prioridad las personas que tengan situaciones más criticas.

## Cómo compilar y ejecutar

Dado que el sistema está diseñado para ser accesible y fácil de probar, recomendamos usar Repl.it para una rápida configuración y ejecución. Sigue estos pasos para comenzar:

1.- Visita Repl.it.

2.- Crea una cuenta o inicia sesion.

3.- Una vez en el inicio selecciona  "New Repl" y elige "Import from GitHub".

4.- Pegar este link = [https://github.com/DavidHenriquezz/Gestion_sistema_pacientes](https://github.com/DavidHenriquezz/Gestion_sistema_pacientes)

5.- Repl.it clonara el repositorio y te preparará un entorno de ejecución

6.- Aprete el boton "Run" para que el codigo se ejecute

## Funcionalidades

### Funcionando correctamente:

- Registrar pacientes con sus datos básicos y una prioridad inicial.
- Asignar o modificar la prioridad de los pacientes.
- Ver la lista de espera de pacientes, ordenada por prioridad y hora de registro.
- Atender al siguiente paciente, respetando el orden de prioridad.
- Ver la lista de pacientes según la prioridad seleccionada

### A mejorar:

- Modificar la interfaz para que sea más amigable
- Permitir la modificación de datos del paciente

### Posibles errores:

- Al momento de registrar a un paciente si se ingresa letras en la edad se la salta
- No se puede reasignar 2 veces la prioridad de los pacientes
- Al momento de asignar prioridades si se ingresa una letra distinta a "s o n" la prioridad no será cambiada.
  
## Ejemplo de uso

**Paso 1: Registrar un Nuevo Paciente**

Se comienza registrando un nuevo paciente que acaba de llegar al hospital.
```
========================================
     Sistema de Gestión Hospitalaria
========================================
1) Registrar paciente
2) Asignar prioridad a paciente
3) Mostrar lista de espera
4) Atender al siguiente paciente
5) Mostrar pacientes por prioridad
6) Salir
Ingrese su opción: 1
Registrar nuevo paciente
-------------------------------
Ingrese el nombre del paciente: Juan Leon
Ingrese la edad del paciente: 20
Ingrese el síntoma del paciente: Dolor de estomago
Se registro a las 19:52:40
-------------------------------
```

El sistema regista a "Juan Leon" con una prioridad "Baja" y guarda la hora en la que fue registrado. La prioridad puede ser cambiada posteriormente.

**Paso 2: Asignar Prioridad a un Paciente**

Tras la evaluación del doctor se decide que Juan León debe tener una prioridad alta.

```
========================================
     Sistema de Gestión Hospitalaria
========================================
1) Registrar paciente
2) Asignar prioridad a paciente
3) Mostrar lista de espera
4) Atender al siguiente paciente
5) Mostrar pacientes por prioridad
6) Salir
Ingrese su opción: 2
-------------------------------
Datos del paciente:
Nombre: Juan Leon
Edad: 20
Síntoma: Dolor de estomago
Desea reasignar la prioridad?(s/n)
-------------------------------
```

En esta situacion hay 2 posibles respuesta el "si"(s) o el "no"(n)

si seleccionan "si" verán el siguiente

```
Seleccione que prioridad que le desea asignar:
1) Alta
2) Medio
3) Baja

```
La prioridad se actualizará según el numero que ingrese (1,2,3), siendo estas las prioridades alta, media y baja.

si seleccionan "no" simplemente seguirá al siguiente paciente

para finalmente mostrar un mensaje cuando se termine de recorrer la lista de pacientes

**Paso 3: Ver la Lista de Espera**

El usuario revisa la lista de espera para ver todos los pacientes y sus prioridades.

```
========================================
     Sistema de Gestión Hospitalaria
========================================
1) Registrar paciente
2) Asignar prioridad a paciente
3) Mostrar lista de espera
4) Atender al siguiente paciente
5) Mostrar pacientes por prioridad
6) Salir
Ingrese su opción: 3
-------------------------------
Nombre: Juan Leon - Prioridad: Alta
Fue ingresado a las 19:52:40
-------------------------------
```

La lista muestra a Juan Leon en la parte superior, indicando su prioridad alta y que es la siguiente en línea para recibir atención.

**Paso 4: Atender al Siguiente Paciente**

Juan Leon es el siguiente para ser atendido basándose en su prioridad.

```
-------------------------------
El siguiente paciente es: Juan Leon
Edad: 20
Sintoma: Dolor de estomago
Prioridad: Alta
Fue ingresado a las 19:52:40
-------------------------------
```

El sistema muestra que Juan Leon está siendo atendido y lo elimina de la lista de espera.
