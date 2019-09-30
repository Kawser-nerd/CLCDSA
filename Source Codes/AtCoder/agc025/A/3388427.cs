using System;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        int kazu = int.Parse(ReadLine());
        int a = 1;
        int b = 0;

        while(a<kazu){
            a*=10;
        }
        a/=10;
        b=kazu-a;
        
        int count = 0;
        while(a>0 || b>0){
            count += a%10 + b%10;
            a/=10;
            b/=10;
//            WriteLine("{0} {1} {2}",count,a,b);
        }
        WriteLine(count);
    }
}