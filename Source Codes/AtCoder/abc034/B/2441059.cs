using System;
public class Hello{
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        if(N % 2 == 0){
            Console.WriteLine(N - 1);
        }else{
            Console.WriteLine(N + 1);
        }
    }
}