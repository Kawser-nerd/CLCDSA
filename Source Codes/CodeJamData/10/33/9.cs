using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Drawing;

namespace Studio.Algorithm.GoogleCodeJamTemplate
{
    public class Program
    {

        public static string FILE_PERFIX = "B-";
        public static bool IS_FILE_OUT = true;
        public static bool IS_FILE_IN = true;
        public static bool IS_SMALL = true;

        public static char[] SPLITERS = new char[] { ' ', '\t' };


        public static void Main(string[] args)
        {
            GoogleCodeJam();
            Console.ReadKey();
        }

        /// <summary>
        /// Algorithm should be writen here for each test case
        /// </summary>
        public static void TestCase(int Index, TextReader reader)
        {
            string CaseNo = string.Format("Case #{0}: ", Index);
            string Result = CaseNo;

            string[] splits = reader.ReadLine().Split(SPLITERS);

            int m = int.Parse(splits[0]);
            int n = int.Parse(splits[1]);

            int[,] B = new int[m, n];
            for (int y = 0; y < m; y++)
            {
                string line = reader.ReadLine();
                for (int x = 0; x < n / 4; x++)
                {
                    int hex = int.Parse(line[x].ToString(), System.Globalization.NumberStyles.HexNumber);
                    B[y, x * 4 + 0] = (hex & 0x08) >> 3;
                    B[y, x * 4 + 1] = (hex & 0x04) >> 2;
                    B[y, x * 4 + 2] = (hex & 0x02) >> 1;
                    B[y, x * 4 + 3] = (hex & 0x01) >> 0;
                }
            }
            OutputBoard(B, m, n);
            Rectangle rect;
            Dictionary<int, int> dict = new Dictionary<int, int>();
            while (true)
            {
                rect = FindBoard(B, m, n);
                if (rect.Equals(Rectangle.Empty))
                    break;

                int size = rect.Height;
                if (dict.Keys.Contains(size))
                    dict[size]++;
                else
                    dict.Add(size, 1);

                for (int y = 0; y < size; y++)
                    for (int x = 0; x < size; x++)
                        B[y + rect.Y, x + rect.X] = -1;
                //if(size >= 2) OutputBoard(B, m, n);
            }
            O(Result + dict.Keys.Count);
            List<int> l = new List<int>();
            l.AddRange(dict.Keys);
            l.Sort();
            for (int i = l.Count - 1; i >= 0; i--)
                O(l[i].ToString() + " " + dict[l[i]].ToString());

        }

        public static Rectangle FindBoard(int[,] B, int m, int n)
        {
            Rectangle rect = Rectangle.Empty;
            for (int y = 0; y < m; y++)
            {
                for (int x = 0; x < n; x++)
                {
                    if (B[y, x] < 0) continue;
                    Point start = new Point(x, y);

                    int color = B[y, x];
                    int size = 1;
                    while (true)
                    {
                        if (size + x >= n || size + y >= m)
                            break;
                        color = (size % 2 == 0) ? B[y, x] : 1 - B[y, x];
                        bool invalid = false;
                        for (int px = x; px < x + size; px++)
                        {
                            if (B[y + size, px] != color)
                            {
                                invalid = true;
                                break;
                            }
                            color = 1 - color;
                        }
                        if (invalid) break;

                        color = (size % 2 == 0) ? B[y, x] : 1 - B[y, x];
                        for (int py = y; py < y + size; py++)
                        {
                            if (B[py, x + size] != color)
                            {
                                invalid = true;
                                break;
                            }
                            color = 1 - color;
                        }
                        if (invalid) break;

                        if (B[y + size, x + size] != B[y, x]) break;

                        size++;
                    }

                    if ((size > rect.Height)
                        || (size == rect.Height && y < rect.Y)
                        || (size == rect.Height && y == rect.Y && x < rect.X))
                           rect = new Rectangle(x, y, size, size);
                }
            }
            return rect;
        }

        public static void OutputBoard(int[,] B, int m, int n)
        {
            for (int y = 0; y < m; y++)
            {
                for (int x = 0; x < n; x++)
                {
                    if(B[y, x] < 0)
                        Console.Write(".");
                    else
                        Console.Write(B[y, x]);
                }
                Console.WriteLine();
            }
        }

        public static void GoogleCodeJam()
        {
            FileStream fs = null;
            TextReader sr = null;
            if (true == Program.IS_FILE_IN)
            {
                // open file
                string fn = FILE_PERFIX + "large.in";
                if (IS_SMALL) fn = FILE_PERFIX + "small.in";
                fs = File.Open(fn, FileMode.Open);
                sr = new StreamReader(fs);
            }
            else
            {
                sr = Console.In;
            }
            // read test case count
            string line = sr.ReadLine();
            int n = int.Parse(line);
            // for each test case
            for (int cs = 1; cs <= n; cs++)
            {
                TestCase(cs, sr);
            }
            if (true == IS_FILE_IN)
            {
                // close file
                if (null != sr) sr.Close();
                if (null != fs) fs.Close();
            }
        }

        /// <summary>
        /// Short for OutputLine
        /// </summary>
        /// <param name="s"></param>
        public static void O(string format, params object[] args)
        {
            Program.OutputLine(string.Format(format, args));
        }

        public static void O(string s)
        {
            Program.OutputLine(s);
        }

        static bool IS_FIRST_RUN = true;

        public static void OutputLine(string s)
        {
            System.Console.WriteLine(s);
            // write to file ?
            if (true == IS_FILE_OUT)
            {
                string fn = FILE_PERFIX + "large.out";
                if (IS_SMALL) fn = FILE_PERFIX + "small.out";
                FileStream fs = null;
                StreamWriter sw = null;
                try
                {
                    if (true == IS_FIRST_RUN)
                    {
                        IS_FIRST_RUN = false;
                        fs = File.Open(fn, FileMode.Create);
                    }
                    else
                    {
                        fs = File.Open(fn, FileMode.Append);
                    }
                    sw = new StreamWriter(fs);
                    sw.WriteLine(s);
                }
                catch (Exception e)
                {
                    System.Console.WriteLine(e.StackTrace);
                }
                finally
                {
                    // close file
                    if (null != sw) sw.Close();
                    if (null != fs) fs.Close();
                }
            }
        }

    }
}
