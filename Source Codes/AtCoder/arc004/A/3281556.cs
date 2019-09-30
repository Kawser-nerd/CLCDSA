using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int kazu = int.Parse(ReadLine());
        double[,] zahyo = new double[kazu,2];
        for(int i=0;i<kazu;i++){
            string[] input = ReadLine().Split(' ');
            zahyo[i,0] = double.Parse(input[0]);
            zahyo[i,1] = double.Parse(input[1]);
        }
        double ans = 0;
        for(int i=0;i<kazu-1;i++){
            for(int j=i+1;j<kazu;j++){
                double leng = ((zahyo[j,0]-zahyo[i,0])*(zahyo[j,0]-zahyo[i,0])) + ((zahyo[j,1]-zahyo[i,1])*(zahyo[j,1]-zahyo[i,1]));
                ans = Max(leng,ans);
            }
        }
        ans = Sqrt(ans);
        WriteLine(ans);
    }
}