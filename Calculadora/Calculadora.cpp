#include<iostream>
using namespace std;

int main() {
	double a=0, b=0;
	char op='q';
	cout<<"Introduzca el primer numero"<<endl;
	cin>>a;
	cout<<"Introduzca la operacion (+,-,*,/,'%')"<<endl;
    bool op_inv=1;
    while(op_inv){
        cin>>op;
        if(op=='+'){
            cout<<"Introduzca el segundo numero"<<endl;
            cin>>b;
            cout<<a+b;
            return 0;
        }
        if(op=='-'){
            cout<<"Introduzca el segundo numero"<<endl;
            cin>>b;
            cout<<a-b;
            return 0;
        }
        if(op=='*'){
            cout<<"Introduzca el segundo numero"<<endl;
            cin>>b;
            cout<<a*b;
            return 0;
        }
        if(op=='/'){
            while(op_inv){
                cout<<"Introduzca el segundo numero"<<endl;
                cin>>b;
                if(b==0){
                    cout<<"Error, introduzca un numero distinto de cero"<<endl;
                }else{
                    op_inv=0;
                }
            }
            cout<<a/b;
            return 0;
        }
        if(op=='%'){
            while(op_inv){
                cout<<"Debido a que la funcion modulo solo funciona con enteros, los numeros que ingrese se truncaran en caso de no ser enteros."<<endl<<"Introduzca el segundo numero"<<endl;
                cin>>b;
                if(b==0){
                    cout<<"Error, introduzca un numero distinto de cero"<<endl;
                }else{
                    op_inv=0;
                }
            }
            cout<<((int)a)%((int)b);
            return 0;
        }
        cout<<"Error, introduzca una operacion valida (+,-,*,/,'%')"<<endl;
    }

	return 0;
}
