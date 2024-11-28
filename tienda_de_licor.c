#include <stdio.h>

 typedef struct {
    char marca[50];
    float grados;
    char tipo[50];
    float precio;
    float volumen;
    int cantidad;
    int serial;
}Licor;

void agregar(Licor producto[], int *tam, int *ser);
void eliminar(Licor producto[], int *tam);
void modificar(Licor producto[], int tam);
void consultar(Licor producto[], int tam);
void consultaGeneral(Licor producto[], int size);
void vender(Licor producto[], int tam);
void comprar(Licor producto[], int *tam, int *ser);
void calcularInventario(Licor producto[], int tam);
void verificarStockBajo(Licor producto[], int tam);

// Funciones auxiliares
void menu();
void switchh(Licor producto[],int *ban, int *serial, int *tam);
void leerInt(char *mensaje, int *variable);
void leerFloat(char *mensaje, float *variable);

int main(){
  Licor producto[50];
  int serial=500,ban=0,tam=0;
  while (ban==0){
  menu();
  switchh(producto,&ban,&serial,&tam);
  }
  return 0;
}

void menu(){
  printf("\n");
  printf(" _____________________________________________                         .-.-.      \n");
  printf("|           Que deseas hacer hoy:             |                        .###.      \n");
  printf("|---------------------------------------------|                        .###.      \n");
  printf("|  0) Salir del programa                      |                        .###.      \n");
  printf("|  1) Agregar producto                        |                        .###.      \n");
  printf("|  2) Eliminar producto                       |                        .@#@.      \n");
  printf("|  3) Modificar producto                      |                        .@#@.      \n");
  printf("|  4) Consultar                               |                        .@#@.      \n");
  printf("|  5) Consulta general                        |                       -@###@-     \n");
  printf("|  6) Vender producto                         |                      +@#####@+    \n");
  printf("|  7) Comprar producto                        |                      #######@#    \n");
  printf("|  8) Calcular Inventario                     |                      ##.....##    \n");
  printf("|  9) Productos a punto de agotarse           |           -====---:  ##.....##    \n");
  printf("|_____________________________________________|          .######@#=  ##.:...##    \n");
  printf("                                                         :#+*#####@  ##::::.##    \n");
  printf("                                                          ##-#####*  ##::::.##    \n");
  printf("                                                           +#####-   ##:::..##    \n");
  printf("                                                              +      ##::...##    \n");
  printf("                                                              =      ##.....##    \n");
  printf("                                                              =      ##.....##    \n");
  printf("                                                              =      #########    \n");
  printf("                                                            :===:    #########    \n");
  printf("                                                           :-----:   #########    \n");
}

void switchh(Licor producto[], int *ban,int *serial, int *tam){
  int out,des=0;
  printf("La opcion seleccionada fue: ");
  out = scanf("%d", &des);
  fflush(stdin);   // cleanStdIn
    if (out != 1)
    {
      printf("\nEsa no es una opcion valida!\n\n");
    }else
    {
      switch (des)
      {
      case 0:
        *ban=1;
        break;
      case 1:
        agregar(producto, tam, serial);
        break;
      case 2:
        eliminar(producto, tam);
        break;
      case 3:
        modificar(producto, *tam);
        break;
      case 4: 
        consultar(producto, *tam);
        break;
      case 5:
         consultaGeneral(producto, *tam);
        break;
      case 6:
         vender(producto, *tam);
        break;
      case 7:
         comprar(producto, tam, serial);
        break;
      case 8:
        calcularInventario(producto, *tam);
        break;
      case 9:
        verificarStockBajo(producto, *tam);
        break;
      default:
        printf("Esa opcion no existe, intentalo de nuevo!!");
        break;
      }
    }
}

void agregar(Licor producto[], int *tam, int *ser){
  if (*tam >= 50) {
    printf("\n\nSe alcanzó el límite de productos.\n");
  } else {
    printf("\n\nIngresa el nombre del producto: ");
    fgets(producto[*tam].tipo, 49, stdin);
    fflush(stdin); // cleanStdIn
    printf("\nIngresa la marca del producto: ");
    fgets(producto[*tam].marca, 49, stdin);
    fflush(stdin); // cleanStdIn
    leerFloat("\nIngresa los grados de alcohol que contiene: ",
              &producto[*tam].grados);
    leerFloat("\nIngresa de cuantos litros es el producto: ",
              &producto[*tam].volumen);
    leerFloat("\nIngresa el precio que tendra el articulo: ",
              &producto[*tam].precio);
    leerInt("\nIngresa cuantos de este tipo vas a agregar: ",
            &producto[*tam].cantidad);

    printf("\n\nEl numero serial del producto es: %d\n ", *ser);
    producto[*tam].serial = *ser;
    *ser = *ser + 1;
    *tam = *tam + 1;
  }
}

