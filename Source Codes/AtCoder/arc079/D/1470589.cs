using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    int N;
    int[] grundy;
    int[] W;
    List<int>[] G;
    int[] D;
    int[] A;
    bool[] b;
    int count;
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
        N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        W = new int[N+1];
        count = 0;
        A = new int[N];
        D = new int[N];
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i])-1;
        }
        G = new List<int>[N];
        for(int i=0;i<N;i++){
            G[i] = new List<int>();
        }
        for(int i=0;i<N;i++){
            G[A[i]].Add(i);
            D[A[i]]++;
        }
        grundy = new int[N];
        b = new bool[N];
        for(int i=0;i<N;i++){
            if(!b[i] && D[i] == 0){
                Calc(i);
            }
        }
        for(int v=0;v<N;v++){
            if(!b[v]){
                for(int i=0;i<G[v].Count;i++){
                    if(b[G[v][i]]){
                        W[grundy[G[v][i]]] = count;
                    }
                }
                int c = 0;
                for(int i=0;i<=N;i++){
                    if(W[i] != count){
                        c = i;
                        break;
                    }
                }
                count++;
                grundy[v] = c;
                if(Calc2(A[v],v) != grundy[v]){
                    sb.Append("POSSIBLE\n");
                    return;
                }
                int original = grundy[v];
                for(int i=0;i<G[v].Count;i++){
                    if(b[G[v][i]]){
                        W[grundy[G[v][i]]] = count;
                    }
                }
                c++;
                for(int i=c;i<=N;i++){
                    if(W[i] != count){
                        c = i;
                        break;
                    }
                }
                count++;
                grundy[v] = c;
                if(Calc2(A[v],v) == original){
                    sb.Append("POSSIBLE\n");
                    return;
                }
                break;
            }
        }
        sb.Append("IMPOSSIBLE\n");
    }
    int Calc2(int v,int f){
        for(int i=0;i<G[v].Count;i++){
            W[grundy[G[v][i]]] = count;
        }
        for(int i=0;i<=N;i++){
            if(W[i] != count){
                grundy[v] = i;
                break;
            }
        }
        count++;
        if(A[v] == f){
            return grundy[v];
        }
        else{
            return Calc2(A[v],f);
        }
    }
    void Calc(int v){
        for(int i=0;i<G[v].Count;i++){
            W[grundy[G[v][i]]] = count;
        }
        for(int i=0;i<=N;i++){
            if(W[i] != count){
                grundy[v] = i;
                break;
            }
        }
        count++;
        b[v] = true;
        D[A[v]]--;
        if(D[A[v]] == 0){
            Calc(A[v]);
        }
    }
}
class Heap{
    public int size;
    int[] obj;
    public Heap(int maxsize){
        size = 0;
        obj = new int[maxsize];
    }
    public bool Compare(int a,int b){
        return a<=b;
    }
    public void push(int a){
        int i = size;
        size++;
        while(i > 0){
            int p = (i - 1)/2;
            if(Compare(obj[p],a)){
                obj[i] = a;
                break;
            }
            obj[i] = obj[p];
            i = p;
        }
        if(i == 0){
            obj[0] = a;
        }
    }
    public int pop(){
        int t = obj[0];
        int i = 0;
        size--;
        while(2*i+1 < size){
            int p = 2*i+1;
            if(p+1 < size && Compare(obj[p+1],obj[p])){
                p++;
            }
            if(Compare(obj[p],obj[size])){
                obj[i] = obj[p];
                i = p;
            }
            else{
                obj[i] = obj[size];
                break;
            }
        }
        if(2*i+1 >= size){
            obj[i] = obj[size];
        }
        return t;
    }
}