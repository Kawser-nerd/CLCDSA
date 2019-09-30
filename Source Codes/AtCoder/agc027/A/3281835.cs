using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int kazu = int.Parse(input[0]);
        string[] suji = ReadLine().Split(' ');
//        int max = int.Parse(input[1]);
        int[] suuji = new int[kazu];
        for(int i=0;i<kazu;i++){
            suuji[i] = int.Parse(suji[i]);
        }
        for(int i=0;i<kazu*10;i++){
            for(int j=0;j<kazu-1;j++){
                if(suuji[j] > suuji[j+1]){
                    int temp = suuji[j];
                    suuji[j] = suuji[j+1];
                    suuji[j+1] = temp;
                }
            }
        }
        
/*        for(int i=0;i<kazu;i++){
            WriteLine(suuji[i]);
        }*/
        
        int a=int.Parse(input[1]);
        int ans = 0;
        for(int i=0;i<kazu;i++){
//            WriteLine("a{0}",a);
            if(suuji[i]<=a){
                a -= suuji[i];
                ans++;
            }
        }
//        WriteLine("aa{0}",a);
        if(ans == kazu && a>0){
            ans--;
//            WriteLine("ddd");
        }
        WriteLine(ans);
    }
}