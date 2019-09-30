using System;
public class Hello{
    public static void Main(){
        int[] input = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        int l = input[0];
        int h = input[1];
        
        int n = int.Parse(Console.ReadLine());
        for(var i = 0;i < n;i++){
            int a = int.Parse(Console.ReadLine());
            if(h < a){
                Console.WriteLine(-1);
            }else if(l <= a && a <= h){
                Console.WriteLine(0);
            }else{
                Console.WriteLine(l - a);
            }
        }
    }
}