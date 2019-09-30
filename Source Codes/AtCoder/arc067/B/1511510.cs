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
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        long A = int.Parse(str[1]);
        long B = int.Parse(str[2]);
        long[] X = new long[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            X[i] = int.Parse(str[i]);
        }
        long count = 0;
        for(int i=1;i<N;i++){
            long distance = X[i]-X[i-1];
            if(distance*A >= B){
                count += B;
            }
            else{
                count += distance*A;
            }
        }
        sb.Append(count+"\n");
    }
}