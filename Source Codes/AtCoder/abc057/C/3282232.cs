using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        long num = long.Parse(ReadLine());
        double root = Sqrt(num);
        int ans = 100;
        for(int i=1;i<=root;i++){
            if(num % i == 0){
                long a = i;
                long b = num/i;
                int count = 1;
                while(a>=10 || b>=10){
                    a/=10;
                    b/=10;
                    count++;
                }
                if(count < ans){
                    ans = count;
                }
            }
        }
        WriteLine(ans);
    }
}