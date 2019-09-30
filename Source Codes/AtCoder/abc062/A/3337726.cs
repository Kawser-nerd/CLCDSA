using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        string[] a = new string[]{"1","3","5","7","8","10","12"};
        string[] b = new string[]{"4","6","9","11"};
        int ia1 = -1;
        int ia2 = -1;
        int ib1 = -1;
        int ib2 = -1;
        for(int i=0;i<7;i++){
            if(a[i] == input[0]){
                ia1 = 0;
            }
            if(a[i] == input[1]){
                ia2 = 0;
            }
            if(b[i%4] == input[0]){
                ib1 = 0;
            }
            if(b[i%4] == input[1]){
                ib2 = 0;
            }
        }
        if((ia1>=0&&ia2>=0) || (ib1>=0&&ib2>=0)){
            WriteLine("Yes");
        }else{
            WriteLine("No");
        }
    }
}