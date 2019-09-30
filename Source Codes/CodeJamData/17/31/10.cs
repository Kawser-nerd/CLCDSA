using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    using TwoTuple = Tuple<int, int>;

    class Program
    {
        private StreamReader inputStream = new StreamReader("in.txt");
        private StreamWriter outputStream = new StreamWriter("out.txt");
        private double PI = Math.PI;

        static void Main(string[] args)
        {
            new Program().Run();
        }

        public double AreaCircle(int radius)
        {
            return PI * radius * radius;
        }

        public double AreaBorder(int radius, int height) {
            return 2 * PI * radius * height;
        }

        public class Panquee {
            public int Radius;
            public int Height;
            public double AreaBorder;
            public double AreaCircle;
        }

        public class Comparer : IComparer<Panquee>
        {
            public int Compare(Panquee x, Panquee y)
            {
                return y.AreaBorder.CompareTo(x.AreaBorder);
            }
        }

        public void Run()
        {
            string line = ReadString();
            int testCasesCount = int.Parse(line);
            for (int testCaseIndex = 1; testCaseIndex < testCasesCount + 1; ++testCaseIndex)
            {
                var panqueues = new List<Panquee>();
                var components = this.ReadIntegers();
                var totalPanqueues = components[0];
                var requestedCount = components[1];
                for (int i = 0; i < totalPanqueues; ++i) {
                    var newComponents = this.ReadIntegers();
                    var radius = newComponents[0];
                    var height = newComponents[1];
                    var areaBorder = AreaBorder(radius, height);
                    var areaCircle = AreaCircle(radius);
                    panqueues.Add(new Panquee() { Radius = radius, Height = height, AreaBorder = areaBorder, AreaCircle = areaCircle });
                }
                panqueues.Sort(new Comparer());
                var surePanqueues = panqueues.Take(requestedCount - 1).ToArray();
                panqueues = panqueues.Skip(requestedCount - 1).ToList();

                double sureAreaBorder = surePanqueues.Sum(p => p.AreaBorder);
                int sureRadius = surePanqueues.Count() > 0 ? surePanqueues.Max(p => p.Radius) : 0;

                var firstP = panqueues.First();
                double bestAreaOneOption = sureAreaBorder + firstP.AreaBorder + AreaCircle(Math.Max(firstP.Radius, sureRadius));
                double bestAreaOtherOption = bestAreaOneOption;
                for (int i = 0; i < panqueues.Count; ++i) {
                    var newP = panqueues[i];
                    double newOption = sureAreaBorder + newP.AreaBorder + AreaCircle(Math.Max(newP.Radius, sureRadius));
                    bestAreaOtherOption = Math.Max(bestAreaOtherOption, newOption);
                }

                outputStream.WriteLine($"Case #{testCaseIndex}: {bestAreaOtherOption}");
            }
            outputStream.Flush();
            outputStream.Close();
        }

        private string ReadString()
        {
            return this.inputStream.ReadLine();
        }

        private int[] ReadIntegers()
        {
            string line = this.ReadString();
            var components = line.Split(' ').Select(txt => int.Parse(txt)).ToArray();
            return components;
        }

        private double[] ReadDoubles()
        {
            string line = this.ReadString();
            var components = line.Split(' ').Select(txt => double.Parse(txt)).ToArray();
            return components;
        }
    }
}
