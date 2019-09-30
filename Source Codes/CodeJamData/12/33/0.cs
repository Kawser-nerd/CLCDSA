using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2012\GoogleCodeJam1C\ProblemC\Input\C-small-attempt1.in";
            const string outputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2012\GoogleCodeJam1C\ProblemC\Output\Small-1.txt";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            Int64 testCases = Int64.Parse(sr.ReadLine());
            for (Int64 i=1; i<=testCases; i++)
            {
                var testCase = BoxFactory.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class BoxFactory
    {
        public int N { get; set; }
        public int M { get; set; }

        public List<Tuple<Int64, Int64>> A { get; set; }
        public List<Tuple<Int64, Int64>> B { get; set; }

        public static BoxFactory ParseCase(StreamReader sr)
        {
            var parameters =
                sr.ReadLine()
                .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => int.Parse(s))
                .ToList();

            var n = parameters.First();
            var m = parameters.Last();

            var parameters2 =
                sr.ReadLine()
                .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => Int64.Parse(s))
                .ToList();

            var a = Enumerable.Range(0, n)
                .Select(i => new Tuple<Int64, Int64>(parameters2[2*i], parameters2[2*i + 1]))
                .ToList();

            parameters2 =
                sr.ReadLine()
                .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => Int64.Parse(s))
                .ToList();

            var b = Enumerable.Range(0, m)
                .Select(i => new Tuple<Int64, Int64>(parameters2[2*i], parameters2[2*i + 1]))
                .ToList();


            return new BoxFactory {N = n, M = m, A = a, B = b};
        }

        public String SolveCase()
        {
            return MatchBoxes(A, B).ToString();
        }

        public Int64 MatchBoxes(List<Tuple<Int64, Int64>> Boxes, List<Tuple<Int64, Int64>> Toys)
        {
            if (Boxes.Count == 0 || Toys.Count == 0)
                return 0;

            var box = Boxes.First();
            var toy = Toys.First();
            if(box.Item2 == toy.Item2)
            {
                Int64 boxedToys = Math.Min(box.Item1, toy.Item1);
                if(box.Item1 == toy.Item1)
                {
                    return boxedToys + MatchBoxes(Boxes.Skip(1).ToList(), Toys.Skip(1).ToList());
                }
                if(box.Item1 > toy.Item1)
                {
                    var remainingBoxes = new List<Tuple<Int64, Int64>> {new Tuple<Int64, Int64>(box.Item1 - boxedToys, box.Item2)}
                        .Concat(Boxes.Skip(1)).ToList();
                    return boxedToys + MatchBoxes(remainingBoxes, Toys.Skip(1).ToList());
                }
                var remainingToys = new List<Tuple<Int64, Int64>> { new Tuple<Int64, Int64>(toy.Item1 - boxedToys, toy.Item2) }
                    .Concat(Toys.Skip(1)).ToList();
                return boxedToys + MatchBoxes(Boxes.Skip(1).ToList(), remainingToys);
            }

            //Throw out boxes
            var noboxesList = Boxes.SkipWhile(b => b.Item2 != toy.Item2).ToList();
            var noboxes = MatchBoxes(noboxesList, Toys);

            //Throw out toys
            var notoysList = Toys.SkipWhile(t => t.Item2 != box.Item2).ToList();
            var notoys = MatchBoxes(Boxes, notoysList);

            //Throw out both
            var neither = MatchBoxes(Boxes.Skip(1).ToList(), Toys.Skip(1).ToList());

            return Math.Max(neither, Math.Max(noboxes, notoys));
        }
    }
}
