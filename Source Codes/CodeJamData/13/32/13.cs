using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ChetkoePrilozhenie
{
    class Program
    {
        static char[] vowels = new char[] { 'a', 'e', 'i', 'o', 'u' };
        static int[] dx = new int[] { 1, -1, 0, 0 };
        static int[] dy = new int[] { 0, 0, 1, -1 };
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(@"C:\gcj\B-small-attempt0.in"))
            using (StreamWriter writer= new StreamWriter(@"c:\gcj\output.txt"))
            {
                var T = Convert.ToInt32(reader.ReadLine());
                for (int i = 1; i <= T; ++i)
                {
                    var xy = reader.ReadLine().Split(new char[] { ' ', '\t' }).Select(v => Convert.ToInt32(v)).ToArray();

                    writer.Write("Case #{0}: ", i);

                    bool f = true;
                    if (xy[0] < 0)
                    {
                        xy[0] = -xy[0];
                        f = false;
                    }

                    for (int j = 0; j < xy[0]; ++j)
                    {
                        if (f)
                        {
                            writer.Write("WE");
                        }
                        else
                        {
                            writer.Write("EW");
                        }
                    }
                    f = true;
                    if (xy[1] < 0)
                    {
                        xy[1] = -xy[1];
                        f = false;
                    }
                    for (int j = 0; j < xy[1]; ++j)
                    {
                        if (f)
                        {
                            writer.Write("SN");
                        }
                        else
                        {
                            writer.Write("NS");
                        }
                    }
                    writer.WriteLine();
                }
            }
        }
    }
}
