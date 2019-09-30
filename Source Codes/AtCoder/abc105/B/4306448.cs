using System;

namespace B.Cakes_and_Donuts
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            int ans = 0;

            for (int i = 0; i <= N; i += 4)
                for (int j = 0; j <= N - i; j += 7)
                    if ((i + j) == N)
                    {
                        ans++;
                        break;
                    }

            if (ans > 0)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}