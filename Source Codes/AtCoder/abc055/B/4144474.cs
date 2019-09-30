using System;
using System.Linq;
public class Hello{
    public static void Main(){
        // Your code here!
        int N = int.Parse(Console.ReadLine());
        long num = 1;
        for(int i = 1; i <= N; i++)
        {
            num = (num * i) % 1000000007;
            
        }
        Console.WriteLine(num);
    }
}