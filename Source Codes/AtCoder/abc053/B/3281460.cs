using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string input = ReadLine();
        int a = -1;
        int b = 0;
        for(int i=0;i<input.Length;++i){
            if(input[i] == 'A' && a == -1){
                a = i;
            }
            if(input[i] == 'Z'){
                b = i;
            }
        }
        WriteLine(b-a+1);
    }
}