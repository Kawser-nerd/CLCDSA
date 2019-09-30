using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    string s;
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
        if((s[0] == s[s.Length-1] && s.Length % 2 == 0) || (s[0] != s[s.Length-1] && s.Length % 2 == 1)){
            sb.Append("First\n");
        }
        else{
            sb.Append("Second\n");
        }
    }
    void Read(){
        s = Console.ReadLine();
    }    
}