using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int studen = int.Parse(input[0]);
        int checkp = int.Parse(input[1]);
        int[,] stuz = new int[studen,2];
        int[,] chez = new int[checkp,2];
        for(int i=0;i<studen;i++){
            string[] temp = ReadLine().Split(' ');
            stuz[i,0] = int.Parse(temp[0]);
            stuz[i,1] = int.Parse(temp[1]);
        }
        
        for(int i=0;i<checkp;i++){
            string[] temp = ReadLine().Split(' ');
            chez[i,0] = int.Parse(temp[0]);
            chez[i,1] = int.Parse(temp[1]);
        }
        
        for(int i=0;i<studen;i++){
            int min = 999999999;
            int ans = 0;
            for(int j=0;j<checkp;j++){
                int leng = Abs(stuz[i,0] - chez[j,0]) + Abs(stuz[i,1] - chez[j,1]);
                if(min > leng){
                    min = leng;
                    ans = j+1;
                }
            }
            WriteLine(ans);
        }
    }
}