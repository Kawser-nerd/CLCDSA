using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var A = new int[n];
        var temp = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            A[i] = int.Parse(temp[i]);
        }

        var ans = gcd(A);
        Console.WriteLine(ans);
    }

    static int gcd(int[] A)
    {
        var ans = A[0];
        for (int i = 1; i < A.Length; i++)
        {
            ans = gcd(ans, A[i]);
        }
        return ans;
    }

    static int gcd(int x, int y)
    {
        if (x == 0) return y;
        if (y == 0) return x;
        if (x < y) return gcd(x, y % x);
        else return gcd(x % y, y);
    }
}