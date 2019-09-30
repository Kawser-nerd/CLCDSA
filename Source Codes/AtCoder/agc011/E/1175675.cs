using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int[] Number;
    string s;
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
        s = Console.ReadLine();
        Number = new int[s.Length+1];
        {
            int d = 0;
            for(int i=0;i<s.Length;i++){
                d += 9*(s[s.Length-1-i]-'0');
                Number[i] = d % 10;
                d /= 10;
            }
            Number[s.Length] = d;
        }
        int count = 0;
        for(int i=s.Length;i>0;i--){
            int d = Number[i];
            count += d;
            Number[i] = 0;
            Plus(d);
            if(Number[i] == 1){
                if(Number[0] == 8){
                    count -= d-1;
                    break;
                }
                else{
                    Plus(1);
                    count++;
                    Number[i] = 0;
                }
            }
        }
        if(Number[0] == 9){
            count++;
        }
        sb.Append((count+8)/9+"\n");
    }
    void Plus(int N){
        int d = N;
        for(int i=0;i<s.Length+1;i++){
            d += Number[i];
            Number[i] = d % 10;
            d /= 10;
            if(d == 0){
                break;
            }
        }
    }
}