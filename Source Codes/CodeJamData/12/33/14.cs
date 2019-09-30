using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            long numberOfCases = long.Parse(input.ReadLine());
            for (long currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
                output.WriteLine(string.Empty);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            string[] counts = input.ReadLine().Split(' ');
            long countToys = long.Parse(counts[(int)0]);
            long countBoxes = long.Parse(counts[(int)1]);
            string[] toyStrings = input.ReadLine().Split(' ');
            string[] boxStrings = input.ReadLine().Split(' ');
            List<long> toyValues = new List<long>();
            List<long> boxValues = new List<long>();
            for (long index = 0; index < toyStrings.Length; index++)
            {
                toyValues.Add(long.Parse(toyStrings[(int)index]));
            }
            for (long index = 0; index < boxStrings.Length; index++)
            {
                boxValues.Add(long.Parse(boxStrings[(int)index]));
            }
            long count = BoxToys(toyValues, boxValues, 0, 0, toyValues[(int)0], toyValues[(int)1], boxValues[(int)0], boxValues[(int)1], 0);
            output.Write(count.ToString());
        }

        private static long BoxToys(List<long> toyValues, List<long> boxValues, long toyIndex, long boxIndex, long toyCount, long toyValue, long boxCount, long boxValue, long count)
        {
            if (toyIndex >= toyValues.Count)
            {
                return DiscardBoxes(toyValues, boxValues, ref toyIndex, ref boxIndex, ref count, ref toyCount, toyValue, ref boxCount, boxValue);
            }
            if (boxIndex >= boxValues.Count)
            {
                return DiscardBoxes(boxValues, toyValues, ref boxIndex, ref toyIndex, ref count, ref boxCount, boxValue, ref toyCount, toyValue);
            }
            if (toyValue == boxValue)
            {
                long boxed = Math.Min(toyCount, boxCount);
                count += boxed;
                toyCount -= boxed;
                boxCount -= boxed;
                if (toyCount == 0)
                {
                    toyIndex += 2;
                    if ((toyIndex + 2) <= toyValues.Count)
                    {
                        toyCount = toyValues[(int)toyIndex];
                        toyValue = toyValues[(int)toyIndex + 1];
                    }
                }
                if (boxCount == 0)
                {
                    boxIndex += 2;
                    if ((boxIndex + 2) <= boxValues.Count)
                    {
                        boxCount = boxValues[(int)boxIndex];
                        boxValue = boxValues[(int)boxIndex + 1];
                    }
                }
                if ((boxIndex + 2) <= boxValues.Count && (toyIndex + 2) <= toyValues.Count)
                {
                    return BoxToys(toyValues, boxValues, toyIndex, boxIndex, toyCount, toyValue, boxCount, boxValue, count);
                }
                else
                {
                    return count;
                }
            }
            else
            {
                return Math.Max(DiscardBoxes(toyValues, boxValues, ref toyIndex, ref boxIndex, ref count, ref toyCount, toyValue, ref boxCount, boxValue),
                    DiscardBoxes(boxValues, toyValues, ref boxIndex, ref toyIndex, ref count, ref boxCount, boxValue, ref toyCount, toyValue));
            }

        }

        private static long DiscardBoxes(List<long> toyValues, List<long> boxValues, ref long toyIndex, ref long boxIndex, ref long count, ref long toyCount, long toyValue, ref long boxCount, long boxValue)
        {
            if (toyValue != boxValue)
            {
                if ((boxIndex + 2) >= boxValues.Count)
                {
                    return count;
                }
                return BoxToys(toyValues, boxValues, toyIndex, boxIndex + 2, toyCount, toyValue, boxValues[(int)boxIndex + 2], boxValues[(int)boxIndex + 3], count);
            }
            else
            {
                return BoxToys(toyValues, boxValues, toyIndex, boxIndex, toyCount, toyValue, boxCount, boxValue, count);
            }
        }

        private static void GetCounts(string[] toyStrings, ref long toyIndex, out long toyCount, out long toyValue)
        {
            toyCount = long.Parse(toyStrings[(int)toyIndex++]);
            toyValue = long.Parse(toyStrings[(int)toyIndex++]);
        }
    }
}
