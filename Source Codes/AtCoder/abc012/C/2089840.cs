using System;
public class Hello{
    public static void Main(){
        var N = int.Parse(Console.ReadLine());
        int A = 2025 - N;
        for(int x = 1;x <= 9;x++){
            for(int y = 1;y <= 9;y++){
                if(x * y == A){
                    Console.WriteLine($"{x} x {y}");
                }
            }
        }
    }
}