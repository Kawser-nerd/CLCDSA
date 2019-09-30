using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] num = ReadLine().Split(' ');
        int n = int.Parse(num[0]);
        int k = int.Parse(num[1]);
        int m = int.Parse(num[2]);
        int d = n+m+k;
        int a = (n+k+m)/2;
        if((a == n || a == m||a==k )&& d%2==0){
            WriteLine("Yes");
        }else{
            WriteLine("No");
        }
    }
}