using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace r1apc
{
    class Tree
    {
        public int X;
        public int Y;

        public List<double> angles = new List<double>();
        public int minCut = int.MaxValue;
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("../../input.txt"))
            using (var outputStream = new StreamWriter("../../output.txt", false, Encoding.Default))
            {
                var caseCount = int.Parse(inputStream.ReadLine());

                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var treeCount = int.Parse(inputStream.ReadLine());
                    var trees = new List<Tree>();
                    for (var i = 0; i < treeCount; i++)
                    {
                        var coords = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                        trees.Add(new Tree() { X = coords[0], Y = coords[1] });
                    }

                    foreach (var tree in trees)
                    {
                        foreach (var otherTree in trees)
                        {
                            if (otherTree.Equals(tree))
                                continue;

                            tree.angles.Add(Math.Atan2(otherTree.Y - tree.Y, otherTree.X - tree.X) + Math.PI);
                        }
                    }
                    foreach (var tree in trees)
                    {
                        tree.angles.Sort();
                        tree.angles = tree.angles.Concat(tree.angles.Select(a => a + 2 * Math.PI)).ToList();

                        double? startAngle = 0.0;
                        while (true)
                        {
                            var angles = tree.angles.Where(a => a > startAngle && a < startAngle + Math.PI).ToList();
                            if (tree.minCut > angles.Count)
                                tree.minCut = angles.Count;
                            if (angles.Count == 0)
                                break;
                            startAngle = angles.Where(a => a > startAngle).Count() == 0 ? null : (double?)angles.Where(a => a > startAngle).First();
                            if (!startAngle.HasValue || startAngle >= 2 * Math.PI)
                                break;
                        }

                    }

                    outputStream.WriteLine("Case #{0}:", caseNumber);
                    foreach (var tree in trees)
                    {
                        outputStream.WriteLine("{0}", tree.minCut);
                    }
                }
            }
        }
    }
}
