using System;
using System.Linq;
public class Hello{
    public static void Main(){
        // Your code here!
        int[] s = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int N = s[0];
        int K = s[1];
        int num = 1;
        for(int i = 0; i < N; i++)
        {
            if(i == 0) num *= K;
            else num *= (K - 1);
        }
        Console.WriteLine(num);
    }
}