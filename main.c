#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct paciente {
  char nombre[101];
  int edad;
  char sintoma[101];
  char prioridad[101];
  char hora[9];
} paciente;

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

//  Funcion para registrar paciente
void registrar_paciente(List *pacientes) {
  paciente *paciente_actual = (paciente *)malloc(sizeof(paciente));
  if (paciente_actual == NULL)
    exit(EXIT_FAILURE);

  // Ingresar datos del paciente y obtener la hora actual
  struct tm *fecha_hora;
  time_t segundos = time(NULL);

  fecha_hora = localtime(&segundos);

  int hora = fecha_hora->tm_hour - 4;
  int minutos = fecha_hora->tm_min;
  int segundos_actual = fecha_hora->tm_sec;

  char hora_str[9];

  sprintf(hora_str, "%02d:%02d:%02d", hora, minutos, segundos_actual);
  strcpy(paciente_actual->hora, hora_str);

  printf("Registrar nuevo paciente\n");
  printf("-------------------------------\n");
  printf("Ingrese el nombre del paciente: ");
  scanf(" %[^\n]s", paciente_actual->nombre);
  printf("Ingrese la edad del paciente: ");
  scanf("%i", &paciente_actual->edad);
  printf("Ingrese el síntoma del paciente: ");
  scanf(" %[^\n]s", paciente_actual->sintoma);
  strcpy(paciente_actual->prioridad, "Baja");
  printf("Se registro a las %s\n", paciente_actual->hora);
  printf("-------------------------------\n");
  list_pushBack(pacientes, paciente_actual);//se guarda al final de una lista auxiliar
}
// Funcion para asignar prioridad a paciente
void reasignar(paciente *paciente) {
  char opcion, priori;
  //Se muestra los datos del paciente
  printf("-------------------------------\n");
  printf("Datos del paciente:\n");
  printf("Nombre: %s\n", paciente->nombre);
  printf("Edad: %i\n", paciente->edad);
  printf("Síntoma: %s\n", paciente->sintoma);
  printf("Desea reasignar la prioridad?(s/n)\n");
  printf("-------------------------------\n");
  scanf(" %c", &opcion);
  //Se muestran los casos según la opción
  switch (opcion) {
  case 's':
    limpiarPantalla();
    printf("Seleccione que prioridad que le desea asignar:\n");
    printf("1) Alta\n");
    printf("2) Medio\n");
    printf("3) Baja\n");

    scanf(" %c", &priori);
    limpiarPantalla();
    switch (priori) {
      //Se reasigna la prioridad
    case '1':
      strcpy(paciente->prioridad, "Alta");
      break;
    case '2':
      strcpy(paciente->prioridad, "Medio");
      break;
    case '3':
      strcpy(paciente->prioridad, "Baja");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    break;
  case 'n':
    limpiarPantalla();
    break;
  default:
    puts("Opción no válida. Por favor, intente de nuevo.");
    printf("-------------------------------\n");
  }
}

//Funcion para separar por listas los pacientes según prioridad
void asignar_prioridad(List *pacientes, List *pacientesMedio,
                       List *pacientesAlta, List *pacientesBaja) {
  paciente *paciente = list_first(pacientes);
  if (paciente == NULL) {
    printf("-------------------------------\n");
    printf("No hay pacientes registrados\n");
    printf("-------------------------------\n");
  } else {
    while (paciente != NULL) {
      reasignar(paciente);
      if (strcmp(paciente->prioridad, "Alta") == 0) {
        list_pushBack(pacientesAlta, paciente);//Se guarda en la lista de alta prioridad
      } else if (strcmp(paciente->prioridad, "Medio") == 0) {
        list_pushBack(pacientesMedio, paciente);//Se guarda en la lista de media prioridad
      } else {
        list_pushBack(pacientesBaja, paciente);//Se guarda en la lista de baja prioridad
      }
      paciente = list_next(pacientes);//Pasa al siguiente paciente
      list_popFront(pacientes);//Elimina el paciente de la lista auxiliar
    }
    printf("-------------------------------\n");
    printf("Prioridades asignadas correctamente\n");
    printf("-------------------------------\n");
  }
}
//Funcion para mostrar la lista de espera
void mostrar_lista_pacientes(List *pacientes, List *pacientesMedio, List *pacientesAlto) {
  paciente *datoAlto = list_first(pacientesAlto);
  paciente *datoMedio = list_first(pacientesMedio);
  paciente *datoBaja = list_first(pacientes);
  printf("-------------------------------\n");
  //Se pregunta si las listas estan vacias
  if (datoAlto == NULL && datoMedio == NULL && datoBaja == NULL) {
    printf("No hay pacientes en la cola de espera\n");
    printf("-------------------------------\n");
  } else {
    while (datoAlto != NULL) {
      //Se muestran los pacientes de alta prioridad
      printf("Nombre: %s - Prioridad: %s\n", datoAlto->nombre, datoAlto->prioridad);
      printf("Fue ingresado a las %s\n", datoAlto->hora);
      printf("-------------------------------\n");
      datoAlto = list_next(pacientesAlto);
    }
    while (datoMedio != NULL) {
      //Se muestran los pacientes de medio prioridad
      printf("Nombre: %s - Prioridad: %s\n", datoMedio->nombre, datoMedio->prioridad);
      printf("Fue ingresado a las %s\n", datoMedio->hora);
      printf("-------------------------------\n");
      datoMedio = list_next(pacientesMedio);
    }
    while (datoBaja != NULL) {
      //Se muestran los pacientes de baja prioridad
      printf("Nombre: %s - Prioridad: %s\n", datoBaja->nombre, datoBaja->prioridad);
      printf("Fue ingresado a las %s\n", datoBaja->hora);
      printf("-------------------------------\n");
      datoBaja = list_next(pacientes);
    }
  }
}
//Funcion para atender al siguiente paciente
void atender_paciente(List *pacientesBajo, List *pacientesMedio,
                      List *pacienteAlto) {
  limpiarPantalla();
  printf("-------------------------------\n");
  //Se busca el paciente con la prioridad mas alta y se muestran sus datos
  paciente *pacienteAlta = list_first(pacienteAlto);
  if (pacienteAlta == NULL) {
    paciente *pacienteMedio = list_first(pacientesMedio);
    if (pacienteMedio == NULL) {
      paciente *pacienteBajo = list_first(pacientesBajo);
      if (pacienteBajo == NULL) {
        printf("No hay pacientes en la cola de espera\n");
      } else {
        printf("El siguiente paciente es: %s\n", pacienteBajo->nombre);
        printf("Edad: %i\n", pacienteBajo->edad);
        printf("Sintoma: %s\n", pacienteBajo->sintoma);
        printf("Prioridad: %s\n", pacienteBajo->prioridad);
        printf("Fue ingresado a las %s\n", pacienteBajo->hora);
        list_popFront(pacientesBajo);
      }
    } else {
      printf("El siguiente paciente es: %s\n", pacienteMedio->nombre);
      printf("Edad: %i\n", pacienteMedio->edad);
      printf("Sintoma: %s\n", pacienteMedio->sintoma);
      printf("Prioridad: %s\n", pacienteMedio->prioridad);
      printf("Fue ingresado a las %s\n", pacienteMedio->hora);
      list_popFront(pacientesMedio);
    }
  } else {
    printf("El siguiente paciente es: %s\n", pacienteAlta->nombre);
    printf("Edad: %i\n", pacienteAlta->edad);
    printf("Sintoma: %s\n", pacienteAlta->sintoma);
    printf("Prioridad: %s\n", pacienteAlta->prioridad);
    printf("Fue ingresado a las %s\n", pacienteAlta->hora);
    list_popFront(pacienteAlto);
  }
  printf("-------------------------------\n");
}
//Funcion para mostrar listas en comun
void mostrar_lista(List *lista) {
  paciente *dato = list_first(lista);
  printf("-------------------------------\n");
  if (dato == NULL)
    printf("No hay pacientes registrados\n");
  else {
    while (dato != NULL) {
      //Se muestran los datos de las personas
      printf("Nombre:");
      printf("%s - Prioridad: %s\n", dato->nombre, dato->prioridad);
      printf("Fue ingresado a las %s\n", dato->hora);
      dato = list_next(lista);
    }
  }
  printf("-------------------------------\n");
}

// Funcio para mostrar pacientes por prioridad
void mostrarPrioridad(List *pacientes, List *pacientesMedio,
                      List *pacientesAlto) {
  char eleccion;
  //Se selecciona la prioridad que se desea ver
  printf("-------------------------------\n");
  printf("Seleccione que prioridad desea ver:\n");
  printf("1) Alta\n");
  printf("2) Medio\n");
  printf("3) Baja\n");
  printf("-------------------------------\n");
  scanf(" %c", &eleccion);
  limpiarPantalla();
  switch (eleccion) {
    //Se muestra la lista seleccionada
  case '1':
    mostrar_lista(pacientesAlto);
    break;
  case '2':
    mostrar_lista(pacientesMedio);
    break;
  case '3':
    mostrar_lista(pacientes);
    break;
  default:
    printf("Opción inválida\n");
    break;
  }
}

int main() {
  char opcion;
  List *pacientes = list_create();
  List *pacientesBaja = list_create();
  List *pacientesMedio = list_create();
  List *pacientesAlto = list_create();
  // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_paciente(pacientes);
      break;
    case '2':
      asignar_prioridad(pacientes, pacientesMedio, pacientesAlto,
                        pacientesBaja);
      break;
    case '3':
      mostrar_lista_pacientes(pacientesBaja, pacientesMedio, pacientesAlto);
      break;
    case '4':
      atender_paciente(pacientesBaja, pacientesMedio, pacientesAlto);
      break;
    case '5':
      mostrarPrioridad(pacientesBaja, pacientesMedio, pacientesAlto);
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(pacientes);

  return 0;
}
