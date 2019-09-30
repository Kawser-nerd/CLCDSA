using System;
using System.Linq;
public class Hello{
    public static void Main()
    {
        // Your code here!
        int[] s = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int A = s[0];
        int B = s[1];
        int C = s[2];
        int D = s[3];
        int ans = -1;
        if(Math.Max(A, C) <= Math.Min(B, D))
        {
            ans = Math.Min(B, D) - Math.Max(A, C);
        }
        else
        {
            ans = 0;
        }
        
        Console.WriteLine(ans);
    }
}