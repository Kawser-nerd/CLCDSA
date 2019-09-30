using System;

namespace AtCoder
{
    class B_SumofThreeIntegers_051
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            var K = int.Parse(input[0]);
            var S = int.Parse(input[1]);

            var count = 0;
            for (var x = 0; x <= K; ++x)
            {
                if (S < x) { break; }

                for (var y = 0; y <= K; ++y)
                {
                    if (S < x + y) { break; }

                    var z = S - x - y;
                    if (0 <= z && z <= K) { ++count; }
                }
            }

            Console.WriteLine(count);
        }
    }
}