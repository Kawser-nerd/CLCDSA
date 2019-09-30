using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int kazu = int.Parse(ReadLine());
        long ans = 1;
        for(int i=1;i<=kazu;i++){
            ans*=i;
            if(ans>1000000007){
                ans%=1000000007;
            }
        }
        WriteLine(ans);
    }
}