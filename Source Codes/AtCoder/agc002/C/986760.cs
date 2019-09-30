using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    long[] a;
    long L;
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
        int c = -1;
        for(int i=0;i<N-1;i++){
            if(a[i]+a[i+1] >= L){
                c = i+1;
            }
        }
        if(c == -1){
            sb.Append("Impossible\n");
        }
        else{
            sb.Append("Possible\n");
            int i=1;
            while(i<c){
                sb.Append(i+"\n");
                i++;
            }
            i=N-1;
            while(i>c){
                sb.Append(i+"\n");
                i--;
            }
            sb.Append(c+"\n");
        }
    }
    void Read(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        L = Int64.Parse(str[1]);
        a = new long[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            a[i] = int.Parse(str[i]);
        }
    }    
}