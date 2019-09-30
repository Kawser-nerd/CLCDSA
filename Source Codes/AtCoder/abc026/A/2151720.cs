using System;
public class Hello{
    public static void Main(){
        int A = int.Parse(Console.ReadLine());
        int max = 0;
        for(int x = 0;x < A;x++){
            int y = A - x;
            if(x * y > max){
                max = x * y;
            }
        }
        Console.WriteLine(max);
    }
}