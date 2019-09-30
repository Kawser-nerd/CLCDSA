using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        string S = Console.ReadLine();
        int N = S.Length;
        int[,] D = new int[N+1,26];
        int[] DM = new int[N+1];
        for(int i=0;i<26;i++){
            D[N,i] = N;
        }
        DM[N] = N;
        for(int i=N-1;i>=0;i--){
            int max = 0;
            for(int j=0;j<26;j++){
                if((S[i] - 'a') == j){
                    D[i,j] = i;
                }
                else{
                    D[i,j] = D[i+1,j];
                }
                max = Math.Max(max,D[i,j]);
            }
            DM[i] = max;
        }
        int[] A = new int[N+2];
        for(int i=N-1;i>=0;i--){
            if(DM[i] == N){
                A[i] = 1;
            }
            else if(DM[i] == N-1){
                A[i] = 2;
            }
            else{
                A[i] = A[DM[i]+1]+1;
            }
        }
        A[N] = -1;
        int L = A[0];
        int count = L;
        int p = 0;
        for(int i=0;i<L;i++){
            for(int j=0;j<26;j++){
                bool b = false;
                if(D[p,j] == N){
                    b = true;
                }
                else if(D[p,j] == N-1 && count == 2){
                    b = true;
                }
                else if(A[D[p,j]+1]+1 == count){
                    b = true;
                }
                if(b){
                    p = D[p,j]+1;
                    sb.Append((char)('a'+j));
                    count--;
                    break;
                }
            }
        }
        sb.Append("\n");
    }
}