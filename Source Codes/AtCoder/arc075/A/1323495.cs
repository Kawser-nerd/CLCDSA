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
        long min = 100000000;
        long sum = 0;
        for(int i=0;i<N;i++){
            int S = int.Parse(Console.ReadLine());
            if(S % 10 != 0){
                min = Math.Min(min,S);
            }
            sum += S;
        }
        long count;
        if(sum % 10 == 0){
            if(min == 100000000){
                count = 0;
            }
            else{
                count = sum - min;
            }
        }
        else{
            count = sum;
        }
        sb.Append(count+"\n");
    }
}