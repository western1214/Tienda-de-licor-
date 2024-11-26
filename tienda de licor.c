#include <stdio.h>
#include <string.h>

 typedef struct {
    char marca[50];
    float grados;
    char tipo[50];
    float precio;
    float volumen;
    int cantidad;
    int serial;
}Licor;

void menu();
void switchh(Licor producto[],int *ban, int *serial, int *tam);
void agregar(Licor producto[], int *tam, int *ser);
void eliminar(Licor producto[], int *tam);
void modificar(Licor producto[], int tam);
void consultar(Licor producto[], int *tam);
void consulta_general(Licor producto[], int size);
void vender(Licor producto[], int *tam);
void comprar(Licor producto[], int tam);
void calcular_inventario(Licor producto[], int *tam);
void verificar_stock_bajo(Licor producto[], int *tam);


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
        agregar(producto,tam,serial);
        break;
      case 2:
        eliminar(producto,tam);
        break;
      case 3:
        modificar(producto, *tam);
        break;
      case 4: 
        consultar(producto,tam);
        break;
      case 5:
         consulta_general(producto, *tam);
        break;
      case 6:
         vender(producto, tam);
        break;
      case 7:
         comprar(producto,tam);
        break;
      case 8:
        calcular_inventario(producto,tam);
        break;
      case 9:
        verificar_stock_bajo(producto,tam);
        break;
      default:
        printf("Esa opcion no existe, intentalo de nuevo!!");
        break;
      }
    }
}

void agregar(Licor producto[], int *tam, int *ser){ 
    int o,u,t,p;
    if (*tam >= 50) {
        printf("\n\nSe alcanzó el límite de productos.\n");
    }else
    {
      printf("\n\nIngresa el nombre del producto: ");
        fgets(producto[*tam].tipo,49,stdin);
        fflush(stdin);   // cleanStdIn
        printf("\nIngresa la marca del producto: ");
        fgets(producto[*tam].marca,49,stdin);
        fflush(stdin);   // cleanStdIn
        do {
          printf("\nIngresa los grados de alcohol que contiene: ");
          o=scanf("%f", &producto[*tam].grados);
          fflush(stdin);   // cleanStdIn
        } while(o != 1 || producto[*tam].grados<0); 
        do
        {
          printf("\nIngresa de cuantos litros es el producto: ");
          u=scanf("%f", &producto[*tam].volumen);
          fflush(stdin);   // cleanStdIn
        } while (u != 1 || producto[*tam].volumen<0);
        do
        {
          printf("\nIngresa el precio que tendra el articulo: ");
          t=scanf("%f", &producto[*tam].precio);
          fflush(stdin);   // cleanStdIn
        } while (t !=1 || producto[*tam].precio<0);
        printf("\nEl numero serial del producto es: %d\n ", *ser);
        producto[*tam].serial=*ser;
        *ser=*ser+1;
        do
        {
          printf("\nIngresa cuantos de este tipo vas a agregar: ");
          p=scanf("%d", &producto[*tam].cantidad);
          fflush(stdin);   // cleanStdIn
        } while (p != 1 || producto[*tam].cantidad<0);
        *tam=*tam+1;
    }    
}


void eliminar(Licor producto[], int *tam){
  int out,i,j,serial,band=0;
  printf(" _____________________________________________________  \n");
  printf("|   Ingresa el numero serial del producto a eliminar  | \n");
  printf("|_____________________________________________________| \n\n");
  do

  { 
    printf("NO.SERIAL: ");
    out=scanf("%d", &serial);
    fflush(stdin);
    if (serial < 500 || serial > 550)
    {
      printf("\nESE SERIAL NO PUEDE EXISTIR\n");
      band=1;
    }else
    {
      for (i = 0; i < *tam; i++)
      {
        if(producto[i].serial==serial){
          band=1;
          for ( j = i; j < *tam-1; j++)
          {
              producto[j]=producto[j+1];  
          }
          *tam=*tam-1;
          printf("\nEl producto ha sido eliminado con exito!\n");
        }
      }
    } 
  } while (out != 1);
  if (band!=1)
  {
    printf("\n\nNo se encuentra ese producto\n\n");
  }

}

void modificar(Licor producto[], int tam) {
    int out, serial, i=0, o, u, t, p, band=0;
    if(tam>0){
  printf(" _____________________________________________________  \n");
  printf("|  Ingresa el numero serial del producto a modificar  | \n");
  printf("|_____________________________________________________| \n\n");
  do { 

    printf("NO.SERIAL: ");
    out=scanf("%d", &serial);
    fflush(stdin);
    for (int i = 0; i < tam; i++) {
      if (producto[i].serial == serial) {
        band=1;
        printf("\n\n Tipo: %s Marca: %s Grados: %.2f \n Precio: %.2f $ \n Volumen  del producto: %.2f L \n serial: %d \n cantidad en existencia: %d \n", producto[i].tipo, producto[i].marca, producto[i].grados, producto[i].precio , producto[i].volumen, producto[i].serial, producto[i].cantidad );
        break;      
      }
    }
            do {
                printf("\nIngresa los nuevos grados de alcohol que contiene: ");
                o = scanf("%f", &producto[i].grados);
                fflush(stdin);
            } while (o != 1);
            do {
                printf("\nIngresa la nueva cantidad de litros del producto: ");
                u = scanf("%f", &producto[i].volumen);
                fflush(stdin);
            } while (u != 1);
            do {
                printf("\nIngresa el nuevo precio del producto: ");
                t = scanf("%f", &producto[i].precio);
                fflush(stdin);
            } while (t != 1);
            do {
                printf("\nIngresa la nueva cantidad disponible: ");
                p = scanf("%d", &producto[i].cantidad);
                fflush(stdin);
            } while (p != 1);

            printf("\nEl producto se ha modificado exitosamente.\n");

    
    } while (out != 1);
  
    if (band!=1) {
        printf("\nEl producto no fue encontrado.\n");
    }
    }
}

