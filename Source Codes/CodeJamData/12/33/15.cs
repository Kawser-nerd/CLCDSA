using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodejamBoxFactory
{
    public struct holder
    {
        public Int64 count;
        public Int64 type;
        public holder(Int64 c, Int64 t)
        {
            count = c;
            type = t;
        }
    }
    class Program
    {
        public static List<holder> boxes = new List<holder>();
        public static List<holder> toys = new List<holder>();
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");

            int T = Convert.ToInt32(sr.ReadLine());

            for (int tt = 0; tt < T; tt++)
            {
                String l = sr.ReadLine();
                String[] line = l.Split(' ');
                int N = Convert.ToInt32(line[0]);
                int M = Convert.ToInt32(line[1]);

                l = sr.ReadLine();
                line = l.Split(' ');

                boxes.Clear();
                toys.Clear();

                for (int n = 0; n < N; n++)
                {
                    Int64 c = Convert.ToInt64(line[(2 * n)]);
                    Int64 type = Convert.ToInt64(line[((2 * n) + 1)]);
                    boxes.Add(new holder(c,type));
                }

                l = sr.ReadLine();
                line = l.Split(' ');

                for (int m = 0; m < M; m++)
                {
                    Int64 c = Convert.ToInt64(line[(2 * m)]);
                    Int64 type = Convert.ToInt64(line[((2 * m) + 1)]);
                    toys.Add(new holder(c, type));
                }

                //Process
                MAX = 0;
                recurse(0, 0, 0, 0, 0);

                sw.WriteLine("Case #" +(tt+1)+": " + MAX);
            }
            
            
            sw.Close();
            sr.Close();
        }
        public static Int64 MAX;
        static void recurse(int tHandle, Int64 tSpent, Int64 bSpent, int bHandle, Int64 current)
        {
            if ((tHandle >= toys.Count) || (bHandle >= boxes.Count))
            {
                if (current > MAX)
                    MAX = current;
                return;
            }
            else
            {
                //IF Matches
                if (boxes[bHandle].type == toys[tHandle].type)
                {
                    Int64 min = ((boxes[bHandle].count - bSpent) > (toys[tHandle].count - tSpent)) ? (toys[tHandle].count - tSpent) 
                        : (boxes[bHandle].count - bSpent);
                    tSpent += min;
                    bSpent += min;
                    if (boxes[bHandle].count == bSpent)
                    {
                        bHandle++;
                        bSpent = 0;
                    }
                    if (toys[tHandle].count == tSpent)
                    {
                        tHandle++;
                        tSpent = 0;
                    }
                    recurse(tHandle, tSpent, bSpent, bHandle, current+min);
                }
                else
                {
                    //IF throw Box
                    recurse(tHandle, tSpent, 0, bHandle+1, current);



                    //IF throw Toy
                    recurse(tHandle + 1, 0, bSpent, bHandle, current);
                }
            }
        }
    }
}
