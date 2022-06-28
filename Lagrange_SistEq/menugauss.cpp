#include "gauss.h"


void menuGauss(){
   Gauss objeto1;
   int opcion=0;

   do{
       system("cls");
       system("cls");
        cout<<"\n1- INGRESO DE DATOS\n";
        cout<<"2- FORMA DE MATRIZ\n";
        cout<<"3- SOLUCION DE INCOGNITAS\n";
        cout<<"4- Vuelta a menu principal\n";

        cout<<"\n\n";

        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
               system("cls");
               objeto1.ingresarDatos();
               system("pause");
               break;
            case 2:
               system("cls");
               objeto1.muestraDatos();
               system("pause");
               break;
            case 3:
               system("cls");
               objeto1.resuelvePivot();
               objeto1.muestraSolucion();
               system("pause");
               return;
            case 4:
               system("cls");
               //cout<<"Usted esta regresando al menu principal.\n";
               break;
            default:
                system("cls");
                cout<<"Ha ingresado una opcion incorrecta. Elija nuevamente una opcion.\n";
                break;
        }

    }while(opcion!=4);
}
