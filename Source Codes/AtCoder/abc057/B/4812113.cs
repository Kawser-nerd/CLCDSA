using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC057_B();
        }

        static void ABC057_B()
        {
            var NM = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var N = NM[0];
            var M = NM[1];

            var students = new Dictionary<int, List<int>>();
            var points = new Dictionary<int, List<int>>();
            for (var n = 1; n <= N; n++)
            {
                var input = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                students.Add(n, input);
            }

            for (var m = 1; m <= M; m++)
            {
                var input = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                points.Add(m, input);
            }

            var ans = new List<int>();
            foreach (var student in students)
            {
                var min = int.MaxValue;
                var minNumber = 1;
                foreach (var point in points)
                {
                    var kyori = Math.Abs((student.Value[0] - point.Value[0])) + Math.Abs((student.Value[1] - point.Value[1]));
                    if (kyori == min) continue;
                    if (min > kyori)
                    {
                        minNumber = point.Key;
                        min = kyori;
                    }
                }
                ans.Add(minNumber);
            }

            foreach (var a in ans)
                Console.WriteLine(a);
        }
    }
}