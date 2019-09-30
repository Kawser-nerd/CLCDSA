using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string input = ReadLine();
        string even = ReadLine();
//        int studen = int.Parse(input[0]);
//        int checkp = int.Parse(input[1]);
//        int c = int.Parse(input[2]);
        int leng = input.Length + even.Length;
        string ans ="";
        for(int i=0;i<leng;i++){
            if(i%2==0){
                ans += input[i/2].ToString();
            }else{
                ans += even[i/2].ToString();
            }
        }
        WriteLine(ans);
    }
}