void consultar(Licor producto[], int *tam){
    printf(" ______________________________________________\n");
    printf("|INGRESA EL NUMERO SERIAL DEL PRODUCTO A BUSCAR|\n");
    printf("|______________________________________________|\n");
    printf("\n");
    int i=0,serial,out,band=0;
    do
    {
        printf("NO.SERIAL: ");
        out=scanf("%d", &serial);
        fflush(stdin);
        for (i = 0; i < *tam; i++)
        {
        if(producto[i].serial==serial){
            band=1;
            printf("\n\n Tipo: %s Marca: %s Grados: %.2f \n Precio: %.2f $ \n Volumen  del producto: %.2f L \n serial: %d \n cantidad en existencia: %d \n", producto[i].tipo, producto[i].marca, producto[i].grados, producto[i].precio , producto[i].volumen, producto[i].serial, producto[i].cantidad );
            break;      
        }
        }
        
    } while (out != 1);
    if (band!=1)
    {
        printf("\n\nNo se encuentra ese producto\n\n");
    }
}

void calcular_inventario(Licor producto[], int *tam){
  int i,productos=0;
  float total=0;
  for (i = 0; i < *tam; i++)
  {
    productos=productos+producto[i].cantidad;
    total=total+(producto[i].precio*producto[i].cantidad);
  }
  printf("\n");
  printf(" ____________________________________________________________________ \n");
  printf("|Cuentas con %d unidades                                             |\n", productos);
  printf("|                                                                    |\n");
  printf("|El precio total de tu inventario es de $%.2f                        |\n", total);
  printf("|____________________________________________________________________|\n\n");
}

void verificar_stock_bajo(Licor producto[], int *tam){
  printf("\n");
  printf(" ____________________________________________________  \n");
  printf("|   Productos con stock bajo (menos de 4 unidades)   | \n");
  printf("|____________________________________________________| \n\n");
  int i,band;
  if (*tam==0)
    {
      printf("\n\nAun no has agregado ningun producto\n\n");
    }
  for (i = 0; i < *tam; i++)
  { 
    if (producto[i].cantidad<4)
    {
       printf("Serial: %d\nTipo: %sMarca: %sCantidad: %d\n\n", producto[i].serial, producto[i].tipo, producto[i].marca, producto[i].cantidad);
       band = 1;
    }
    if (band != 1)
    {
      printf("No hay productos con stock bajo\n\n");
    } 
  } 
}
void consulta_general(Licor producto[], int tam){
int i;
   for(i=0;i<=tam;i++){
    printf("%d: %s - %s - %d", i, producto[i].tipo, producto[i].marca, producto[i].serial);
  }
    }

void vender(Licor producto[], int *tam){
  int i=0,serial,out,band=0, x;
  if(*tam>0){

  printf(" _____________________________________________________  \n");
  printf("|   Ingresa el numero serial del producto a vender    | \n");
  printf("|_____________________________________________________| \n\n");

    do
    {
        printf("NO.SERIAL: ");
        out=scanf("%d", &serial);
        fflush(stdin);
        for (i = 0; i < *tam; i++)
        {
          if(producto[i].serial==serial){
            band=1;
            printf("Que cantidad desea vender? ");
            scanf("Cantidad: %d", &x);
            if(producto[i].cantidad>=x){
            producto[i].cantidad= producto[i].cantidad - x;
            break;
            }
          } else {
            printf("\n\nNo hay suficiente stock para vender\n\n");
          }
        }

    } while (out != 1);
    if (band!=1)
    {
        printf("\n\nNo se encuentra ese producto\n\n");
    }
  }
  else{
    printf("\n\nNo has agregado productos para vender\n\n");
  }
}

void comprar(Licor producto[], int tam){
    printf(" ___________________________________________________________\n");
    printf("|INGRESA EL NUMERO SERIAL DEL PRODUCTO QUE QUIERAS COMPRAR: |\n");
    printf("|___________________________________________________________|\n");
    printf("\n");
    int i=0,serial,out,band=0, x;
    do
    {
        printf("NO.SERIAL: ");
        out=scanf("%d", &serial);
        fflush(stdin);
        for (i = 0; i < tam; i++)
        {
        if(producto[i].serial==serial){
            band=1;
            printf("Que cantidad desea comprar? ");
            scanf("Cantidad: %d", &x);
            producto[i].cantidad= producto[i].cantidad + x;
            break;
        }
        }

    } while (out != 1);
    if (band!=1)
    {
        printf("\n\nNo se encuentra ese producto\n\n");
    }
}