void eliminar(Licor producto[], int *tam) {
  int i, j, serial, band = 0;
  if (*tam > 0) {
    printf(" _____________________________________________________  \n");
    printf("|   Ingresa el numero serial del producto a eliminar  | \n");
    printf("|_____________________________________________________| \n\n");
    leerInt("NO.SERIAL: ", &serial);

    for (i = 0; i < *tam; i++) {
      if (producto[i].serial == serial) {
        band = 1;
        for (j = i; j < *tam - 1; j++) {
          producto[j] = producto[j + 1];
        }
        *tam = *tam - 1;
        printf("\nEl producto ha sido eliminado con exito!\n");
      }
    }
    if (band != 1) {
      printf("\n\nNo se encuentra ese producto\n\n");
    }
  } else {
    printf("\n\nNo has agregado ningun producto.\n\n");
  }
}

void modificar(Licor producto[], int tam) {
  int serial, i = 0, band = 0;
  if (tam > 0) {
    printf(" _____________________________________________________  \n");
    printf("|  Ingresa el numero serial del producto a modificar  | \n");
    printf("|_____________________________________________________| \n\n");
    leerInt("NO.SERIAL: ", &serial);

    for (i = 0; i < tam; i++) {
      if (producto[i].serial == serial) {
        band = 1;
        printf("\n\n Tipo: %s Marca: %s Grados: %.2f \n Precio: %.2f $ \n "
               "Volumen  del producto: %.2f L \n serial: %d \n cantidad en "
               "existencia: %d \n",
               producto[i].tipo, producto[i].marca, producto[i].grados,
               producto[i].precio, producto[i].volumen, producto[i].serial,
               producto[i].cantidad);
        break;
      }
    }
    if (i < tam) {
      printf("\n\nIngresa el nombre del producto: ");
      fgets(producto[i].tipo, 49, stdin);
      fflush(stdin); // cleanStdIn
      printf("\nIngresa la marca del producto: ");
      fgets(producto[i].marca, 49, stdin);
      fflush(stdin); // cleanStdIn
      leerFloat("\nIngresa los grados de alcohol que contiene: ",
                &producto[i].grados);
      leerFloat("\nIngresa de cuantos litros es el producto: ",
                &producto[i].volumen);
      leerFloat("\nIngresa el precio que tendra el articulo: ",
                &producto[i].precio);
      leerInt("\nIngresa cuantos de este tipo vas a agregar: ",
              &producto[i].cantidad);

      printf("\nEl producto se ha modificado exitosamente.\n");
    }

    if (band != 1) {
      printf("\nEl producto no fue encontrado.\n");
    }
  } else {
    printf("\nNo has agregado ningun producto\n");
  }
}

void consultar(Licor producto[], int tam) {
  if (tam > 0) {
    int i = 0, serial, band = 0;
    printf(" ______________________________________________\n");
    printf("|INGRESA EL NUMERO SERIAL DEL PRODUCTO A BUSCAR|\n");
    printf("|______________________________________________|\n");
    printf("\n");
    leerInt("NO.SERIAL: ", &serial);
    for (i = 0; i < tam; i++) {
      if (producto[i].serial == serial) {
        band = 1;
        printf("\n\n Tipo: %s Marca: %s Grados: %.2f \n Precio: %.2f $ \n "
               "Volumen  del producto: %.2f L \n serial: %d \n cantidad en "
               "existencia: %d \n",
               producto[i].tipo, producto[i].marca, producto[i].grados,
               producto[i].precio, producto[i].volumen, producto[i].serial,
               producto[i].cantidad);
        break;
      }
    }

    if (band != 1) {
      printf("\n\nNo se encuentra ese producto\n\n");
    }
  }
}

