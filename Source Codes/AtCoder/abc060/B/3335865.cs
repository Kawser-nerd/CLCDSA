using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] word = ReadLine().Split(' ');
        int moto = int.Parse(word[0]);
        int waru = int.Parse(word[1]);
        int amari = int.Parse(word[2]);
        int a = 0;
        for(int i=1;i<=100;i++){
            int motoi = moto*i;
            if(motoi%waru == amari){
                a++;
            }
        }
        if(a>0){
            WriteLine("YES");
        }else{
            WriteLine("NO");
        }
    }
}