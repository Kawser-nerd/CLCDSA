using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2016Round2
{
    public class ProblemA
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Round2\";
        private const string Impossible = "IMPOSSIBLE";

        private class Option
        {
            public string Order { get; private set; }
            public int[] Counts { get; private set; }
            public Option(string order)
            {
                Order = order;
                Counts = GetCounts(order);
            }

            private int[] GetCounts(string str)
            {
                var chs = new int[3];
                foreach (var ch in str)
                {
                    if (ch == 'P')
                        chs[0] += 1;
                    else if (ch == 'R')
                        chs[1] += 1;
                    else if (ch == 'S')
                        chs[2] += 1;
                }
                return chs;
            }
        }

        public void Process()
        {
            var result = new StringBuilder();
            var precomputed = new List<Option>[13];
            for (int i = 0; i < precomputed.Length; ++i)
                precomputed[i] = Calculate(i);

            using (var tr = File.OpenText(Path + "in_A.txt"))
            {
                var testsCount = int.Parse(tr.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var arr = tr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var n = arr[0];
                    var r = arr[1];
                    var p = arr[2];
                    var s = arr[3];
                    var order = Solve(p, r, s, precomputed[n]);
                    result.AppendLine($"Case #{t}: {order}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_A.txt"))
                textWriter.Write(result.ToString());
        }

        private List<Option> Calculate(int max)
        {
            var sb1 = new StringBuilder();
            var sb2 = new StringBuilder();
            var sb3 = new StringBuilder();
            Dfs('P', max, 0, ref sb1);
            Dfs('R', max, 0, ref sb2);
            Dfs('S', max, 0, ref sb3);
            var s1 = sb1.ToString();
            var s2 = sb2.ToString();
            var s3 = sb3.ToString();

            var result = new List<Option>();
            result.Add(new Option(s1));
            result.Add(new Option(s2));
            result.Add(new Option(s3));

            return result;
        }

        //private List<List<Option>> Calculate(int max)
        //{
        //    var result = new List<List<Option>>();
        //    for (int i = 0; i <= max; ++i)
        //        result.Add(new List<Option>());

        //    Bfs('P', max, result);
        //    Bfs('R', max, result);
        //    Bfs('S', max, result);

        //    return result;
        //}

        //private void Bfs(char ch, int max, List<List<Option>> result)
        //{
        //    var queue = new Queue<char>();
        //    var count = 1;
        //    var level = 0;
        //    var sb = new StringBuilder();
        //    queue.Enqueue(ch);
        //    var i = 0;
        //    while (level <= max)
        //    {
        //        var q = queue.Dequeue();
        //        sb.Append(q);
        //        ++i;
        //        if (q == 'P')
        //        {
        //            queue.Enqueue('P');
        //            queue.Enqueue('R');
        //        }
        //        else if (q == 'R')
        //        {
        //            if (level == max - 1)
        //            {
        //                queue.Enqueue('R');
        //                queue.Enqueue('S');
        //            }
        //            else
        //            {
        //                queue.Enqueue('S');
        //                queue.Enqueue('R');
        //            }
        //        }
        //        else if (q == 'S')
        //        {
        //            queue.Enqueue('P');
        //            queue.Enqueue('S');
        //        }
        //        if (i == count)
        //        {
        //            result[level].Add(new Option(sb.ToString()));
        //            ++level;
        //            count *= 2;
        //            i = 0;
        //            sb = new StringBuilder();
        //        }
        //    }
        //}

        private void Dfs(char ch, int max, int level, ref StringBuilder sb)
        {
            if (max == level)
            {
                sb.Append(ch);
                return;
            }
            var sb1 = new StringBuilder(sb.ToString());
            var s1 = "";
            var s2 = "";
            if (ch == 'P')
            {
                Dfs('P', max, level + 1, ref sb);
                Dfs('R', max, level + 1, ref sb);
                s1 = sb.ToString();

                Dfs('R', max, level + 1, ref sb1);
                Dfs('P', max, level + 1, ref sb1);
                s2 = sb1.ToString();
            }
            else if (ch == 'R')
            {
                Dfs('R', max, level + 1, ref sb);
                Dfs('S', max, level + 1, ref sb);
                s1 = sb.ToString();

                Dfs('S', max, level + 1, ref sb1);
                Dfs('R', max, level + 1, ref sb1);
                s2 = sb1.ToString();
            }
            else if (ch == 'S')
            {
                Dfs('P', max, level + 1, ref sb);
                Dfs('S', max, level + 1, ref sb);
                s1 = sb.ToString();

                Dfs('S', max, level + 1, ref sb1);
                Dfs('P', max, level + 1, ref sb1);
                s2 = sb1.ToString();
            }
            sb = new StringBuilder(s1.CompareTo(s2) > 0 ? s2 : s1);
        }

        private string Solve(int p, int r, int s, List<Option> list)
        {
            var min = "";
            foreach (var option in list)
                if (p == option.Counts[0] && r == option.Counts[1] && s == option.Counts[2])
                    min = min == "" || min.CompareTo(option.Order) > 0 ? option.Order : min;

            return min == "" ? Impossible : min;
        }
    }
}
