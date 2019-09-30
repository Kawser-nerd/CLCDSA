using System;
using System.Linq;
public class Hello{
    public static void Main(){
        // Your code here!
        int N = int.Parse(Console.ReadLine());
        int[] num = new int[110];
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            int x = int.Parse(Console.ReadLine());
            num[x]++;
        }
        
        for(int i = 0; i < num.Length; i++)
        {
            if(num[i] > 0)
            {
                sum++;
            }
        }
        
        Console.WriteLine(sum);
        
    }
}