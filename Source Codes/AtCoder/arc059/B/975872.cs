using System;
using System.Collections.Generic;
class Solve{
    string s;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        for(int i=0;i<s.Length-1;i++){
            if(i != s.Length-2 && s[i] == s[i+2]){
                Console.Write(i+1);
                Console.Write(" ");
                Console.WriteLine(i+3);
                return;
            }
            if(s[i] == s[i+1]){
                Console.Write(i+1);
                Console.Write(" ");
                Console.WriteLine(i+2);
                return;
            }
        }
        Console.WriteLine("-1 -1");
    }
    void getinput(){
        s = Console.ReadLine();
    }    
}