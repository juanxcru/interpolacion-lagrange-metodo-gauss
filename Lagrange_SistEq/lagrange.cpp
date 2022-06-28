#include "lagrange.h"


int Lagrange::setValores(){


    for( int i = 0 ; i<3 ; i++ ){


        for( int j= 0; j<2 ; j++ ){

            if(j!=1)
                cout<<"\nIngrese la coordenada [x"<<i+1<<"]"<<": ";
			else if (j == 1)
                cout<<"\nIngrese la coordenada [y"<<i+1<<"]"<<": ";
            cin>>Matriz[i][j]; // 0,0 = 0 . 0,1 = 1  .. 1,0 = 1 . 1,1 = 3  2,0= 2  2,1=0

        }

    }


    for(int r=0;r<2;r++){
        if(Matriz[r][0] == Matriz[2][0]){
	    	cout<<"\nCoordenadas inconsistentes"<<endl<<"Presiona una tecla para volver a ingresar"<<endl;
	    	while(!kbhit());
	    	system("cls");
	    	return 1;
			}
		}
    for(int r=1;r<3; r++){
	    	if(Matriz[r][0] == Matriz[0][0]){
	    	cout<<"\nCoordenadas inconsistentes"<<endl<<"Presiona una tecla para volver a ingresar"<<endl;
            while(!kbhit());
	    	system("cls");
	    	return 1;
			}
		}

    return 0;
}

int Lagrange::setContadores (){

    I = N -1;
    J = N -1 ;
}

int Lagrange::calcularPolinomio (){

 float Px =( Matriz [0][1] * Li[0] ) + ( Matriz [1][1] * Li[1] ) + ( Matriz [2][1] * Li[2] );
        cout<<"\n\nEl resultado del polinomio es: "<<Px<<endl;
}

void Lagrange::calcularLx (){

    int valorX;

    cout<<"\nIngrese el valor de X: \n";
    cin>>valorX;

    Li[0] = (( valorX - Matriz[1][0] )  * ( valorX - Matriz[2][0])) / (( Matriz [0][0] - Matriz[1][0]) * ( Matriz[0][0] - Matriz[2][0] ));
	cout<<"\nEl resultado es: Li(1)="<<Li[0]<<endl;

	Li[1] = (( valorX - Matriz[0][0] ) * ( valorX - Matriz[2][0] )) / (( Matriz [1][0] - Matriz [0][0] ) * ( Matriz [1][0] - Matriz [2][0] ));
    cout<<"\nEl resultado es: Li(2)="<<Li[1]<<endl;


    Li[2] = (( valorX - Matriz[0][0] ) * ( valorX - Matriz[1][0] )) / (( Matriz [2][0] - Matriz [0][0] ) * ( Matriz [2][0] - Matriz [1][0] ));
    cout<<"\nEl resultado es: Li(3)="<<Li[2]<<endl<<endl;
}
