using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MiscLibrary;
using System.IO;

namespace CodeJam_2015_R1A_3
{
    class Program
    {
        static int Solve(List<PointInt32> list, int num)
        {
            List<double> l = new List<double>();
            for (int i = 0; i < list.Count; i++) {
                if (i == num) continue;
                l.Add(Math.Atan2(list[i].X - list[num].X, list[i].Y - list[num].Y) + Math.PI);
            }
            l.Sort();

            int minToRemove = l.Count;

            int startNum = 0;
            for (int endNum = 0; endNum < l.Count * 2; endNum++) {
                if (startNum >= l.Count) break;
                int realEnd = endNum;
                if (realEnd >= l.Count) realEnd -= l.Count;

                double realEndValue = l[realEnd];
                if (realEnd != endNum) realEndValue += 2 * Math.PI;
                double realStartValue = l[startNum];
                while (realEndValue - realStartValue > Math.PI+0.0000000001) {
                    startNum++;
                    if (startNum >= l.Count) return minToRemove;
                    realStartValue = l[startNum];
                }
                int save = endNum - startNum + 1;
                int remove = l.Count - save;
                if (remove < minToRemove) minToRemove = remove;
            }
            return minToRemove;
        }

        
        static int[] Solve(List<PointInt32> list)
        {
            int[] res = new int[list.Count];
            for (int i = 0; i < list.Count; i++)
            {
                res[i] = Solve(list, i);
            }

            return res;
        }

        static void Main(string[] args)
        {
            var lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2015\Round1A\Task3_input\input.txt");
            int caseNum = 0;
            int lineNum = 1;
            while (caseNum < Int32.Parse(lines[0]))
            {
                caseNum++;
                int treesCount = Int32.Parse(lines[lineNum]);
                List<PointInt32> trees = new List<PointInt32>();
                for (int b = 0; b < treesCount; b++)
                {
                    lineNum++;
                    var arr = lines[lineNum].Split(' ').Select(Int32.Parse).ToArray();
                    trees.Add(new PointInt32(arr[0], arr[1]));
                }
                lineNum++;
                int[] res = Solve(trees);
                Console.WriteLine("Case #{0}:", caseNum);
                foreach (var t in res)
                {
                    Console.WriteLine(t);
                }
            }
//            Console.WriteLine();

        }
    }
}
