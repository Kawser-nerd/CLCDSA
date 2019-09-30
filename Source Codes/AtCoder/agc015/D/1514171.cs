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
        long A = long.Parse(Console.ReadLine());
        long B = long.Parse(Console.ReadLine());
        if(A == B){
            sb.Append("1\n");
            return;
        }
        int b;
        for(b=63;b>=0;b--){
            if(((((long)1 << b) & A) == 0) && ((((long)1 << b) & B) != 0)){
                long temp = A;
                A = B;
                B = temp;
                break;
            }
            else if(((((long)1 << b) & A) != 0) && ((((long)1 << b) & B) == 0)){
                break;
            }
            else if(((((long)1 << b) & A) != 0) && ((((long)1 << b) & B) != 0)){
                A -= (long)1 << b;
                B -= (long)1 << b;
            }
        }
        long count = ((long)1 << b) - B;
        int c;
        for(c = b-1;c >= 0;c--){
            if(((((long)1 << c) & A) != 0)){
                break;
            }
        }
        long C = ((long)1 << (c+1));
        count += Math.Min((long)1 << b,count + C);
        sb.Append(count+"\n");
    }
}