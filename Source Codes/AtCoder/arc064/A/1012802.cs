using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    long x;
    long[] a;
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
        long count = 0;
        if(a[0] > x){
            count += a[0]-x;
            a[0] = x;
        }
        for(int i=0;i<N-1;i++){
            if(a[i]+a[i+1] > x){
                count += a[i]+a[i+1]-x;
                a[i+1] = x-a[i];
            }
        }
        sb.Append(count+"\n");
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        x = Int64.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        a = new long[N];
        for(int i=0;i<N;i++){
            a[i] = Int64.Parse(str[i]);
        }
    }    
}