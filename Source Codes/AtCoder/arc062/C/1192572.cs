using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    long[] C;
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
        C = new long[N];
        for(int i=0;i<N;i++){
            string[] str = Console.ReadLine().Split(' ');
            C[i] = Square(int.Parse(str[0]),int.Parse(str[1]),int.Parse(str[2]),int.Parse(str[3]));
        }
        Array.Sort(C);
        long count = 0;
        for(int i=0;i<N;i++){
            long X = C[i];
            for(int j=i+1;j<N;j++){
                long Y = C[j];
                long Y0 = Y;
                for(int l=0;l<4;l++){
                    long c = 1;
                    long ax = X/1000000000;
                    long bx = X/1000000%1000;
                    long cx = X/1000%1000;
                    long dx = X%1000;
                    long ay = Y0/1000000000;
                    long by = Y0/1000000%1000;
                    long cy = Y0/1000%1000;
                    long dy = Y0%1000;
                    long C1 = Square(bx,ax,by,ay);
                    long C2 = Square(cx,bx,ay,dy);
                    long C3 = Square(dx,cx,dy,cy);
                    long C4 = Square(ax,dx,cy,by);
                    long cc = Counter(C1);
                    if(X == C1){
                        cc--;
                    }
                    if(Y == C1){
                        cc--;
                    }
                    c *= cc*Roll(C1);
                    cc = Counter(C2);
                    if(X == C2){
                        cc--;
                    }
                    if(Y == C2){
                        cc--;
                    }
                    if(C1 == C2){
                        cc--;
                    }
                    c *= cc*Roll(C2);
                    cc = Counter(C3);
                    if(X == C3){
                        cc--;
                    }
                    if(Y == C3){
                        cc--;
                    }
                    if(C1 == C3){
                        cc--;
                    }
                    if(C2 == C3){
                        cc--;
                    }
                    c *= cc*Roll(C3);
                    cc = Counter(C4);
                    if(X == C4){
                        cc--;
                    }
                    if(Y == C4){
                        cc--;
                    }
                    if(C1 == C4){
                        cc--;
                    }
                    if(C2 == C4){
                        cc--;
                    }
                    if(C3 == C4){
                        cc--;
                    }
                    c *= cc*Roll(C4);
                    count += c;
                    Y0 = Y0/1000000000 + Y0%1000000000*1000;
                }
            }
        }
        sb.Append(count/3+"\n");
    }
    long Roll(long X){
        long Y = X/1000000000 + X%1000000000*1000;
        if(X == Y){
            return 4;
        }
        else{
            long Z = Y/1000000000 + Y%1000000000*1000;
            if(X == Z){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    long Square(long a,long b,long c,long d){
        long X = 1000000000 * a + 1000000 * b + 1000 * c + d;
        long min = X;
        for(int i=0;i<3;i++){
            X = X/1000000000 + X%1000000000*1000;
            min = Math.Min(min,X);
        }
        return min;
    }
    long Counter(long X){
        int bf = 0;
        int bl = C.Length;
        while(bf != bl){
            int bc = (bf+bl)/2;
            if(bc == C.Length || C[bc] >= X){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        int l = bf;
        bf = -1;
        bl = C.Length-1;
        while(bf != bl){
            int bc = (bf+bl+1)/2;
            if(bc == -1 || C[bc] <= X){
                bf = bc;
            }
            else{
                bl = bc-1;
            }
        }
        int r = bf;
        if(l > r){
            return 0;
        }
        else{
            return r - l + 1;
        }
    }
}