using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string a = ReadLine();
        string b = ReadLine();
        int al = a.Length;
        int bl = b.Length;
        if(al != bl){
            if(al>bl){
                WriteLine("GREATER");
            }else{
                WriteLine("LESS");
            }
        }else{
            int count = 0;
            for(int i=0;i<al;i++){
                int ai = int.Parse(a[i].ToString());
                int bi = int.Parse(b[i].ToString());
                if(ai > bi){
                    WriteLine("GREATER");
                    break;
                }else if(ai < bi){
                    WriteLine("LESS");
                    break;
                }else{
                    count++;
                }
            }
            if(count == al){
            WriteLine("EQUAL");
            }
        }
    }
}