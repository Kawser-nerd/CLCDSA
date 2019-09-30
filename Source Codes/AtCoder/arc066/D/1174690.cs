using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    int N;
    long[] DPL;
    long[] DPR;
    long[] unuse;
    long[] use;
    long[] sumL;
    long[] sumR;
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
        long[] T = new long[N];
        for(int i=0;i<N;i++){
            T[i] = int.Parse(str[i]);
        }
        DPL = new long[N];
        DPR = new long[N];
        {
            sumL = new long[N];
            sumL[0] = T[0];
            for(int i=1;i<N;i++){
                sumL[i] = sumL[i-1] + T[i];
            }
            ConvexHullTrick Con = new ConvexHullTrick(N+1);
            Con.Add(-1,1);
            for(int i=0;i<N;i++){
                DPL[i] = Math.Max(i == 0 ? 0 : DPL[i-1],Con.Query(-i)-sumL[i]+(long)i*(long)(i+1)/2);
                Con.Add(i,DPL[i]+sumL[i]+(long)i*(long)(i-1)/2);
            }
        }
        {
            sumR = new long[N];
            sumR[0] = T[N-1];
            for(int i=1;i<N;i++){
                sumR[i] = sumR[i-1] + T[N-1-i];
            }
            ConvexHullTrick Con = new ConvexHullTrick(N+1);
            Con.Add(-1,1);
            for(int i=0;i<N;i++){
                DPR[N-1-i] = Math.Max(i == 0 ? 0 : DPR[N-i],Con.Query(-i)-sumR[i]+(long)i*(long)(i+1)/2);
                Con.Add(i,DPR[N-1-i]+sumR[i]+(long)i*(long)(i-1)/2);
            }
        }
        unuse = new long[N];
        for(int i=0;i<N;i++){
            unuse[i] = (i == 0 ? 0 : DPL[i-1]) + (i == N-1 ? 0 : DPR[i+1]);
        } 
        use = new long[N];
        for(int i=0;i<N;i++){
            use[i] = -T[i];
        }
        GetUse(0,N-1);
        int M = int.Parse(Console.ReadLine());
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int P = int.Parse(str[0])-1;
            long X = int.Parse(str[1]);
            sb.Append(Math.Max(unuse[P],use[P]-X+T[P])+"\n");
        }
    }
    ConvexHullTrick ConL(int l,int r){
        ConvexHullTrick Con = new ConvexHullTrick(r-l+1);
        for(int i=l;i<=r;i++){
            if(i == 0){
                Con.Add(-1,1);
            }
            else{
                Con.Add(i-1,DPL[i-1]+sumL[i-1]+(long)(i-1)*(long)(i-2)/2);
            }
        }
        return Con;
    }
    ConvexHullTrick ConR(int l,int r){
        ConvexHullTrick Con = new ConvexHullTrick(r-l+1);
        for(int i=N-1-r;i<N-l;i++){
            if(i == 0){
                Con.Add(-1,1);
            }
            else{
                Con.Add(i-1,DPR[N-i]+sumR[i-1]+(long)(i-1)*(long)(i-2)/2);
            }
        }
        return Con;
    }
    long UseConL(int i){
        return -sumL[i]+(long)i*(long)(i+1)/2;
    }
    long UseConR(int i){
        return -sumR[N-1-i]+(long)(N-1-i)*(long)(N-i)/2;
    }
    void GetUse(int l,int r){
        int M = (l+r)/2;
        if(l <= M-1){
            GetUse(l,M-1);
        }
        if(M+1 <= r){
            GetUse(M+1,r);
        }
        {
            ConvexHullTrick Con = ConL(l,M);
            long max = -1000000000;
            for(int i=r;i>=M;i--){
                max = Math.Max(max,Con.Query(-i)+UseConL(i)+(i == N-1 ? 0 : DPR[i+1]));
                use[i] = Math.Max(max,use[i]);
            }
        }
        {
            ConvexHullTrick Con = ConR(M,r);
            long max = -1000000000;
            for(int i=l;i<=M;i++){
                max = Math.Max(max,Con.Query(-(N-1-i))+UseConR(i)+(i == 0 ? 0 : DPL[i-1]));
                use[i] = Math.Max(max,use[i]);
            }
        }
    }
}
struct ConvexHullTrick{
    long[] A;
    long[] B;
    //C[i]?i???????????i+1????????????????????x ???????
    long[] C;
    int p;
    int find;
    public ConvexHullTrick(int N){
        A = new long[N];
        B = new long[N];
        C = new long[N];
        p = 0;
        find = 0;
    }
    //a?????????????
    public void Add(long a,long b){
        if(p == 0){
            A[0] = a;
            B[0] = b;;
            p++;
        }
        else{
            for(int i=p;i>0;i--){
                long X = Compare(A[i-1],B[i-1],a,b);
                if(i == 1 || X > C[i-2]){
                    C[i-1] = X;
                    A[i] = a;
                    B[i] = b;
                    p = i+1;
                    break;
                }
            }
        }
    }
    //1??Add??????????
    public long Query(long x){
        return Calc(x,findMax(x));
    }
    int findMax(long x){
        find = Math.Min(find,p-1);
        while(find < p-1 && C[find] < x){
            find++;
        }
        while(find > 0 && C[find-1] >= x){
            find--;
        }
        return find;
    }
    long Calc(long x,int i){
        return A[i]*x + B[i];
    }
    //(a1,b1)???????(a2,b2)???????????????x
    long Compare(long a1,long b1,long a2,long b2){
        return (b1-b2-1)/(a2-a1) - ((b1-b2-1)%(a2-a1) < 0 ? 1 : 0);
    }
}