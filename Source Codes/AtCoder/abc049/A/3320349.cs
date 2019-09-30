using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
/*        string[] input = ReadLine().Split(' ');
        long a = long.Parse(input[0]);
        long b = long.Parse(input[1]);
        long x = long.Parse(input[2]);
        
        long ans = 0;
        ans += b/x;
        if(a>x){
        if(a%x == 0){
            ans -= (a/x)-1;
        }else{
            ans -= a/x;
        }
        }
        if(a==0){
            ans++;
        }
        WriteLine(ans);*/
        string a = ReadLine();
        if(a=="a"||a=="i"||a=="u"||a=="e"||a=="o"){
            WriteLine("vowel");
        }else{
            WriteLine("consonant");
        }
    }
}