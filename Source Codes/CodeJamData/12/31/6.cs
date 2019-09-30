using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var p = new Program();
            p.Run();
        }

        private void Run()
        {
            //Assume data is on the desktop called input.txt
            var s = new StreamReader(@"C:\Users\richard\Desktop\input.txt");

            var caseNumber = 0;
            var sb = new StringBuilder();

            var start = DateTime.Now;

            //Ignore the first line - just tells us how many tests there are
            s.ReadLine();
            var sb1 = new StringBuilder();
            while (!s.EndOfStream)
            {
                caseNumber++;

                #region Main code bit

                //var line = s.ReadLine().Split(' ');
                var N = int.Parse(s.ReadLine());

                var inheritFrom = new Dictionary<int, List<int>>();
                var tops = new List<int>();
                for (var i = 0; i < N; i++)
                {
                    var l = new List<int>();
                    var line = s.ReadLine().Split(' ');
                    var M = int.Parse(line[0]);
                    if (M == 0) tops.Add(i + 1);
                    for (var j = 0; j < M; j++)
                    {
                        l.Add(int.Parse(line[1 + j]));
                    }
                    inheritFrom.Add(i, l);
                }

                //Check for each head
                var isDone = false;
                foreach (var top in tops)
                {
                    var d = new List<int>();
                    isDone = inherited(inheritFrom, top, d, true);
                    if (isDone)
                    {
                        break;
                    }
                }

                sb.Append("Case #");
                sb.Append(caseNumber);
                sb.Append(": ");
                sb.Append(isDone ? "Yes" : "No");
                sb.AppendLine();

                #endregion
            }
            sb.AppendLine(sb1.ToString());

            //Write output file
            var sw = new StreamWriter(@"C:\Users\richard\Desktop\output.txt", false);
            sw.Write(sb.ToString());
            sw.Flush();
        }

        bool inherited(Dictionary<int, List<int>> a, int from, List<int> done, bool isTop)
        {
            var nextNodes = a.Where(x => x.Value.Contains(from)).Select(x => x.Key + 1).ToList();

            if (nextNodes.Count == 0)
            {
                return false;
            }

            done.AddRange(nextNodes);
            if (done.Distinct().Count() < done.Count) return true;
            foreach (var nextNode in nextNodes)
            {
                if (inherited(a, nextNode, done, false)) return true;
            }
            return false;
        }
    }
}
