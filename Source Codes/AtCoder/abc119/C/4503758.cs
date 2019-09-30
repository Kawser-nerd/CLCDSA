using System;
using System.Linq;
using System.Collections.Generic;

public class Hello
{
    public static int N, A, B, C;
    public static int[] L;
    public static void Main()
    {
        // Your code here!
        int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        N = a[0];
        A = a[1];
        B = a[2];
        C = a[3];
        L = new int[N];
        
        for(int i = 0; i < N; i++)
        {
            L[i] = int.Parse(Console.ReadLine());
        }
        
        Console.WriteLine(dfs(0,0,0,0));
        
        
        
        

        
    }
    
    public static int dfs(int depth, int a, int b, int c) //????????????
    {
        if (depth == N)
        {
            if((a == 0 || b == 0)|| c == 0) return 10000000;
            else
            {
                return Math.Abs(A - a) + Math.Abs(B - b) + Math.Abs(C - c);
            }
            
        }
    
        int res = dfs(depth + 1, a, b, c);
        
        res = Math.Min(res, dfs(depth + 1, a + L[depth], b, c) + ((a != 0) ? 10 : 0));
        res = Math.Min(res, dfs(depth + 1, a, b + L[depth], c) + ((b != 0) ? 10 : 0));
        res = Math.Min(res, dfs(depth + 1, a, b, c + L[depth]) + ((c != 0) ? 10 : 0));
        
        return res;
    }
    
    
}