using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int[] W,H;
    int N;
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Read();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int[] a = new int[N];
        for(int i=0;i<N;i++){
            a[i] = i;
        }
        Array.Sort(a,(x,y) => H[y]-H[x] > 0 ? 1 : (H[y]-H[x] < 0 ? -1 : (W[x] - W[y])));
        BitTree B = new BitTree(100000);
        int max = 0;
        for(int i=0;i<N;i++){
            int g = B.Get(W[a[i]]);
            max = max < g ? g : max;
            B.Set(W[a[i]],g+1);
        }
        sb.Append(max+"\n");
    }
    void Read(){
        N = int.Parse(Console.ReadLine());
        string[] str;
        W = new int[N];
        H = new int[N];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            W[i] = int.Parse(str[0]);
            H[i] = int.Parse(str[1]);
        }
    }    
}
class Tree{
    public int i;
    public Tree left;
    public Tree right;
    public int max;
    public int min;
    public int v;
    public Tree(int min0,int max0){
        max = max0;
        min = min0;
        v = 1;
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
    public void MakeChild(Tree t){
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
    public int GetTree(Tree t,int i){
        if(t.max == t.min){
            return t.v;
        }
        else if(i > (t.min+t.max)/2){
            int j = GetTree(t.right,i);
            return j > t.v ? j : t.v;
        }
        else{
            int j = GetTree(t.left,i);
            return j > t.v ? j : t.v;
        }
    }
    public void SetTree(Tree t,int i,int j){
        if(t.max == t.min){
            t.v = t.v > j ? t.v : j;
        }
        else if(i <= (t.min+t.max)/2+1){
            SetTree(t.left,i,j);
        }
        else{
            t.left.v = t.left.v > j ? t.left.v : j; 
            SetTree(t.right,i,j);
        }
    }
    public int Get(int i){
        return GetTree(top,i);
    }
    public void Set(int i,int p){
        SetTree(top,i,p);
    }
}