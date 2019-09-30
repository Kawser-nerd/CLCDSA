using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int leng = int.Parse(ReadLine());
        string input = ReadLine();
        int max = 0;
        int temp = 0;
        for(int i=0;i<leng;i++){
            if(input[i] == 'I'){
                temp++;
                max = Max(temp,max);
            }else if(input[i] == 'D'){
                temp--;
            }
        }
        WriteLine(max);
    }
}