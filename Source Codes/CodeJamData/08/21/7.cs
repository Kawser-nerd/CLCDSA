using System;

public class triangles
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        for (int cs = 1; cs <= N; cs++)
        {
            string[] parts = Console.ReadLine().Split();
            long n = long.Parse(parts[0]);
            long A = long.Parse(parts[1]);
            long B = long.Parse(parts[2]);
            long C = long.Parse(parts[3]);
            long D = long.Parse(parts[4]);
            long x0 = long.Parse(parts[5]);
            long y0 = long.Parse(parts[6]);
            long M = long.Parse(parts[7]);
            long[] x = new long[n];
            long[] y = new long[n];
            for (int i = 0; i < n; i++)
            {
                x[i] = x0;
                y[i] = y0;
                x0 = (A * x0 + B) % M;
                y0 = (C * y0 + D) % M;
            }
            long ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        if ((x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0)
                            ans++;
                    }
                }
            }
            Console.WriteLine("Case #" + cs + ": " + ans);
        }
    }
}