using System;

class program
{
    static long ans = 0;

    static void solv(long A, long B, long C)
    {
        long p, q, r;
        while (A%2==0 && B%2==0 && C%2==0)
        {
            ans++;
            p = (B + C) / 2;
            q = (C + A) / 2;
            r = (A + B) / 2;
            A = p;
            B = q;
            C = r;
        }
        return;
    }

    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split();
        long A = long.Parse(inputs[0]);
        long B = long.Parse(inputs[1]);
        long C = long.Parse(inputs[2]);

        if (A == B && B == C && A%2==0) Console.WriteLine(-1);
        else
        {
            solv(A, B, C);
            Console.WriteLine(ans);
        }
        
    }
}