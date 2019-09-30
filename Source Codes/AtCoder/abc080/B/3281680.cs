using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string input = ReadLine();
        int kazu = int.Parse(input);
        int wa = 0;
        int temp = kazu;
        
        for(int i=0;i<=10;i++){
            wa += temp%10;
            temp /= 10;
            if(temp == 0){
                break;
            }
        }
        if(kazu % wa ==0){
            WriteLine("Yes");
        }else{
            WriteLine("No");
        }
    }
}