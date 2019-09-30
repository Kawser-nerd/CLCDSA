using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

namespace ConsoleApp2
{
    struct Point { public int x, y; };
    class Program {
        static int Manh(Point x,Point y) {
            return Math.Abs(x.x - y.x) + Math.Abs(x.y - y.y);
        }

        static void Main(string[] Args) {
            var l = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();


            var StudentPoint = new List<Point>();
            List<int> tmp;
            for (int i = 0; i < l[0]; i++) {
                tmp = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();
                StudentPoint.Add(new Point { x = tmp[0], y = tmp[1] });
            }
            var CheckPoint = new List<Point>();
            for (int i = 0; i < l[1]; i++) {
                tmp = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();
                CheckPoint.Add(new Point { x = tmp[0], y = tmp[1] });
            }

            List<int> Ans = new List<int>();
            List<int> dist;
            for(int i = 0;i < l[0]; i++) {
                dist = new List<int>();
                for (int j = 0; j < l[1]; j++) {
                    dist.Add(Manh(StudentPoint[i], CheckPoint[j]));
                }
                Ans.Add(dist.IndexOf(dist.Min()));
            }

            foreach (var e in Ans)
                WriteLine(e + 1);

            ReadLine();
        }
    }
}