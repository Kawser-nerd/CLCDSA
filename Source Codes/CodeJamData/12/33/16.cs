#region using directives

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

#endregion

namespace ProblemC
{
    internal class Program
    {
        private static void Main()
        {
            string[] input = File.ReadAllLines("input.txt");
            int count = Int32.Parse(input[0]);

            var sb = new StringBuilder();

            int lineNr = 1;

            for (int i = 1; i <= count; i++)
            {
                sb.Append("Case #" + i + ": ");

                var toyList = new List<ProductionItem>();
                var boxList = new List<ProductionItem>();

                var nm = input[lineNr].Split(new[] { ' ' }).Select(Int32.Parse).ToList();
                lineNr++;

                int n = nm[0];
                int m = nm[1];

                var aList = input[lineNr].Split(new[] { ' ' }).Select(Int64.Parse).ToList();
                lineNr++;

                var bList = input[lineNr].Split(new[] { ' ' }).Select(Int64.Parse).ToList();
                lineNr++;

                for (int j = 0; j < n*2; j+=2)
                {
                    boxList.Add(new ProductionItem(aList[j], aList[j+1]));
                }

                for (int j = 0; j < m * 2; j += 2)
                {
                    toyList.Add(new ProductionItem(bList[j], bList[j + 1]));
                }

                var result = Solve(boxList, toyList, 0);

                sb.AppendLine(result.ToString());
            }

            Console.Write(sb.ToString());
            File.WriteAllText("ouput.txt", sb.ToString().Trim());
        }

        private static long Solve(List<ProductionItem> boxList, List<ProductionItem> toyList, long produced)
        {
            while (true)
            {
                var boxes = boxList.FirstOrDefault();
                var toys = toyList.FirstOrDefault();

                if (boxes == null || toys == null)
                    return produced;

                if (boxes.Type == toys.Type)
                {
                    var count = Math.Min(boxes.Count, toys.Count);

                    boxes.Count -= count;
                    toys.Count -= count;
                    
                    if (boxes.Count == 0)
                        boxList.Remove(boxes);

                    if (toys.Count == 0)
                        toyList.Remove(toys);

                    produced += count;
                }
                else
                {

                    var r1 = Solve(Clone(boxList), Clone(toyList.Skip(1)), produced);
                    var r2 = Solve(Clone(boxList.Skip(1)), Clone(toyList), produced);
                    var r3 = Solve(Clone(boxList.Skip(1)), Clone(toyList.Skip(1)), produced);

                    return Math.Max(r1, Math.Max(r2, r3));
                }
            }
        }

        private static List<ProductionItem> Clone(IEnumerable<ProductionItem> boxList)
        {
            return boxList.Select(x => x.Clone()).ToList();
        }
    }


    public class ProductionItem
    {
        public ProductionItem(long count, long type)
        {
            Type = type;
            Count = count;
        }

        public long Type { get; private set; }
        public long Count { get; set; }

        public ProductionItem Clone()
        {
            return new ProductionItem(Count, Type);
        }
    }


}