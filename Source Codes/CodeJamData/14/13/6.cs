using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

class CProperShuffleSolution
{
    static void Main()
    {
        var T = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
        for (int t = 1; t <= T; t++)
        {
            var N = int.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);
            var A = Console.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(_ => int.Parse(_, CultureInfo.InvariantCulture)).ToArray();
            if (A.Length != N)
                throw new InvalidOperationException("Expected " + N + " items in line, actual count " + A.Length);

            long metric = 0;
            for (int i = 0; i < N; i++)
                metric += A[i] > i ? N / 2 - A[i] + i : 0;

            Console.WriteLine("Case #{0}: {1}", t, metric >= 93500 ? "BAD" : "GOOD");
        }
    }
}