void calcularInventario(Licor producto[], int tam) {
  if (tam == 0) {
    printf("\n\nAun no has agregado ningun producto\n\n");
  }

  int i, productos = 0;
  float total = 0;

  for (i = 0; i < tam; i++) {
    productos = productos + producto[i].cantidad;
    total = total + (producto[i].precio * producto[i].cantidad);
  }

  printf("\n");
  printf(" __________________________________________________________________"
         "__ \n");
  printf("|Cuentas con %d unidades                                           "
         "  |\n",
         productos);
  printf("|                                                                  "
         "  |\n");
  printf("|El precio total de tu inventario es de $%.2f                      "
         "  |\n",
         total);
  printf("|__________________________________________________________________"
         "__|\n\n");
}

void verificarStockBajo(Licor producto[], int tam) {
  if (tam == 0) {
    printf("\n\nAun no has agregado ningun producto\n\n");
  }

  printf("\n");
  printf(" ____________________________________________________  \n");
  printf("|   Productos con stock bajo (menos de 4 unidades)   | \n");
  printf("|____________________________________________________| \n\n");
  int i, band;

  for (i = 0; i < tam; i++) {
    if (producto[i].cantidad < 4) {
      printf("Serial: %d\nTipo: %sMarca: %sCantidad: %d\n\n",
             producto[i].serial, producto[i].tipo, producto[i].marca,
             producto[i].cantidad);
      band = 1;
    }
  }

  if (band != 1) {
    printf("No hay productos con stock bajo\n\n");
  }
}

void consultaGeneral(Licor producto[], int tam) {
  if (tam > 0) {
    int i;
    for (i = 0; i < tam; i++) {
      printf("Producto: %d \n\t- Tipo: %s\t- Marca: %s\t- SERIAL: %d\n", i + 1, producto[i].tipo, producto[i].marca, producto[i].serial);
    } 
  } else {
    printf("\n\nAun no has agregado ningun producto\n\n");
   }
}

void vender(Licor producto[], int tam) {
  int i = 0, serial, band = 0, cantidad;
  if (tam > 0) {
    printf(" _____________________________________________________  \n");
    printf("|   Ingresa el numero serial del producto a vender    | \n");
    printf("|_____________________________________________________| \n\n");

    leerInt("NO.SERIAL: ", &serial);

    for (i = 0; i < tam; i++) {
      if (producto[i].serial == serial) {
        band = 1;
        leerInt("Que cantidad desea vender? ", &cantidad);
        if (producto[i].cantidad >= cantidad) {
          producto[i].cantidad = producto[i].cantidad - cantidad;
          break;
        } else {
          printf("\n\nNo hay suficiente stock para vender\n\n");
        }
      }
    }

    if (band != 1) {
      printf("\n\nNo se encuentra ese producto\n\n");
    }
  } else {
    printf("\n\nNo has agregado productos para vender\n\n");
  }
}

void comprar(Licor producto[], int *tam, int *ser) {
  if (*tam > 0) {
    printf(" ___________________________________________________________\n");
    printf("|INGRESA EL NUMERO SERIAL DEL PRODUCTO QUE QUIERAS COMPRAR: |\n");
    printf("|___________________________________________________________|\n");
    printf("\n");
    int i = 0, serial, band = 0, cantidad;

    leerInt("NO.SERIAL: ", &serial);

    for (i = 0; i < *tam; i++) {
      if (producto[i].serial == serial) {
        band = 1;
        leerInt("Que cantidad desea comprar? ", &cantidad);
        producto[i].cantidad = producto[i].cantidad + cantidad;
        break;
      }
    }

    if (band != 1) {
      printf("\n\nNo se encuentra ese producto\n\n");
      agregar(producto, tam, ser);
    }
  } else {
   printf("\n\nNo has agregado productos\nAgregando uno nuevo\n");
   agregar(producto, tam, ser);
  }
}

void leerInt(char *mensaje, int *variable) {
  int salida;
  do {
    printf("%s", mensaje);
    salida = scanf("%d", variable);
    fflush(stdin); // cleanStdIn
  } while (salida != 1 || *variable <= 0);
}

void leerFloat(char *mensaje, float *variable) {
  int salida;
  do {
    printf("%s", mensaje);
    salida = scanf("%f", variable);
    fflush(stdin); // cleanStdIn
  } while (salida != 1 || *variable <= 0);
}
