#include <iostream>
#define P 5
#define R 3

using namespace std;

void calcula_necessidade(int necessita[P][R], int max[][R], int alloc[][R]){
    for(int i = 0; i < P; i++){
        for(int j = 0; j < R; j++){
            necessita[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

bool eh_seguro(int processos[], int aval[], int max[][R], int alloc[][R]){
    int necessita[P][R];

    calcula_necessidade(necessita, max, alloc);

    bool final[P] ={0};

    int seqSegura[P];

    int job[R];

    for(int i = 0; i < R; i++){
        job[i] = aval[i];
    }

    int count = 0;

    while(count < P){

        bool achou = false;

        for(int p = 0; p < P; p++){
            if(final[p] == 0){
                int j;
                for(j = 0; j < R; j++){
                    if(necessita[p][j] > job[j]){
                        break;
                    }
                }
                if(j == R){
                    for(int k = 0; k < R; k++){
                        job[k] = alloc[p][k];
                    }

                    seqSegura[count++] = p;

                    final[p] = true;

                    achou = true;
                }
            }
        }

        if (!achou){
            cout << "O sistema nao esta em estado seguro\n";
            return false;
        }
    }

    cout << "O sistema esta em estado seguro.\n Seguro:";

    for(int i = 0 ; i < P; i++){
        cout << seqSegura[i] << " ";
    }

    return true;
}


int main() {
    int processos[] = {0, 1, 2, 3, 4};
    int aval[] = {3, 3, 2};

    int max[][R] = {
                    {7, 5, 3},
                    {3, 2, 2},
                    {9, 0, 2},
                    {2, 2, 2},
                    {4, 3, 3}
                   };
    int alloc[][R] = {{0, 1, 0},
                      {2, 0, 0},
                      {3, 0, 2},
                      {2, 1, 1},
                      {0, 0, 2}};

    eh_seguro(processos, aval, max, alloc);
    return 0;
}