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
        Console.WriteLine("! "+sb.ToString());
    }
    void Calc(){
        long count = 10000000000;
        int digit = 0;
        while(true){
            Console.WriteLine("? "+ count);
            string s = Console.ReadLine();
            if(s[0] == 'Y'){
                break;
            }
            else{
                count /= 10;
            }
            digit++;
        }
        string ans = "";
        if(digit == 0){
            long C = 9;
            ans += "1";
            while(true){
                Console.WriteLine("? "+C);
                C = C*10+9;
                string s = Console.ReadLine();
                if(s[0] == 'Y'){
                    break;
                }
                ans += "0";
            }
        }
        else{
            long bf = count+1;
            long bl = count*10-1;
            while(bf != bl){
                long bc = (bf+bl)/2;
                Console.WriteLine("? "+ bc*10);
                string s = Console.ReadLine();
                if(s[0] == 'Y'){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            ans += bf;
        }
        sb.Append(ans);
    }
}