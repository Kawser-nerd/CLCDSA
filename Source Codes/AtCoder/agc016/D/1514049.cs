using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    long[] Numbers;
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
        long[] A = new long[N+1];
        {
            long xor = 0;
            for(int i=0;i<N;i++){
                A[i] = int.Parse(str[i]);
                xor ^= A[i];
            }
            A[N] = xor;
        }
        str = Console.ReadLine().Split(' ');
        long[] B = new long[N+1];
        {
            long xor = 0;
            for(int i=0;i<N;i++){
                B[i] = int.Parse(str[i]);
                xor ^= B[i];
            }
            B[N] = xor;
        }
        {
            long[] C = new long[N+1];
            long[] D = new long[N+1];
            for(int i=0;i<=N;i++){
                C[i] = A[i];
                D[i] = B[i];
            }
            Array.Sort(C);
            Array.Sort(D);
            bool b = true;
            for(int i=0;i<N;i++){
                b &= C[i] == D[i];
            }
            if(!b){
                sb.Append("-1\n");
                return;
            }
            List<long> numbers = new List<long>();
            for(int i=0;i<=N;i++){
                if(i == 0 || C[i] != C[i-1]){
                    numbers.Add(C[i]);
                }
            }
            Numbers = numbers.ToArray();
        }
        int S = Numbers.Length;
        UnionFind U = new UnionFind(S);
        int count = 0;
        for(int i=0;i<=N;i++){
            if(A[i] != B[i]){
                count++;
                U.Union(ToIndex(A[i]),ToIndex(B[i]));
            }
        }
        int[] UC = new int[S];
        for(int i=0;i<S;i++){
            UC[U.Get(i)]++;
            if(UC[U.Get(i)] == 2){
                count++;
            }
        }
        if(A[N] != B[N]){
            count -= 2;
        }
        else if(UC[U.Get(ToIndex(A[N]))] >= 2){
            count--;
        }
        sb.Append(count+"\n");
    }
    int ToIndex(long X){
        int bf = 0;
        int bl = Numbers.Length-1;
        while(bf != bl){
            int bc = (bf+bl)/2;
            if(X <= Numbers[bc]){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        return bf;
    }
}
class UnionFind{
    int[] par;
    public UnionFind(int n){
        par = new int[n];
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    public void Union(int x,int y){
        par[Get(x)] = Get(y); 
    }
    public bool Same(int x,int y){
        return Get(x) == Get(y);
    }
    public int Get(int x){
        if(x != par[x]){
            par[x] = Get(par[x]);
        }
        return par[x];
    }
}