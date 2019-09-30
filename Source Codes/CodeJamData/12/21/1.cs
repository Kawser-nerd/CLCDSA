using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Jam21
{
    class Program
    {
        const string FileName = @"D:\A-large.in";
        public const string outputFileName = @"D:\A-large-out.in";

        static void Main(string[] args)
        {
            var builder = new StringBuilder();

            using (var sr = new StreamReader(FileName))
            {
                String line;
                line = sr.ReadLine();
                int caseCounter = 1;

                while ((line = sr.ReadLine()) != null)
                {
                    builder.Append("Case #" + caseCounter + ": ");

                    string[] data = line.Split(' ');
                    int[] uData = new int[Int32.Parse(data[0])];

                    for (int i = 1; i < data.Length; i++)
                    {
                        uData[i - 1] = int.Parse(data[i]);
                    }

                    processCase(uData, builder);

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

        static void processCase(int[] uData, StringBuilder builder)
        {
            int X = 0;
            foreach (var i in uData) X += i;

            int[] sorted = new int[uData.Length];
            uData.CopyTo(sorted, 0);

            Array.Sort(sorted);

            double[] result = new double[uData.Length];
            double totalUnsplitted = 0;
            for (int i = 0; i < sorted.Length - 1; i++)
            {
                double deltaUnsplitted = (double)(sorted[i + 1] - sorted[i]) / X;
                totalUnsplitted += deltaUnsplitted * (i + 1);
                if (totalUnsplitted >= 1) deltaUnsplitted -= ((totalUnsplitted - 1) / (i + 1));
                double delta = deltaUnsplitted;
                for (int j = 0; j <= i; j++)
                {
                    result[j] += delta;
                }
                if (totalUnsplitted >= 1) break;
            }

            if (totalUnsplitted < 1)
            {
                double addDelta = (1 - totalUnsplitted) / sorted.Length;
                for (int i = 0; i < result.Length; i++) result[i] += addDelta;
            }

            double[] arranged = new double[sorted.Length];
            for (int i = 0; i < sorted.Length; i++)
            {
                for (int j = 0; j < uData.Length; j++)
                {
                    if (sorted[i] == uData[j])
                        arranged[j] = result[i] * 100;
                }
            }

            for (int i = 0; i < arranged.Length; i++)
            {
                builder.Append(Math.Round(arranged[i], 6).ToString());
                builder.Append(" ");
            }

            builder.AppendLine();
        }
    }
}
