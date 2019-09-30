using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] num = ReadLine().Split(' ');
        int[] check = new int[100];
        for(int i = 0;i<num.Length;i++){
            int a = int.Parse(num[i]);
            check[a-1]++;
        }
        int ans = 0;
        for(int i=0;i<100;i++){
            if(check[i] > 0){
                ans++;
            }
        }
        WriteLine(ans);
    }
}