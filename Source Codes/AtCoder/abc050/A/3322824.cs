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
        string[] inp = ReadLine().Split(' ');
        int a = int.Parse(inp[0]);
        int b = int.Parse(inp[2]);
        if(inp[1] == "+"){
            WriteLine(a+b);
        }else{
            WriteLine(a-b);
        }
    }
}