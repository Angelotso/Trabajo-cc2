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


template<typename T>
class Quicksort: public Ordenador<T>{
    void ordenar( vector<T> &lista ){
        ordenar( lista, 0, lista.size()-1 );
    }
    
    void ordenar( vector<T> &lista, int posIni, int posFin ){
        if( posIni < posFin ){
            int posPivote = (posIni+posFin)/2; // Cogemos el del medio
            int i = posIni, j = posFin;
            T pivote = lista[posPivote];
            i = posPivote+1;
            while( i <= posFin ){
                if( lista[i] <= pivote ){
                    lista[posPivote] = lista[i];                  
                    lista[i] = lista[posPivote+1];                 
                    lista[posPivote+1] = pivote;
                    posPivote++;
                }
                i++;
            }
            j = posPivote-1;
            while( j >= posIni ){
                if( lista[j] > pivote ){
                    lista[posPivote] = lista[j];
                    lista[j] = lista[posPivote-1];
                    lista[posPivote-1] = pivote;
                    posPivote--;
                }
                j--;
            }
            // Ordenamos el array izquierdo del pivote
            this->ordenar( lista, posIni, posPivote-1 );
            // Ordenamos el array derecho del pivote
            this->ordenar( lista, posPivote+1, posFin );
        }
        
    }
};
void ordenarArrayEnteros( Ordenador<int>* ordenador, vector<int> &vec ){
    ordenador->ordenar(vec);
}
int main()
{
    Ordenador<int> *ord;
    Quicksort<int> quick;
    ord = &quick;
    cout << "**** Array DESORDENADO ***" << endl << "-------------------" << endl;
    vector <int> array {7, 1, 33, 11, 10, 4, 7, 5, 16, 0, 2, 19};
    ord->imprimir(array);
    ordenarArrayEnteros(ord, array);
    cout<<"\n";
    cout << "**** Array ORDENADO ****" << endl << "-------------------" << endl;
    ord->imprimir(array);
    return 0;
}