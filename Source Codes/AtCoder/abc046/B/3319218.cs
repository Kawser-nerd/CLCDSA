using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] num = ReadLine().Split(' ');
        int n = int.Parse(num[0]);
        int k = int.Parse(num[1]);
        int ans = k;
        int n1 = n-1;
        int k1 = k-1;
        for(int i=0;i<n1;i++){
            ans*=k1;
        }
        WriteLine(ans);
    }
}