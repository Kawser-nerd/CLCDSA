using System;
using System.Linq;

namespace numa
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] n = Console.ReadLine().Split().ToArray();
            int X = int.Parse(n[0]);
            int Y = int.Parse(n[1]);
            int N = int.Parse(Console.ReadLine());
            var x = new int[N + 2];
            var y = new int[N + 2];
            for(int i = 1; i <= N; i++)
            {
                string[] input = Console.ReadLine().Split().ToArray();
                x[i] = int.Parse(input[0]);
                y[i] = int.Parse(input[1]);
            }
            x[N + 1] = x[1];
            y[N + 1] = y[1];

            double ans = double.MaxValue;
            for(int i = 1; i <= N; i++)
            {
                double tmp = Math.Abs((y[i + 1] - y[i]) * X - Y * (x[i + 1] - x[i]) + x[i + 1] * y[i] - x[i] * y[i + 1]) / Math.Sqrt(Math.Pow(x[i + 1] - x[i], 2) + Math.Pow(y[i + 1] - y[i], 2));
                ans = Math.Min(ans, tmp);
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }
    }
}