using System;
using System.Linq;
using System.Collections.Generic;

public class Hello
{
    public static void Main()
    {
        
        int N = int.Parse(Console.ReadLine());
        List<int> A = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        
        int ans = A[0];
        for(int i = 1; i < N; i++)
        {
            ans = gcd(ans, A[i]);
            
        }
        Console.WriteLine(ans);
    }
    
    public static int gcd(int a, int b)// a > b
    {
        if(a < b) return gcd(b, a);
        else
        {
            if(b == 0) return a;
            else return gcd(b, a % b);
        }
        
    }
}