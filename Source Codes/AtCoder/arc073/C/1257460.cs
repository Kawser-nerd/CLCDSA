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
        int N = int.Parse(Console.ReadLine());
        long[] X = new long[N];
        long[] Y = new long[N];
        long maxY = 0;
        long minY = 1000000000;
        for(int i=0;i<N;i++){
            string[] str = Console.ReadLine().Split(' ');
            long x = int.Parse(str[0]);
            long y = int.Parse(str[1]);
            if(x > y){
                long t = y;
                y = x;
                x = t;
            }
            X[i] = x;
            Y[i] = y;
            maxY = Math.Max(maxY,y);
            minY = Math.Min(minY,y);
        }
        Array.Sort(X,Y);
        long count = (X[N-1]-X[0])*(maxY-minY);
        long M = X[N-1];
        long m = Y[0];
        for(int i=0;i<N;i++){
            count = Math.Min(count,(maxY-X[0])*(M-Math.Min(X[i],m)));
            m = Math.Min(m,Y[i]);
            M = Math.Max(M,Y[i]);
        }
        sb.Append(count+"\n");
    }
}