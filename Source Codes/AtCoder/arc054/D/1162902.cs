using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    long[] rs;
    long Half;
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
        SegTree[] S = new SegTree[N];
        int p = 0;
        rs = new long[100001];
        Half = Rev(2);
        for(int i=0;i<N;i++){
            int x = int.Parse(str[i]);
            if(x > 0){
                S[p] = new SegTree(x);
                p++;
            }
            else if(x == 0){
                S[p-2] = Merge(S[p-2],S[p-1]);
                p--;
            }
            else{
                Multi(S[p-1],-x);
            }
        }
        sb.Append(S[0].c1+"\n");
    }
    long Rev(int i){
        if(rs[i] == 0){
            rs[i] = Pow(i,Define.mod-2);
        }
        return rs[i];
    }
    long Pow(long x,long k){
        if(k == 0){
            return 1;
        }
        else if(k % 2 == 0){
            long t = Pow(x,k/2);
            return t*t%Define.mod;
        }
        else{
            return x*Pow(x,k-1)%Define.mod;
        }
    }
    void Multi(SegTree S,int M){
        S.M = M * S.M % Define.mod;
        S.rM = Rev(M) * S.rM % Define.mod;
        S.c1 = (S.c1*M + S.c2*M%Define.mod*(M-1)%Define.mod*Half)%Define.mod;
        S.c2 = S.c2*M%Define.mod*M%Define.mod;
    }
    SegTree Merge(SegTree F,SegTree T){
        if(F.size >= T.size){
            long FT = T.AddRight(F);
            long TF = T.AddLeft(F);
            F.c1 = (F.c1 + T.c1 + FT) % Define.mod;
            F.c2 = (F.c2 + T.c2 + FT + TF) % Define.mod;
            T.Add(F);
            return F;
        }
        else{
            long FT = F.AddLeft(T);
            long TF = F.AddRight(T);
            T.c1 = (F.c1 + T.c1 + FT) % Define.mod;
            T.c2 = (F.c2 + T.c2 + FT + TF) % Define.mod; 
            F.Add(T);
            return T;
        }
    }
}
public class SegTree{
    public Vertex P;
    public long M;
    public long rM;
    public int size;
    public long c1;
    public long c2;
    public SegTree(int X){
        P = new Vertex();
        M = 1;
        rM = 1;
        size = 1;
        c1 = 0;
        c2 = 0;
        Add(X,1);
    }
    public void Add(int p,long c){
        int depth = 16;
        P.count = (P.count + c) % Define.mod;
        Vertex v;
        for(v=P;depth>=0;depth--){
            if(((1 << depth) & p) == 0){
                if(v.l == null){
                    v.l = new Vertex();
                    size++;
                }
                v = v.l;
            }
            else{
                if(v.r == null){
                    v.r = new Vertex();
                    size++;
                }
                v = v.r;
            }
            v.count = (v.count + c) % Define.mod; 
        }
        v.p = p;
    }
    //S???this?
    public long AddRight(SegTree S){
        return M*S.M%Define.mod*P.AddRight(S)%Define.mod;
    }
    public long AddLeft(SegTree S){
        return M*S.M%Define.mod*P.AddLeft(S)%Define.mod;
    }
    public void Add(SegTree S){
        P.Add(S,M*S.rM%Define.mod);
    }
    public long CalcLess(int p){
        int depth = 16;
        long ans = 0;
        for(Vertex v=P;depth>=0;depth--){
            if(((1 << depth) & p) == 0){
                if(v.l == null){
                    break;
                }
                v = v.l;
            }
            else{
                if(v.l != null){
                    ans = (ans + v.l.count) % Define.mod;
                }
                if(v.r == null){
                    break;
                }
                v = v.r;
            }
        }
        return ans;
    }
    public long CalcMore(int p){
        int depth = 16;
        long ans = 0;
        for(Vertex v=P;depth>=0;depth--){
            if(((1 << depth) & p) == 0){
                if(v.r != null){
                    ans = (ans + v.r.count) % Define.mod;
                }
                if(v.l == null){
                    break;
                }
                v = v.l;
            }
            else{
                if(v.r == null){
                    break;
                }
                v = v.r;
            }
        }
        return ans;
    }
}
public class Vertex{
    public long count;
    public int p;
    public Vertex l;
    public Vertex r;
    public Vertex(){
        count = 0;
    }
    public void Add(SegTree S,long M){
        if(l == null && r == null){
            S.Add(p,count*M%Define.mod);
        }
        if(l != null){
            l.Add(S,M);
        }
        if(r != null){
            r.Add(S,M);
        }
    }
    //S???V
    public long AddRight(SegTree S){
        long ans = 0;
        if(l == null && r == null){
            return count*S.CalcMore(p)%Define.mod;
        }
        if(l != null){
            ans += l.AddRight(S);
        }
        if(r != null){
            ans += r.AddRight(S);
        }
        return ans % Define.mod;
    }
    public long AddLeft(SegTree S){
        long ans = 0;
        if(l == null && r == null){
            return count*S.CalcLess(p)%Define.mod;
        }
        if(r != null){
            ans += r.AddLeft(S);
        }
        if(l != null){
            ans += l.AddLeft(S);
        }
        return ans % Define.mod;
    }
}
public static class Define{
    public const long mod = 1000000007;
}