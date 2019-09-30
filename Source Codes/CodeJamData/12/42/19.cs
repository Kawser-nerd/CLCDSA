using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A1
{
    class Program
    {
        public const string inputFileName = @"D:\Study\Jam2\Files\B-small-attempt0.in";
        public const string outputFileName = @"D:\Study\Jam2\Files\B-small-attempt0.out";

        static void Main(string[] args)
        {
            var builder = new StringBuilder();
            using (var sr = new StreamReader(inputFileName))
            {
                String line;
                line = sr.ReadLine();
                int caseCounter = 1;
                while ((line = sr.ReadLine()) != null)
                {
                    var sizeLine = sr.ReadLine();
                    builder.Append("Case #" + caseCounter + ": ");

                    string[] first = line.Split(' ');
                    int W = Int32.Parse(first[1]);
                    int L = Int32.Parse(first[2]);

                    string[] second = sizeLine.Split(' ');
                    List<KeyValuePair<int, int>> sizesInOrder = new List<KeyValuePair<int,int>>();
                    for(int i = 0; i < second.Length; i++)
                    {
                        sizesInOrder.Add(new KeyValuePair<int,int>(i, Int32.Parse(second[i])));
                    }

                    ProcessCase(sizesInOrder, W, L, builder);
                    builder.AppendLine();
                    caseCounter++;
                }
            }

            using (var sw = new StreamWriter(outputFileName))
            {
                sw.Write(builder.ToString());
            }

            Console.WriteLine("Done...");
            Console.ReadKey();
        }

        static void ProcessCase(List<KeyValuePair<int, int>> sizesInOrder, int W, int L, StringBuilder builder)
        {
            float[] X = new float[sizesInOrder.Count];
            float[] Y = new float[sizesInOrder.Count];
            sizesInOrder.Sort(delegate(KeyValuePair<int, int> firstPair,
                KeyValuePair<int, int> nextPair)
                {
                    return nextPair.Value.CompareTo(firstPair.Value);
                });

            int width = (-1) * sizesInOrder[0].Value;
            int heigth = (-1) * sizesInOrder[0].Value;
            int heyMax = 0;

            while (sizesInOrder.Count > 0)
            {
                List<int> idxToRemove = new List<int>();
                for (int i = 0; i < sizesInOrder.Count; i++)
                {
                    if (W - width > sizesInOrder[i].Value && L - heigth > sizesInOrder[i].Value)
                    {
                        if (2 * sizesInOrder[i].Value > heyMax) heyMax = 2 * sizesInOrder[i].Value;
                        X[sizesInOrder[i].Key] = width + sizesInOrder[i].Value >= 0 ? width + sizesInOrder[i].Value : 0;
                        Y[sizesInOrder[i].Key] = heigth + sizesInOrder[i].Value >= 0 ? heigth + sizesInOrder[i].Value : 0;
                        width += sizesInOrder[i].Value * 2;
                        idxToRemove.Add(i);
                    }
                }

                for (int i = sizesInOrder.Count - 1; i >= 0; i--)
                {
                    if (idxToRemove.Contains(i)) sizesInOrder.RemoveAt(i);
                }

                idxToRemove.Clear();

                if (sizesInOrder.Count > 0)
                {
                    heigth += heyMax;
                    heyMax = 0;
                    width = (-1) * sizesInOrder[0].Value;
                }
            }

            for (int i = 0; i < X.Length; i++)
            {
                builder.Append(X[i]);
                builder.Append(" ");
                builder.Append(Y[i]);
                builder.Append(" ");
            }
        }
    }
}
