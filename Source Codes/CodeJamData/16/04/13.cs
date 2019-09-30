using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemD
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var t = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= t; caseNumber++)
            {
                var line = Console.ReadLine();
                var lineItems = line.Split(' ');
                var baseTileCount = int.Parse(lineItems[0]);
                var complexity = int.Parse(lineItems[1]);
                var studentCount = int.Parse(lineItems[2]);

                var positions = TryGetPositions(baseTileCount, complexity, studentCount);

                Console.Write("Case #{0}:", caseNumber);
                if (positions.Any())
                {
                    foreach (var position in positions)
                    {
                        Console.Write(' ');
                        Console.Write(position);
                    }

                    Console.WriteLine();
                }
                else
                {
                    Console.WriteLine(" IMPOSSIBLE");
                }
            }
        }

        private static IEnumerable<BigInteger> TryGetPositions(int baseTileCount, int complexity, int studentCount)
        {
            var baseTileCountPerStudent = complexity;
            var requiredStudentCount = (baseTileCount + (baseTileCountPerStudent - 1)) / baseTileCountPerStudent;
            if (studentCount < requiredStudentCount)
                yield break;

            for (var studentNumber = 1; studentNumber <= requiredStudentCount; studentNumber++)
            {
                var currentBasePosition = (studentNumber - 1) * baseTileCountPerStudent + 1;
                var currentPosition = new BigInteger(currentBasePosition);
                var complexityLeft = complexity;
                while (complexityLeft > 1)
                {
                    if (currentBasePosition < baseTileCount)
                        currentBasePosition++;
                    currentPosition = (currentPosition - 1) * baseTileCount + currentBasePosition;

                    complexityLeft--;
                }

                yield return currentPosition;
            }
        }
    }
}
