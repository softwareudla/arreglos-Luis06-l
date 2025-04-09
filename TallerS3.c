#include <stdio.h>
#include <string.h>
int main()
{

    int estudiantes[5];
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
        while (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            printf("Error: Debe ingresar un numero.\n: ");
        }
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
                   
                    while (scanf("%f", &nMat[cont]) != 1) {
                        
                        while (getchar() != '\n');
                        printf("Error: Debe ingresar un numero.\nIngrese la nota del estudiante en Matematica: ");
                    }
                    
                    if (nMat[cont] > 10 || nMat[cont] < -1)
                    {
                        printf("Nota invalida\n");
                    }

                } while (nMat[cont] > 10 || nMat[cont] < -1);
                do
                {
                    printf("Ingrese la nota del estudiante en Lengua: ");
                  
                    while (scanf("%f", &nLen[cont]) != 1) {
                        
                        while (getchar() != '\n');
                        printf("Error: Debe ingresar un numero.\nIngrese la nota del estudiante en Lengua: ");
                    }
                    
                    if (nLen[cont] > 10 || nLen[cont] < -1)
                    {
                        printf("Nota invalida\n");
                    }

                } while (nLen[cont] > 10 || nLen[cont] < -1);

                do
                {
                    printf("Ingrese la nota del estudiante en Fisica ");
                 
                    while (scanf("%f", &nFis[cont]) != 1) {
                        
                        while (getchar() != '\n');
                        printf("Error: Debe ingresar un numero.\nIngrese la nota del estudiante en Fisica ");
                    }
                    
                    if (nFis[cont] > 10 || nFis[cont] < -1)
                    {
                        printf("Nota invalida\n");
                    }

                } while (nFis[cont] > 10 || nFis[cont] < -1);
                cont++;
            }else
            {
                printf("!!LIMITE DE ESTUDIANTES ALCANZADO!!");
            }
            
            break;
        case 2:

            printf("NOTAS:\n");
            printf("Nombre\t\t\tMatematica\t\tLengua\t\tFisica\t\tPromedios\n");
            for (int i = 0; i < cont; i++)
            {
                float promedio[5];
                promedio[i] = (nMat[i] + nLen[i] + nFis[i]) / 3;
                printf("%s\t\t\t%.2f\t\t\t%.2f\t\t%2.f\t\t%.2f\n", nombres[i], nMat[i], nLen[i], nFis[i], promedio[i]);
            }
            break;
        case 3:
            int c1 = 0;
            float pr1M = 0, pr1L = 0, pr1F = 0, pr2M = 0, pr2L = 0, pr2F = 0;
            printf("PROMEDIO DE ASIGNATURAS:\n");
            for (int i = 0; i < cont; i++)
            {
                pr1M += nMat[i];
                pr1L += nLen[i];
                pr1F += nFis[i];
                c1++;
            }
            pr2M = pr1M / c1;
            pr2L = pr1L / c1;
            pr2F = pr1F / c1;
            printf("MATEMATICA:\t %.2f\n", pr2M);
            printf("LENGUA    :\t %.2f\n", pr2L);
            printf("FISICA    :\t %.2f\n", pr2F);
            break;
        case 4:
        int naux;
        float min=10, max=0;
            printf("Seleccione el numero de estudiante al que quiere visualizar\n");
            
            for (int i = 0; i < cont; i++)
            {
                printf("%i\t%s\n", i, nombres[i]);
            }
            scanf("%d", &naux);
           
             if(nMat[naux]>max){
                max=nMat[naux];
             } 
             if(nLen[naux]>max){
                max=nLen[naux];
             } 
             if(nFis[naux]>max){
                max=nFis[naux];
             } 
             if(nMat[naux]<min){
                min=nMat[naux];
             } 
             if(nLen[naux]<min){
                min=nLen[naux];
             } 
             if(nFis[naux]<min){
                min=nFis[naux];
             }
             
             printf("La nota mas alta del estudiante %s es: %.2f\n", nombres[naux], max);
             printf("La nota mas alta del estudiante %s es: %.2f\n", nombres[naux], min);
             break;
        case 5:
        float nAltaM = 0, nAltaL=0, nAltaF=0, nBajaM = 11, nBajaL = 11, nBajaF = 11;
        for (int i = 0; i < cont; i++)
        {

            if (nMat[i] > nAltaM)
            {
                nAltaM = nMat[i];
            }
            if (nLen[i] > nAltaL)
            {
                nAltaL = nLen[i];
            }
            if (nFis[i] > nAltaF)
            {
                nAltaF = nFis[i];
            }

            if (nMat[i] < nBajaM)
            {
                nBajaM = nMat[i];
            }
            if (nLen[i] < nBajaL)
            {
                nBajaL = nLen[i];
            }
            if (nFis[i] < nBajaF)
            {
                nBajaF = nFis[i];
            }
        }
        printf("La nota mas alta de Matematica es: %.2f\n", nAltaM);
        printf("La nota mas baja de Matematica es: %.2f\n", nBajaM);
        printf("La nota mas alta de Lengua es    : %.2f\n", nAltaL);
        printf("La nota mas baja de Lengua es    : %.2f\n", nBajaL);
        printf("La nota mas alta de Fisica es    : %.2f\n", nAltaF);
        printf("La nota mas baja de Fisica es    : %.2f\n", nBajaF);

        break;
        case 6:
        int nAM=0, nAL=0, nAF=0, nRM=0, nRL=0, nRF=0;
        for (int i = 0; i < cont; i++)
        {

            if (nMat[i] >= 6)
            {
                nAM++;
            }if(nMat[i]<6){
                nRM++;
            }
            if (nLen[i] >= 6)
            {
                nAL++;
            }if(nLen[i]<6){
                nRL++;
            
            }
            if (nFis[i] >= 6)
            {
                nAF++;
            }if(nFis[i]<6){
                nRF++;
            
            }
            
        }

        printf("           Aprobados\t\tReprobados \n");
        printf("MATEMATICA  %d      \t\t%d \n",nAM, nRM );
        printf("LENGUA      %d      \t\t%d \n", nAL, nRL);
        printf("FISICA      %d      \t\t%d \n", nAF, nRF);
        
       break;
       case 7: 
       printf("Gracias por usar nuestro programa...");
        default:
            break;
        }

    } while (opcion != 7);
    return 0;
}