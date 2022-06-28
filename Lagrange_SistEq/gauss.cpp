
#include "gauss.h"


void Gauss::creaMatriz(){

	do{
	cout<<"Ingrese el tamano de la matriz cuadrada (>1): ";
	cin>>n;
	}while(n<=1);
	cout<<endl;
	mat = new double* [n];
	for (int i=0;i<n;i++)
		mat[i]=new double [n];

    per=new int[n];

}

void Gauss::creaArrayValoresIndependientes(){

	b = new double [n];
}

void Gauss::ingresarDatos(){

	creaMatriz();
	creaArrayValoresIndependientes();
    cout<<"---------------------------------------------------"<<endl<<endl;
	for (int i=0; i<n; i++)
  		for (int j=0;j<n; j++){
    		cout<<"Ingrese el valor de la incognita de ("<<i+1<<","<<j+1<<"): ";
    		cin>>mat[i][j];
  		}
    cout<<"---------------------------------------------------"<<endl;
	// valores independientes

	for (int i=0;i<n;i++){
  		cout<<"Ingrese el valor independiente "<<i+1<<": ";
  		cin>>b[i];
	}

}

void Gauss::muestraDatos(){

	cout<<"\nSistema a resolver: \n";
	for (int i=0; i<n; i++){
		cout<<endl;
		cout<<"Ecuacion "<<i+1<<": ";
		for (int j=0;j<n; j++){
    		if (j!=2){
        		cout<<mat[i][j]<<"x["<<j<<"] + ";
    		}
			else {
        	cout<<mat[i][j]<<"x["<<j<<"] = ";
    		}
    	}
  		cout<<b[i]<<"  ";
   }
	cout <<endl;

}

void Gauss::creaMatrizInverso(){

	x= new double [n];

}

void Gauss::muestraSolucion(){
    int r=0;
	for (int i=0; i<n;i++){
  		if(isnan(x[i]) || isinf(x[i])){
            if(n<4){
                printf("%c = ",120+i);
                cout<<"Indeterminado\n";
            }else if(i<3){
                printf("%c = ",120+i);
                cout<<"Indeterminado\n";
            }else{
                printf("%c = ",109+r);
                cout<<"Indeterminado\n";
                r++;
            }
        }else{
            if(n<4){
                printf("%c = ",120+i);
                cout<<x[i]<<"\n";
            }
            else if(i<3){
                printf("%c = ",120+i);
                cout<<x[i]<<"\n";
            }
            else{
                    printf("%c = ",109+r);
                    cout<<x[i]<<"\n";
                    r++;
            }

        }


    }
    cout<<endl;

    liberaMemo();

}

void Gauss::resuelvePivot(){




	for (int i=1;i<n;i++)
		per[i]=i;

//eliminacion

	for (int i=0;i<n;i++){

//busqueda pivot

		double piv=abs(mat[i][i]);
		int ipiv=i;
		for (int j=i;j<n;j++){
    		if( abs(mat[j][i])>piv){
    			ipiv=j;
    			piv= abs(mat[j][i]);
    		}
		}

//Permuta filas i and ipiv
    	for (int j=i;j<n;j++) {
    		double temp=mat[i][j];
    		mat[i][j]=mat[ipiv][j];
    		mat[ipiv][j]=temp;
    	}
    	double temp = b[i];
     	b[i]=b[ipiv];
     	b[ipiv]=temp;

// permutacion array
    	int itemp=per[i];
    	per[i]=per[ipiv];
    	per[ipiv]=itemp;

//Eliminacion

  		for (int j=i+1; j<n; j++){
			double   piv=mat[j][i]/mat[i][i]; //m[j][i] se anula despues de la primera el.
    		for (int k=i; k<n; k++){
      			mat[j][k]=mat[j][k]- piv*mat[i][k];
      		}
    		b[j]=b[j]- piv*b[i];
    	}
	}

	creaMatrizInverso();
	resuelveInversa();

}

void Gauss::resuelveInversa(){

	for (int i=n-1;i>=0;i--){
   		x[i]=b[i];
		  for (int j= n-1;j>i;j--)
    		x[i]=x[i]-mat[i][j]*x[j];
		x[i]=x[i]/mat[i][i];
  }

}


void Gauss::liberaMemo(){

    delete[] mat;
    delete x;
    delete b;
    delete per;

}


