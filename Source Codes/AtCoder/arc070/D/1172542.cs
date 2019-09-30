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
        Console.WriteLine(sb.ToString());
    }
    void Calc(){
        string[] str = Console.ReadLine().Split(' ');
        int A = int.Parse(str[0]);
        int B = int.Parse(str[1]);
        if(A <= B){
            sb.Append("Impossible");
        }
        else{
            int N = A + B;
            int[] stack = new int[N];
            int count = B;
            int sp = 0;
            int p = 0;
            while(sp <= count){
                if(sp == 0){
                    stack[0] = p;
                    sp++;
                    p++;
                }
                else{
                    Console.WriteLine("? "+stack[sp-1]+" "+p);
                    string s = Console.ReadLine();
                    if(s[0] == 'N'){
                        sp--;
                        count--;
                        p++;
                    }
                    else{
                        stack[sp] = p;
                        sp++;
                        p++;
                    }
                }
            }
            int t = sp == 0 ? p : stack[sp-1];
            sb.Append("! ");
            for(int i=0;i<N;i++){
                if(i == t){
                    sb.Append("1");
                }
                else{
                    Console.WriteLine("? "+t+" "+i);
                    string s = Console.ReadLine();
                    sb.Append(s[0] == 'N' ? "0" : "1");
                }
            }
        }
    }
}