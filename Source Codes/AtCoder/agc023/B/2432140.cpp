#include <iostream>
#include <vector>

using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector < vector < char > > array;
    array = vector < vector<char> > (2*N,vector<char>(2*N,0));
    for (int i = 0; i < N;i++) {
        for (int j = 0; j < N;j++) {
            cin >> array[i][j];
            array[i + N][j] = array[i][j];
            array[i][j + N] = array[i][j];
            array[i + N][j + N] = array[i][j];
        }
    }



    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int found = 0;
        for (int row = 0; row < N; row++)
        {
            for (int col = row + 1; col < N; col++)
            {
                //cout << array[row][col + i] << array[col][row + i] << endl;
                if (array[row][col + i] != array[col][row + i])
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1){
                break;
            }
        }
        if (found == 0){
            count += 1;
        }
    }
    cout << count * N << endl;
}