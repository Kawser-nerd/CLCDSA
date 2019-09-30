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
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        int[,] A = new int[N,M];
        int[,] B = new int[N,M];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            for(int j=0;j<M;j++){
                B[i,j] = int.Parse(str[j]) - 1;
                A[i,int.Parse(str[j])-1] = j;
            }
        }
        int bf = 1;
        int bl = N;
        while(bf != bl){
            int bc = (bf+bl)/2;
            bool b = true;
            {
                int[] X = new int[M];
                int[] Chosen = new int[N];
                int[] stack = new int[2*N];
                int p = 0;
                for(int i=0;i<N;i++){
                    X[B[i,0]]++;
                    if(X[B[i,0]] == bc+1){
                        stack[p] = B[i,0];
                        p++;
                    }
                }
                bool[] deleted = new bool[M];
                while(b && p != 0){
                    int C = stack[p-1];
                    p--;
                    deleted[C] = true;
                    for(int i=0;i<N;i++){
                        if(Chosen[i] == A[i,C]){
                            while(Chosen[i] <= M-1 && deleted[B[i,Chosen[i]]]){
                                Chosen[i]++;
                            }
                            if(Chosen[i] == M){
                                b = false;
                                break;
                            }
                            else{
                                X[B[i,Chosen[i]]]++;
                                if(X[B[i,Chosen[i]]] == bc+1){
                                    stack[p] = B[i,Chosen[i]];
                                    p++;
                                }
                            }
                        }
                    }
                }
            }
            if(b){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        sb.Append(bf+"\n");
    }
}