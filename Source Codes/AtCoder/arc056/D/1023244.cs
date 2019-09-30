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
        long[] W = new long[N];
        string[] str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            W[i] = int.Parse(str[i]);
        }
        const int T = 500001;
        List<int>[] t = new List<int>[T];
        for(int i=0;i<T;i++){
            t[i] = new List<int>();
        }
        List<int>[] d = new List<int>[N];
        for(int i=0;i<N;i++){
            d[i] = new List<int>();
        }
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            int M = int.Parse(str[0]);
            for(int j=1;j<=M;j++){
                t[int.Parse(str[j])/2].Add(i);
                d[i].Add(int.Parse(str[j])/2);
            }
        }
        int[] c = new int[N];
        BitTree B = new BitTree(T);
        B.Set(0,0);
        long max = 0;
        long g = 0;
        for(int i=1;i<T;i++){
            if(t[i].Count == 0){
                B.Set(g,i);
                continue;
            }
            for(int j=0;j<t[i].Count;j++){
                if(c[t[i][j]] == 0){
                    B.Add(0,i-1,W[t[i][j]]);
                }
                else{
                    B.Add(d[t[i][j]][c[t[i][j]]-1],i-1,W[t[i][j]]);
                }
                c[t[i][j]]++;
            }
            g = B.Get(0,i-1);
            max = max > g ? max : g;
            B.Set(g,i);
        }
        max = max > B.Get(0,T-1) ? max : B.Get(0,T-1);
        sb.Append(max+"\n");
    }
}
class Tree{
    public long c;
    public long m;
    public Tree left;
    public Tree right;
    public int max;
    public int min;
    public Tree(int min0,int max0){
        max = max0;
        min = min0;
        c = 0;
        m = -1000000000000000000;
    }
}
class BitTree{
    Tree[] trees;
    Tree top;
    public BitTree(int n){
        trees = new Tree[n];
        top = new Tree(0,n-1);
        MakeChild(top);
    }
    void MakeChild(Tree t){
        if(t.max == t.min){
            trees[t.max] = t;
        }
        else{
            t.left = new Tree(t.min,(t.min+t.max)/2);
            t.right = new Tree((t.min+t.max)/2+1,t.max);
            MakeChild(t.left);
            MakeChild(t.right);
        }
    }
    long GetTree(Tree t,int min,int max){
        if(t.min == min && t.max == max){
            return t.m;
        }
        else if(min > (t.min+t.max)/2){
            return GetTree(t.right,min,max);
        }
        else if(max <= (t.min+t.max)/2){
            return GetTree(t.left,min,max);
        }
        else{
            long i = GetTree(t.left,min,(t.min+t.max)/2);
            long j = GetTree(t.right,(t.min+t.max)/2+1,max);
            return i > j ? i + t.c : j + t.c;
        }
    }
    void SetTree(Tree t,long i,int j){
        t.m = t.m > i ? t.m : i;
        if(t.min == t.max){
            ;
        }
        else if(j > (t.min+t.max)/2){
            SetTree(t.right,i,j);
        }
        else{
            SetTree(t.left,i,j);
        }
    }
    void AddTree(Tree t,int min,int max,long c){
        if(t.min == min && t.max == max){
            t.c += c;
            t.m += c;
        }
        else if(min > (t.min+t.max)/2){
            AddTree(t.right,min,max,c);
            t.m = t.left.m > t.right.m ? t.left.m + t.c : t.right.m + t.c;
        }
        else if(max <= (t.min+t.max)/2){
            AddTree(t.left,min,max,c);
            t.m = t.left.m > t.right.m ? t.left.m + t.c : t.right.m + t.c;
        }
        else{
            AddTree(t.left,min,(t.min+t.max)/2,c);
            AddTree(t.right,(t.min+t.max)/2+1,max,c);
            t.m = t.left.m > t.right.m ? t.left.m + t.c : t.right.m + t.c;
        }
    }
    public long Get(int min,int max){
        return GetTree(top,min,max);
    }
    public void Set(long i,int p){
        SetTree(top,i,p);
    }
    public void Add(int i,int p,long c){
        AddTree(top,i,p,c);
    }
}