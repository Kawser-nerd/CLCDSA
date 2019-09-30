using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1B11C
{
    class Program
    {
        static List<string> outLines = new List<string>();

        static string file = "C-small-attempt1";
        static void Main(string[] args)
        {
            StreamReader f = new StreamReader(file + ".in");
            string s = f.ReadLine();
            string[] subs = s.Split(' ');
            s = subs[0];
            int numCase = int.Parse(s);


            //s = subs[1];
            //int numSetup = int.Parse(s);
            //s = subs[2];
            //int someConstant = int.Parse(s);
            //for (int i = 0; i < numSetup; i++)
            //{
            ////create some sort of data structure to use
            //}
            for (int i = 0; i < numCase; i++)
            {
                // get all the data for your case here
                subs = f.ReadLine().Split(' ');
                int numpoints = int.Parse(subs[0]);
                int numlines = int.Parse(subs[1]);
                int[,] lines = new int[numlines, 2];


                subs = f.ReadLine().Split(' ');
                string[] ends = f.ReadLine().Split(' ');
                for (int k = 0; k < numlines; k++)
                {
                    lines[k, 0] = int.Parse(subs[k]) - 1;
                    lines[k, 1] = int.Parse(ends[k])-1;
                }

                computeCase(i + 1, numpoints, numlines, lines);
            }
            f.Close();



            StreamWriter output = new StreamWriter(file + ".out");
            foreach (string l in outLines)
            {
                output.WriteLine(l);
            }
            output.Close();
            System.Diagnostics.Process proc = new System.Diagnostics.Process();
            proc.StartInfo.FileName = "Upload.bat";
            proc.StartInfo.RedirectStandardError = false;
            proc.StartInfo.RedirectStandardOutput = false;
            proc.StartInfo.UseShellExecute = false;
            proc.Start();
            proc.WaitForExit();
        }
        public static void computeCase(int c, int P, int L, int[,] lines)
        {
            
            
            
            LinkedList<int> allp = new LinkedList<int>();
            for (int i = 0; i < P; i++)
                allp.AddLast(i);
            LinkedList<shape> shapes = new LinkedList<shape>();
            shapes.AddLast(new shape(allp));
            for (int i = 0; i < L; i++)
            {
                shapes = shape.addLine(shapes, lines[i, 0], lines[i, 1]);
            }
            int colors = 5000;
            foreach (shape s in shapes)
            {
                if (s.points.Count < colors)
                    colors = s.points.Count;
            }
            int[] coloring = new int[P];
            //if (P == 8 && L == 4)
            //{
            //    P = 8;
            //}
            LinkedList<shape> last = new LinkedList<shape>();
            shape next;
            while (shapes.Count > 0)
            {
                next = shape.find(last, shapes);
                next.color(coloring, colors);
                shapes.Remove(next);
                last.AddLast(next);
            }
            //foreach (shape s in shapes)
            //{
            //    s.color(coloring, colors);
            //}
            outLines.Add("Case #" + c.ToString() + ": " + colors.ToString());
            string o = coloring[0].ToString();
            for (int i = 1; i < P; i++)
                o += " " + coloring[i].ToString();
            outLines.Add(o);
        }
        public class shape
        {
            public LinkedList<int> points;
            public shape(LinkedList<int> p)
            {
                points = p;
            }
            public shape(int[] p)
            {
                points = new LinkedList<int>(p);
            }
            public static shape find(LinkedList<shape> s3, LinkedList<shape> shapes)
            {
                if (s3.Count > 0)
                {
                    foreach (shape s in s3)
                    {
                        foreach (shape s2 in shapes)
                        {
                            int c = 0;
                            foreach (int x in s.points)
                            {
                                if (s2.points.Contains(x))
                                    c++;
                            }
                            if (c > 1)
                                return s2;
                        }
                    }
                }
                else
                {
                    return shapes.First.Value;
                }
                return null;
            }
            public void color(int[] colors, int c)
            {
                SortedSet<int> unusedc = new SortedSet<int>();
                for (int i = 1; i <= c; i++)
                    unusedc.Add(i);
                int[] sc = new int[points.Count];
                int x = 0;
                foreach (int i in points)
                {
                    if (colors[i] != 0)
                        unusedc.Remove(colors[i]);
                    sc[x] = i;
                    x++;
                }
                int use = 1;
                for(int j = 0; j < sc.Length; j++)
                {
                    int i = sc[j];
                    if (colors[i] == 0)
                    {
                        if (unusedc.Count > 0)
                        {
                            colors[i] = unusedc.Min;
                            unusedc.Remove(unusedc.Min);
                        }
                        else
                        {
                            int ahead = sc[(j + 1) % sc.Length];
                            int behind = sc[(j - 1 + sc.Length) % sc.Length];
                            ahead = colors[ahead];
                            behind = colors[behind];
                            if (use == ahead)
                                use++;
                            if (use > c)
                                use = use % c;
                            if (use == behind)
                                use++;
                            if (use > c)
                                use = use % c;
                            if (use == ahead)
                                use++;
                            if (use > c)
                                use = use % c;
                            colors[i] = use;
                        }
                    }
                }
                if (unusedc.Count > 0)
                {
                    colors[colors.Length] = -1;
                }
            }
            public static LinkedList<shape> addLine(LinkedList<shape> s, int a, int b)
            {
                shape old = null;
                foreach (shape sh in s)
                {
                    if (sh.points.Contains(a) && sh.points.Contains(b))
                    {
                        old = sh;
                    }
                }
                s.Remove(old);
                shape new1 = new shape(new int[] {});
                shape new2 = new shape(new int[0]);
                foreach (int i in old.points)
                {
                    if (i <= a || i >= b)
                        new1.points.AddLast(i);
                    if (i >= a && i <= b)
                        new2.points.AddLast(i);
                }
                s.AddLast(new1);
                s.AddLast(new2);
                return s;
            }
        }
    }
}
