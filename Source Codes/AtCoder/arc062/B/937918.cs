using System;
using System.Collections.Generic;
class Solve{
    string s;
    int N;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int p = N/2;
        int c = 0;
        for(int i=0;i<N;i++){
            if(s[i] == 'p'){
                c++;
            }
        }
        Console.WriteLine(p-c);
    }
    void getinput(){
        s = Console.ReadLine();
        N = s.Length;
    }    
}