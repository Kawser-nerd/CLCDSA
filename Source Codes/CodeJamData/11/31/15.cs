using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Studio.Algorithm.GoogleCodeJamTemplate
{
    public class Program
    {

        public static string FILE_PERFIX = "A-";
        public static bool IS_FILE_OUT = true;
        public static bool IS_FILE_IN = true;
        public static bool IS_SMALL = false;

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

            int R = int.Parse(splits[0]);
            int C = int.Parse(splits[1]);

            List<List<char>> tiles = new List<List<char>>();

            for (int r = 0; r < R; r++)
            {
                string rowstr = reader.ReadLine();
                List<char> row = new List<char>();
                for (int c = 0; c < C; c++)
                {
                    row.Add(rowstr[c]);
                }
                tiles.Add(row);
            }

            bool impossible = false;
            for (int r = 0; r < R; r++)
            {
                List<char> row = tiles[r];
                for (int c = 0; c < C; c++)
                {
                    char ch = row[c];
                    // left top corner.
                    if (ch == '#')
                    {
                        if (c >= C - 1 || r >= R - 1)
                        {
                            impossible = true;
                            break;
                        }
                        char ch1 = tiles[r][c + 1];
                        char ch2 = tiles[r + 1][c];
                        char ch3 = tiles[r + 1][c + 1];
                        if (ch1 != '#' || ch2 != '#' || ch3 != '#')
                        {
                            impossible = true;
                            break;
                        }

                        tiles[r][c] = '/';
                        tiles[r][c + 1] = '\\';
                        tiles[r + 1][c] = '\\';
                        tiles[r + 1][c + 1] = '/';
                    }
                }

                if (impossible == true)
                    break;
            
            }

            if (impossible)
            {
                Result += "\r\nImpossible";
            }
            else
            {

                for (int r = 0; r < R; r++)
                {
                    Result += "\r\n";
                    for (int c = 0; c < C; c++)
                    {
                        Result += tiles[r][c];
                    }
                }
            }
            O(Result);
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
