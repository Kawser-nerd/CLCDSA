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
        int state;
        int count = 0;
        if(s[0] == 'B'){
            state = 1;
        }
        else{
            state = 0;
        }
        for(int i=1;i<s.Length;i++){
            if((state == 0 && s[i] == 'B') || (state == 1 && s[i] != 'B')){
                count++;
            }
            if(s[i] == 'B'){
                state = 1;
            }
            else{
                state = 0;
            }
        }
        Console.WriteLine(count);
    }
    void getinput(){
        s = Console.ReadLine();
    }    
}