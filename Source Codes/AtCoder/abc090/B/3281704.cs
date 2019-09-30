using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int min = int.Parse(input[0]);
        int max = int.Parse(input[1]);
        int w = 0;
        
        for(int i=min;i<=max;i++){
            int[] suji = new int[5];
            int temp = i;
            for(int j=0;j<5;j++){
                suji[j] = temp%10;
                temp /= 10;
            }
            if(suji[0] == suji[4] && suji[1] == suji[3]){
                w++;
            }
        }
        WriteLine(w);
    }
}