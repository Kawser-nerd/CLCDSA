using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Googlerese
    {
        public static string ourClueTextG = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
        public static string ourClueTextE = "a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

        public static string[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int cases = int.Parse(lines[0]);
            var result = new string[cases];
            Array.Copy(lines, 1, result, 0, cases);
            return result;
        }

        public static void Main()
        {
            var charMapping = new Dictionary<char, char>();
            for (int i = 0; i < ourClueTextE.Length; i++)
            {
                var g = ourClueTextG[i];
                var e = ourClueTextE[i];
                if (charMapping.ContainsKey(g))
                {
                    if (charMapping[g] != e)
                        throw new Exception("Inconsistent mapping");
                }
                else charMapping[g] = e;
            }

            charMapping['z'] = 'q';

            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\Googlerese\small input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\Googlerese\small output.txt";
            string[] input = ReadFile(inputFilepath);
            var outputFile = File.CreateText(outputFilepath);

            for (int i = 0; i < input.Length; i++)
            {
                string translation = new string(input[i].Select(g => charMapping[g]).ToArray());
                string outputLine = string.Format("Case #{0}: {1}", i + 1, translation);
                Console.WriteLine(outputLine);
                outputFile.WriteLine(outputLine);
            }

            outputFile.Close();
        }
    }
}
