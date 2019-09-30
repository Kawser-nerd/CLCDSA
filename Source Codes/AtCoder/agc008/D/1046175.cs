using System;
using System.Text;
using System.Collections.Generic;
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
        int N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] X = new int[N];
        for(int i=0;i<N;i++){
            X[i] = int.Parse(str[i]);
        }
        int[] a = new int[N];
        for(int i=0;i<N;i++){
            a[i] = i;
        }
        Array.Sort(a,(x,y) => X[x]-X[y]);
        int[] L = new int[N];
        for(int i=0;i<N;i++){
            L[i] = N;
        }
        int[] Y = new int[N*N];
        bool[] finished = new bool[N*N];
        int p = 0;
        bool b = true;
        for(int i=0;i<N;i++){
            int d = a[i] + 1;
            finished[X[a[i]]-1] = true;
            Y[X[a[i]]-1] = a[i] + 1;
            L[a[i]] -= a[i] + 1; 
            for(int j=0;j<a[i];j++){
                while(p < N*N && finished[p]){
                    p++;
                }
                Y[p] = d;
                p++;
                if(p > X[a[i]] - 1){
                    b = false;
                }
            }
        }
        int q = 0;
        for(;p<N*N;p++){
            if(finished[p]){
                continue;
            }
            while(q < N && L[a[q]] == 0){
                q++;
            }
            if(q == N){
                b = false;
                break;
            }
            else{
                Y[p] = a[q]+1;
                if(p < X[a[q]]){
                    b = false;
                }
                L[a[q]]--;
            }
        }
        if(b){
            sb.Append("Yes\n");
            for(int i=0;i<N*N;i++){
                sb.Append(Y[i]+" ");
            }
            sb.Append("\n");
        }
        else{
            sb.Append("No\n");
        }
    }
}