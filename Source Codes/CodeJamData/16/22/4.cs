using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudyingConsoleCSharp.CodeJam._2016Round1B
{
    public class ProblemB
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Round1B\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_B.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var s = textReader.ReadLine().Split(' ').ToArray();
                    var s1 = s[0];
                    var s2 = s[1];

                    var r = Solve(s1, s2);
                    result.AppendLine($"Case #{t}: {r}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_B.txt"))
                textWriter.Write(result.ToString());
        }

        private string Solve(string s1, string s2)
        {
            int min = int.MaxValue;
            int mini = 0, minj = 0;
            int n = s1.Length;
            for (int i = 0; i < Math.Pow(10, n); ++i)
            {
                for (int j = 0; j < Math.Pow(10, n); ++j)
                {
                    var diff = Math.Abs(j - i);
                    if (diff >= min)
                        continue;

                    var l = Get(i, n);
                    var r = Get(j, n);
                    var matched = true;
                    for (int k = 0; k < n; ++k)
                    {
                        if (l[k] != s1[k] && s1[k] != '?')
                        {
                            matched = false;
                            break;
                        }
                        if (r[k] != s2[k] && s2[k] != '?')
                        {
                            matched = false;
                            break;
                        }
                    }
                    if (matched)
                    {
                        min = diff;
                        mini = i;
                        minj = j;
                    }
                }
            }

            return $"{Get(mini, n)} {Get(minj, n)}";
        }

        private string Get(int i, int n)
        {
            var cs = new char[n].Select(x => '0').ToArray();
            for (int j = n - 1; j >= 0; j--)
            {
                cs[j] = char.Parse((i%10).ToString());
                i /= 10;
            }
            return new string(cs);
        }
    }
}
