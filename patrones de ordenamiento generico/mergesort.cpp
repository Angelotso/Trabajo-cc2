#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class Ordenador {

    public:
        virtual void ordenar( vector<T> &arr ) = 0;
        void imprimir( vector<T> &lista ){
            cout << "[";
            int i = 0;
            for( T elem: lista  ){
                cout << elem << ( i < lista.size() -1 ? ", " : " " );                
                i++;
            }
            cout << "]" << endl;
        }
};

template <typename T>
class MergeSort: public Ordenador<T>{
    
    void ordenar( vector<T> &lista ){
        this->ordenar( lista, 0, lista.size()-1 );
    }
    void ordenar( vector<T> &lista, int posIni, int posFin ){
        if( posIni < posFin ){
            // Ordenamos la parte izq. y derecha del array
            int posCentral = (posIni+posFin)/2;
            this->ordenar( lista, posIni, posCentral );
            this->ordenar( lista, posCentral+1, posFin );
            
            // Mezclamos
            int i = posIni, j = posCentral+1;
            while( i <= posCentral && j <= posFin ){
                if( lista[j] < lista[i] ){
                    T temp = lista[i];
                    lista[i] = lista[j];
                    int k = j;
                    for(; k <= posFin; k++ ){
                        if( temp > lista[k] ){
                            lista[k] = lista[k+1];
                        } else{
                            break;
                        }
                    }
                    lista[k-1] = temp;
                }
                i++;
            }
        }
    }
};
void ordenarArrayEnteros( Ordenador<int>* ordenador, vector<int> &vec ){
    ordenador->ordenar(vec);
}
int main()
{
    Ordenador<int> *ord;
    MergeSort<int> merge;
    ord=&merge;
    cout << "**** Array DESORDENADO ***" << endl << "-------------------" << endl;
    vector <int> array {9, 1, 5, 12, 55, 4, 7, 20, 16, 0, 2, 17};
    ord->imprimir(array);
    ordenarArrayEnteros(ord, array);
    cout<<"\n";
    cout << "**** Array ORDENADO ****" << endl << "-------------------" << endl;
    ord->imprimir(array);
    return 0;
}