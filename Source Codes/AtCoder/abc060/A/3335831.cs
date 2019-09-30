using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] word = ReadLine().Split(' ');
        int l1 = word[0].Length;
        int l2 = word[1].Length;
        if(word[0][l1-1] == word[1][0] && word[1][l2-1] == word[2][0]){
            WriteLine("YES");
        }else{
            WriteLine("NO");
        }
    }
}