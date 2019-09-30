using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Messages
        {
            public const string BAD_MAGICIAN = "Bad magician!";
            public const string VOLUNTEER_CHEATED = "Volunteer cheated!";
        }

        static void Main(string[] args)
        {
            int numberOfTestCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, Trial());
            }
        }

        static string Trial()
        {
            bool[] firstTable = MakeTable();
            bool[] secondTable = MakeTable();

            int candidate = -1;

            for (int i = 0; i < firstTable.Length; i++)
            {
                if (firstTable[i] && secondTable[i])
                {
                    if (candidate < 0)
                    {
                        candidate = i + 1;
                    }
                    else
                    {
                        return Messages.BAD_MAGICIAN;
                    }
                }
            }

            if (candidate < 0)
            {
                return Messages.VOLUNTEER_CHEATED;
            }

            return candidate.ToString();
        }

        static bool[] MakeTable()
        {
            bool[] table = new bool[16];

            int answer = int.Parse(Console.ReadLine());

            for (int i = 0; i < 4; i++)
            {
                String line = Console.ReadLine();
                if (i + 1 != answer)
                {
                    continue;
                }

                var list = line.Split(' ').Select((x) => (int.Parse(x)));
                foreach (int x in list)
                {
                    table[x - 1] = true;
                }
            }

            return table;
        }
    }
}
