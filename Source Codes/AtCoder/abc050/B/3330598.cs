using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int ques = int.Parse(ReadLine());
        string[] time = ReadLine().Split(' ');
        int drink = int.Parse(ReadLine());
        for(int i=0;i<drink;i++){
            string[] temp = ReadLine().Split(' ');
            int num = int.Parse(temp[0]);
            int jikan = int.Parse(temp[1]);
            int output = 0;
            for(int j=0;j<ques;j++){
                if(num-1 == j){
                    output += jikan;
                }else{
                    output += int.Parse(time[j]);
                }
            }
            WriteLine(output);
        }
    }
}