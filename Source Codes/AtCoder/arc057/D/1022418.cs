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
        Divisor D = new Divisor(N);
        int j = 0;
        D.vs[N-1][0].dp = 1;
        for(int i=0;i<N-1;i++){
            int next = int.Parse(Console.ReadLine());
            for(;j<next-1;j++){
                for(int k=0;k<D.vs[N-i-1].Count;k++){
                    Vertex v = D.vs[N-i-1][k];
                    v.dp = v.dp*(v.siden-j)%Define.mod;
                }
            }
            for(int k=0;k<D.vs[N-i-1].Count;k++){
                Vertex v = D.vs[N-i-1][k];
                for(int l=0;l<v.Link.Count;l++){
                    v.Link[l].dp = (v.Link[l].dp + (v.LinkN[l]*v.dp%Define.mod)) % Define.mod;
                }
            }
            j++;
        }
        for(;j<N*(N-1)/2;j++){
            Vertex v = D.vs[0][0];
            v.dp = v.dp*(v.siden-j)%Define.mod;
        }
        sb.Append(D.vs[0][0].dp+"\n");
    }
}
class Tree{
    public List<Tree> child;
    public Vertex v;
    public Divisor D;
    public Tree(int n,int l,Divisor d){
        child = new List<Tree>();
        if(l != n){
            for(int i = n == 0 ? 1 : n;i<=l-n;i++){
                child.Add(new Tree(i,l-n,d));
            }
        }
        else{
            v = new Vertex();
            D = d;
        }
    }
    public void Make(int[] a,int b){
        int[] c = new int[a.Length+(b == 0 ? 0 : 1)];
        for(int i=0;i<a.Length;i++){
            c[i] = a[i];
        }
        if(b != 0){
            c[a.Length] = b; 
        }
        if(v == null){
            for(int i=0;i<child.Count;i++){
                child[i].Make(c,b == 0 ? i + 1 : b + i);
            }    
        }
        else{
            D.MakeTree(v,c);
        }
    }
}
class Vertex{
    public List<Vertex> Link;
    public List<long> LinkN;
    public long dp;
    public long siden;
    public Vertex(){
        Link = new List<Vertex>();
        LinkN = new List<long>();
        dp = 0;
    }
}
class Divisor{
    Tree top;
    public List<Vertex>[] vs;
    public Divisor(int n){
        vs = new List<Vertex>[n];
        for(int i=0;i<n;i++){
            vs[i] = new List<Vertex>();
        }
        top = new Tree(0,n,this);
        top.Make(new int[0],0);
    }
    public void MakeTree(Vertex v,int[] c){
        List<int> kind = new List<int>();
        List<int> num = new List<int>();
        vs[c.Length-1].Add(v);
        int l = c[0];
        int count = 0;
        for(int i=0;i<c.Length;i++){
            count += c[i]*(c[i]-1)/2;
        }
        v.siden = count;
        count = 1;
        for(int i=1;i<c.Length;i++){
            if(l == c[i]){
                count++;
            }
            else{
                kind.Add(l);
                num.Add(count);
                l = c[i];
                count = 1;
            }
        }
        kind.Add(l);
        num.Add(count);
        for(int i=0;i<kind.Count;i++){
            if(num[i] != 1){
                int[] ci = new int[c.Length-1];
                int j = 0;
                int k = 0;
                while(k < i){
                    for(int loop=0;loop<num[k];loop++,j++){
                        ci[j] = kind[k];
                    }
                    k++;
                }
                for(int loop=0;loop<num[k]-2;loop++,j++){
                    ci[j] = kind[k];
                }
                k++;
                while(k != kind.Count && kind[k] < kind[i]*2){
                    for(int loop=0;loop<num[k];loop++,j++){
                        ci[j] = kind[k];
                    }
                    k++;
                }
                ci[j] = kind[i]*2;
                j++;
                while(k != kind.Count){
                    for(int loop=0;loop<num[k];loop++,j++){
                        ci[j] = kind[k];
                    }
                    k++;
                }
                v.Link.Add(Get(ci));
                v.LinkN.Add(num[i]*(num[i]-1)/2*kind[i]*kind[i]);
            }
        }
        for(int i=0;i<kind.Count;i++){
            for(int r=i+1;r<kind.Count;r++){
                int[] ci = new int[c.Length-1];
                int j = 0;
                int k = 0;
                while(k < i){
                    for(int loop=0;loop<num[k];loop++,j++){
                        ci[j] = kind[k];
                    }
                    k++;
                }
                for(int loop=0;loop<num[k]-1;loop++,j++){
                    ci[j] = kind[k];
                }
                k++;
                while(k < r){
                    for(int loop=0;loop<num[k];loop++,j++){
                        ci[j] = kind[k];
                    }
                    k++;
                }
                for(int loop=0;loop<num[k]-1;loop++,j++){
                    ci[j] = kind[k];
                }
                k++;
                while(k != kind.Count && kind[k] < kind[i]+kind[r]){
                    for(int loop=0;loop<num[k];loop++,j++){
                        ci[j] = kind[k];
                    }
                    k++;
                }
                ci[j] = kind[i]+kind[r];
                j++;
                while(k != kind.Count){
                    for(int loop=0;loop<num[k];loop++,j++){
                        ci[j] = kind[k];
                    }
                    k++;
                }
                v.Link.Add(Get(ci));
                v.LinkN.Add(num[i]*num[r]*kind[i]*kind[r]);
            }
        }
    }
    public Vertex Get(int[] a){
        Tree t = top.child[a[0]-1];
        for(int i=1;i<a.Length;i++){
            t = t.child[a[i]-a[i-1]];
        }
        return t.v;
    }
}
public static class Define{
    public const long mod = 1000000007;
}