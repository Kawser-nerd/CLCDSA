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
        long N = long.Parse(Console.ReadLine());
        List<int> act = new List<int>();
        N++;
        while(N > 1){
            if(N % 2 == 0){
                act.Add(2);
                N /= 2;
            }
            else{
                act.Add(1);
                N--;
            }
        }
        List<int> left = new List<int>();
        List<int> right = new List<int>();
        int count = 1;
        for(int i=act.Count-1;i>=0;i--){
            if(act[i] == 1){
                left.Add(count);
            }
            else{
                right.Add(count);
            }
            count++;
        }
        sb.Append((count*2-2)+"\n");
        for(int i=0;i<count-1;i++){
            sb.Append((i+1)+" ");
        }
        for(int i=left.Count-1;i>=0;i--){
            sb.Append(left[i]+" ");
        }
        for(int i=0;i<right.Count;i++){
            sb.Append(right[i]+" ");
        }
        sb.Append("\n");
    }
}