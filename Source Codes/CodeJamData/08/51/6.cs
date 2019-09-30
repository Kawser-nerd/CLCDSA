using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static int[] dx = new int[] { 0, 1, 0, -1 };
        static int[] dy = new int[] { 1, 0, -1, 0 };
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("A-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("A-large.out"))
                {
                    int TC = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= TC; tc++)
                    {
                        int L = int.Parse(sr.ReadLine());
                        List<string> inputs = new List<string>();
                        while (inputs.Count  < L * 2)
                        {
                            string[] elem = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                            inputs.AddRange(elem);
                        }

                        Dictionary<Pos, bool> dict = new Dictionary<Pos, bool>();
                        int currx = 0, curry = 0, currdir = 0;
                        for (int i = 0, lim = inputs.Count; i < lim; i += 2)
                        {
                            int count = int.Parse(inputs[i + 1]);
                            for (int j = 0; j < count; j++)
                            {
                                foreach (char c in inputs[i])
                                {
                                    switch (c)
                                    {
                                        case 'F' :
                                            int newx = currx + dx[currdir];
                                            int newy = curry + dy[currdir];
                                            dict[new Pos(currx, curry, newx, newy)] =
                                                dict[new Pos(newx, newy, currx, curry)] = true ;
                                            //Console.WriteLine("{0} {1}-{2} {3}", currx, curry, newx, newy);
                                            currx = newx;
                                            curry = newy;
                                            break;
                                        case 'R' :
                                            currdir = (currdir + 1) % 4;
                                            break;
                                        case 'L' :
                                            currdir = (currdir + 3) % 4;
                                            break;
                                    }
                                }
                            }
                        }

                        int lm = int.MaxValue;
                        int rm = int.MinValue;
                        int tm = int.MinValue;
                        int bm = int.MaxValue;
                        foreach (KeyValuePair<Pos, bool> kvp in dict)
                        {
                            lm = Math.Min(lm, Math.Min(kvp.Key.X1, kvp.Key.X2));
                            rm = Math.Max(rm, Math.Max(kvp.Key.X1, kvp.Key.X2));
                            tm = Math.Max(tm, Math.Max(kvp.Key.Y1, kvp.Key.Y2));
                            bm = Math.Min(bm, Math.Max(kvp.Key.Y1, kvp.Key.Y2));
                        }

                        //Console.WriteLine("{0} {1} {2} {3}", lm, rm, tm, bm);

                        Dictionary<Pos2, bool> res = new Dictionary<Pos2, bool>();
                        for (int i = tm , lim = bm ; i >= lim; i--)
                        {
                            bool first = true, open = true;
                            List<Pos2> hehe = new List<Pos2>();
                            for (int j = lm, lim2 = rm; j <= lim2; j++)
                            {
                                Pos x = new Pos(j, i, j, i - 1);
                                if (dict.ContainsKey ( x ))
                                {
                                    open = !open;
                                    first = false;

                                    if (!open && !first)
                                    {
                                        foreach (Pos2 p in hehe)
                                        {
                                            if ( res.ContainsKey ( p ) == false )
                                                res[p] = true;
                                        }
                                        hehe.Clear();
                                    }
                                    else if (open)
                                    {
                                        hehe.Add(new Pos2(j, i));
                                    }
                                }
                                else if ( open && !first )
                                {
                                    hehe.Add ( new Pos2(j, i) ) ;
                                }
                            }
                        }

                        for (int i = lm, lim = rm; i <= lim; i++)
                        {
                            bool first = true, open = true;
                            List<Pos2> hehe = new List<Pos2>();
                            for (int j = tm, lim2 = bm; j >= lim2; j--)
                            {
                                Pos x = new Pos(i, j, i + 1, j);
                                if (dict.ContainsKey ( x ))
                                {
                                    open = !open;
                                    first = false;

                                    if (!open && !first)
                                    {
                                        foreach (Pos2 p in hehe)
                                        {
                                            if ( res.ContainsKey ( p ) == false )
                                                res[p] = true;
                                        }
                                        hehe.Clear();
                                    }
                                    else if (open)
                                    {
                                        hehe.Add(new Pos2(i, j));
                                    }
                                }
                                else if (open && !first)
                                {
                                    hehe.Add(new Pos2(i, j));
                                }
                            }
                        }

                        sw.WriteLine("Case #{0}: {1}", tc, res.Count);
                    }
                    sw.Close(); sr.Close();
                }
            }
        }
    }

    struct Pos2
    {
        public int X, Y;
        public Pos2(int x, int y)
        {
            X = x;
            Y = y;
        }

        public override int GetHashCode()
        {
            return (X * 100 + Y).GetHashCode();
        }
        public override bool Equals(object obj)
        {
            if (obj is Pos2)
            {
                Pos2 x = (Pos2)obj;
                return x.X == X && x.Y == Y;
            }

            return false;
        }
    }
    struct Pos
    {
        public int X1, Y1, X2, Y2;

        public Pos(int x1, int y1, int x2, int y2)
        {
            X1 = x1;
            Y1 = y1;
            X2 = x2;
            Y2 = y2;
        }

        public override int GetHashCode()
        {
            return (X1 * 1000000 + Y1 * 10000 + X2 * 100 + Y2).GetHashCode();
        }

        public override bool Equals(object obj)
        {
            if (obj is Pos)
            {
                Pos x = (Pos)obj;
                return x.X1 == X1 && x.Y1 == Y1 && x.X2 == X2 && x.Y2 == Y2;
            }

            return false;
        }
    }
}
