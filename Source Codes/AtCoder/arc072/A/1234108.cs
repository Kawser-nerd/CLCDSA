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
        string[] str = Console.ReadLine().Split(' ');
        long[] A;
        A = new long[N];
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        long ans;
        long sum = 0;
        long count = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(i % 2 == 0){
                if(sum <= 0){
                    count += 1-sum;
                    sum = 1;
                }
            }
            else{
                if(sum >= 0){
                    count += sum+1;
                    sum = -1;
                }
            }
        }
        ans = count;
        sum = 0;
        count = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(i % 2 != 0){
                if(sum <= 0){
                    count += 1-sum;
                    sum = 1;
                }
            }
            else{
                if(sum >= 0){
                    count += sum+1;
                    sum = -1;
                }
            }
        }
        ans = Math.Min(ans,count);
        sb.Append(ans+"\n");
    }
}