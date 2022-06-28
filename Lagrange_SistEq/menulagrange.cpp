#include "lagrange.h"


void menuLagrange(){

    Lagrange objeto1;
    int opcion, err=0;

    do{
        system("cls");
        cout<<"\n1- INGRESO DE DATOS\n";
        cout<<"2- CALCULO LX\n";
        cout<<"3- CALCULO POLINOMIO\n";
        cout<<"4- Vuelta a menu principal\n";

        cout<<"\n\n";

        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                system("cls");
            	do{
				err = objeto1.setValores();
            	}while(err);
            	objeto1.setContadores();
            	cout<<endl;
            	cout<<"Presione una tecla para volver al menu"<<endl;
                while(!kbhit());
            	break;
            case 2:
                system("cls");
                objeto1.calcularLx();
                cout<<endl;
                cout<<"Presione una tecla para volver al menu"<<endl;
                while(!kbhit());
                break;
            case 3:
                system("cls");
                objeto1.calcularPolinomio();
                cout<<endl;
                cout<<"Presione una tecla para volver al menu principal"<<endl;
                while(!kbhit());
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
