using System;
using System.IO;
using System.Linq;

namespace ABC118D_2
{
    // ABC118D???????
    class Program
    {
        private static readonly int[] requiredMatches = { 2, 5, 5, 4, 5, 6, 3, 7, 6 };

        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                Console.SetIn(new StreamReader(args[0]));
            }

            new Program().Solve();
        }

        void Solve()
        {
            // ??
            var temp = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var numMatches = temp[0];
            var numNumbers = temp[1];
            var availableNumbers = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var maxNumber = new string[numMatches + 1];

            for (int i = 0; i <= numMatches; i++)
            {
                maxNumber[i] = "";

                for (int j = 0; j < availableNumbers.Length; j++)
                {
                    var candidate = availableNumbers[j];

                    if (i - requiredMatches[candidate - 1] < 0)
                    {
                        continue;
                    }

                    if (maxNumber[i - requiredMatches[candidate - 1]] == "")
                    {
                        if (i != requiredMatches[candidate - 1])
                        {
                            continue;
                        }
                    }

                    var number = candidate + maxNumber[i - requiredMatches[candidate - 1]];
                    maxNumber[i] = GetMax(number, maxNumber[i]);
                }

                Console.Error.WriteLine(i + " : " + maxNumber[i]);
            }

            Console.WriteLine(maxNumber[numMatches]);
        }
        string GetMax(string a, string b)
        {
            if (a.Length > b.Length)
            {
                return a;
            }
            else if (a.Length < b.Length)
            {
                return b;
            }
            else
            {
                return a.CompareTo(b) > 0 ? a : b;
            }
        }
    }
}