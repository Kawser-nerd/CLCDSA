using System;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        int kazu = int.Parse(ReadLine());
        string[] suuji = ReadLine().Split(' ');
        int[] suujii = new int[kazu];
        for(int i=0;i<kazu;i++){
            suujii[i] = int.Parse(suuji[i]);
        }
        int count = 0;
        for(int i=1;i<kazu;i++){
            if(suujii[i] == suujii[i-1]){
                suujii[i] = suujii[i-1] + 10000;
                count++;
            }
        }
        WriteLine(count);
    }
}