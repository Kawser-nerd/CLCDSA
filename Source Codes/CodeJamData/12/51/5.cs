using System.Collections.Generic;
using System.IO;
using GCJ_base;
using System.Linq;

namespace GCJ_3A
{
    class Program
    {
        static void Main()
        {
            new Gcj3A().Run();
        }
    }

    class Gcj3A : Gcj
    {
        public Gcj3A()
        {
            Problem = 'A';
            Small = true;
        }

        protected override string ComputeCase(TextReader reader)
        {
            int n = int.Parse(reader.ReadLine());
            int[] lengths = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] probabilities = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

            var levels = new List<Level>(n);

            for (int i = 0; i < n; i++)
                levels.Add(new Level { Length = lengths[i], Probability = probabilities[i], Index = i });

            var result = levels
                .OrderByDescending(l => l.Probability)
                .ThenBy(l => l.Probability == 0 ? 0 : l.Length)
                .ThenBy(l => l.Index)
                .Select(l => l.Index);

            return string.Join(" ", result);
        }
    }

    class Level
    {
        public int Length;
        public int Probability;
        public int Index;
    }
}