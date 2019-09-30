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
        long[] h = new long[N];
        for(int i=0;i<N;i++){
            h[i] = int.Parse(Console.ReadLine());
        }
        long bf = 0;
        long bl = 10000000000;
        while(bf != bl){
            long bc = (bf+bl)/2;
            bool b;
            {
                long count = 0;
                for(int i=0;i<N;i++){
                    if(h[i] > B*bc){
                        count += (h[i] - B*bc - 1)/(A-B)+1;
                    }
                }
                b = count <= bc;
            }
            if(b){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        sb.Append(bf+"\n");
    }
}