using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudyingConsoleCSharp.CodeJam._2016Round1B
{
    public class ProblemA
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Round1B\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_A.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var s = textReader.ReadLine();

                    var r = Solve(s);
                    result.AppendLine($"Case #{t}: {r}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_A.txt"))
                textWriter.Write(result.ToString());
        }

        private string Solve(string s)
        {
            var arr = new int[26];
            foreach (var c in s)
                arr[c - 'A'] += 1;

            var r = new int[10];
            r[0] = Remove(arr, 'Z', "ZERO");
            r[6] = Remove(arr, 'X', "SIX");
            r[4] = Remove(arr, 'U', "FOUR");
            r[2] = Remove(arr, 'W', "TWO");
            r[8] = Remove(arr, 'G', "EIGHT");
            r[7] = Remove(arr, 'S', "SEVEN");
            r[5] = Remove(arr, 'V', "FIVE");
            r[1] = Remove(arr, 'O', "ONE");
            r[9] = Remove(arr, 'I', "NINE");
            r[3] = Remove(arr, 'T', "THREE");

            var sb = new StringBuilder();
            for (int i = 0; i < r.Length; ++i)
                for (int j = 0; j < r[i]; ++j)
                    sb.Append(i);
            return sb.ToString();
        }

        private int Remove(int[] arr, char c, string w)
        {
            var cnt = arr[c - 'A'];
            foreach (var wc in w)
                arr[wc - 'A'] -= cnt;
            return cnt;
        }
    }
}
