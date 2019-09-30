using System;

namespace B.Exponential
{
    class Program
    {
        static void Main(string[] args)
        {
            var X = int.Parse(Console.ReadLine());
            int ans = 0;

            for (int b = 1; b <= Math.Floor(Math.Sqrt(X)); b++)
            {
                for (int p = 2; Math.Pow(b, p) <= X; p++)
                {
                    ans = Math.Max(ans, (int)Math.Pow(b,p));
                    if (b == 1) break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}