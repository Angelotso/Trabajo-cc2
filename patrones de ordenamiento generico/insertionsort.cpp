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
class Insertionsort : public Ordenador<T>
{
    public:
        public:
        void ordenar( vector<T> &lista ){
            for( int i = 0; i < lista.size(); i++ ){
                bool insertado = false;
                for( int j = 0; j < i && !insertado; j++ ){
                    if( lista[j] >= lista[i] ){
                        T temp = lista[i];
                        for( int k = i; k >= j+1; k-- ){
                            lista[k] = lista[k-1];
                        }
                        lista[j] = temp;
                        insertado = true;
                    }
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
    Insertionsort<int> inser;
    ord=&inser;
    cout << "**** Array DESORDENADO ****" << endl << "-------------------" << endl;
    vector <int> array {3, 1, 5, 10, 12, 4, 7, 20, 16, 0, 2, 1};
    ord->imprimir(array);
    ordenarArrayEnteros(ord, array);
    cout<<"\n";
    cout << "**** Array ORDENADO ****" << endl << "-------------------" << endl;
    ord->imprimir(array);
    return 0;
}