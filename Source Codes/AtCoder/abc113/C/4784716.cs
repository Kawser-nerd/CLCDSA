using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var strs = str.Split(' ');
            var N = int.Parse(strs[0]);
            var M = int.Parse(strs[1]);

            var PY = new List<List<int>>();
            for (int i = 0; i < M; i++)
            {
                str = Console.ReadLine();
                strs = str.Split(' ');

                var list = new List<int>();
                list.Add(i);
                list.Add(int.Parse(strs[0]));
                list.Add(int.Parse(strs[1]));
                list.Add(0);

                PY.Add(list);
            }

            PY = PY.OrderBy(py => py[1]).ThenBy(py => py[2]).ToList();

            var prevP = PY[0][1];
            var no = 1;
            for (int i = 0; i < PY.Count; i++)
            {
                if (prevP != PY[i][1])
                {
                    no = 1;
                    prevP = PY[i][1];
                }

                PY[i][3] = no++;
            }

            PY = PY.OrderBy(py => py[0]).ToList();

            foreach (var item in PY)
            {
                Console.WriteLine(item[1].ToString().PadLeft(6, '0') + item[3].ToString().PadLeft(6, '0'));
            }
        }
    }
}