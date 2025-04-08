#include <stdio.h>
#include <string.h>
int main()
{

    int estudiantes[5];
    char asignatura[3][15];
    char nombres[5][10];
    int opcion, cont = 0, len;
    float nMat[5], nLen[5], nFis[5];

    do
    {
        printf("\t//Seleccione una opcion//\n");
        printf("1. Registrar estudiante\n");
        printf("2. Promedio de los estudiantes\n");
        printf("3. Promedio de las asignaturas\n");
        printf("4. Califiaciones mas altas y bajas por estudiante\n");
        printf("5. Calificaciones mas altas y bajas por asignatura\n");
        printf("6. Estudiantes Aprobados y Reprobados\n");
        printf("7. Salir \n");
        printf(": ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            if (cont < 5)
            {
                printf("\t//Las asignaturas son Matematica, Lengua y Fisica//\n");
                printf("Ingrese el nombre del estudiante %d: ", cont);
                fflush(stdin);
                fgets(nombres[cont], 30, stdin);
                len = strlen(nombres[cont]) - 1;
                nombres[cont][len] = '\0';
                do
                {
                    printf("Ingrese la nota del estudiante en Matematica: ");
                    scanf("%f", &nMat[cont]);
                    if (nMat[cont] > 11 || nMat[cont] < -1)
                    {
                        printf("Nota invalida\n");
                    }

                } while (nMat[cont] > 11 || nMat[cont] < -1);
                do
                {
                    printf("Ingrese la nota del estudiante en Lengua: ");
                    scanf("%f", &nLen[cont]);
                    if (nLen[cont] > 11 || nLen[cont] < -1)
                    {
                        printf("Nota invalida\n");
                    }

                } while (nLen[cont] > 11 || nLen[cont] < -1);

                do
                {
                    printf("Ingrese la nota del estudiante en Fisica ");
                    scanf("%f", &nFis[cont]);
                    if (nFis[cont] > 11 || nFis[cont] < -1)
                    {
                        printf("Nota invalida\n");
                    }

                } while (nFis[cont] > 11 || nFis[cont] < -1);
                cont++;
            }
            break;
        case 2:

            printf("NOTAS:\n");
            printf("Nombre\t\tMatematica\t\tLengua\t\tFisica\t\tPromedios\n");
            for (int i = 0; i < cont; i++)
            {
                float promedio[5];
                promedio[i] = (nMat[i] + nLen[i] + nFis[i]) / 3;
                printf("%s\t\t%.2f\t\t\t%.2f\t\t%2.f\t\t%.2f\n", nombres[i], nMat[i], nLen[i], nFis[i], promedio[i]);
            }
            break;
        case 3:
        int c1=0;
        float pr1M=0, pr1L=0, pr1F=0, pr2M=0, pr2L=0, pr2F=0;
        printf("PROMEDIO DE ASIGNATURAS:\n");
        for (int i = 0; i < cont; i++)
        {
           pr1M+=nMat[i];
            pr1L+=nLen[i];
            pr1F+=nFis[i];
            c1++;
        }
        pr2M=pr1M/c1;
        pr2L=pr1L/c1;
        pr2F=pr1F/c1;
        printf("MATEMATICA:\t %f\n", pr2M);
        printf("LENGUA    :\t %f\n", pr2L);
        printf("FISICA    :\t %f\n", pr2F);
        break;
        default:
            break;
        }

    } while (opcion != 7);

    return 0;
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char id[5][10];
    char nombres[5][30];
    int stock[5];
    float precio[5];
    float total_ganancias = 0, venta = 0;
    int opc1, cont = 0, cantidad, len;

    do
    {
        printf("Selecciones una opcion:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Detalle producto\n");
        printf("5. Total ganancias\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc1);

        switch (opc1)
        {
        case 1:
            if (cont < 5)
            {
                printf("Ingrese el ID del producto %d: ", cont);
                scanf("%s", &id[cont]);
                printf("Ingrese el nombre del producto %d: ", cont);
                fflush(stdin);
                fgets(nombres[cont], 30, stdin);
                len = strlen(nombres[cont]) - 1;
                nombres[cont][len] = '\0';

                printf("Ingrese el stock del producto %d: ", cont);
                scanf("%d", &stock[cont]);
                printf("Ingrese el precio del producto %d: ", cont);
                scanf("%f", &precio[cont]);
                cont++;
            }
            break;
        case 2:
            char naux[10];

            printf("Seleccione el producto que desea vender\n");
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%2.f\n", id[i], nombres[i], stock[i], precio[i]);
            }
            scanf("%s", &naux);
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(id[i], naux) == 0)
                {
                    printf("Ingrese la cantidad de prodcuto a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad <= stock[i])
                    {
                        venta = cantidad * precio[i];
                        printf("EL valor de la venta es: %.2f\n", venta);
                        total_ganancias += venta;
                    }
                    else
                    {
                        printf("No existe stock suficiente para esta venta\n");
                    }
                }
            }
            break;
        case 3:
            int c1 = 0;
            printf("Seleccione el producto que desea reabastecer\n");
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%2.f\n", id[i], nombres[i], stock[i], precio[i]);
            }
            scanf("%s", &naux);
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(id[i], naux) == 0)
                {
                    printf("Ingrese la cantidad de prodcuto a reabastecer: ");
                    scanf("%d", &c1);
                    if (c1 > 0)
                    {
                        stock[i] += c1;
                        printf("EL nuevo stock es de %d\n", stock[i]);
                    }
                    else
                    {
                        printf("El stock no puede ser menor a 0\n");
                    }
                }
            }
        case 4:
            printf("DETALLES DE LOS PRODUCTOS\n");
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%2.f\n", id[i], nombres[i], stock[i], precio[i]);
            }
            break;
        case 5:

            printf("El total de ganancias es de: %f\n", total_ganancias);
            break;
        default:
            break;
        }

    } while (opc1 != 6);

    return 0;
}
*/