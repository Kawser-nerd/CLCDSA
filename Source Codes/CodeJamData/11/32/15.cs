using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Studio.Algorithm.GoogleCodeJamTemplate
{
    public class Program
    {

        public static string FILE_PERFIX = "B-";
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

            long L = long.Parse(splits[0]);
            long t = long.Parse(splits[1]);
            long N = long.Parse(splits[2]);
            long C = long.Parse(splits[3]);

            List<int> a = new List<int>();
            List<int> ar = new List<int>();

            long k = N / C;
            long m = N % C;

            long sum = 0;
            long rem = 0;
            for (int i = 0; i < C; i++)
            {
                int ai = int.Parse(splits[4 + i]);
                sum += ai;
                a.Add(ai);

                if (i < m)
                {
                    rem += ai;
                    ar.Add(ai);
                }
            }

            long total = sum * k + rem;
            long totalTime = total * 2;

            // build boosters

            // List<int> am = new List<int>();

            if (totalTime > t)
            {
                long leftD = total - t / 2;
                long leftK = (leftD - rem) / sum;
                int leftM = (int)((leftD - rem) % sum);

                int c = a.Count - 1;
                while (leftM > a[c])
                {
                    ar.Add(a[c]);
                    leftM -= a[c];
                    c--;
                }
                if (leftM > 0)
                    ar.Add(leftM);

                ar.Sort();
                // find longest
                if(leftK > 0)
                    a.Sort();

                while (L > 0)
                {
                    if (ar.Count == 0 && a.Count == 0)
                        break;

                    if (leftK > 0 && a.Count > 0)
                    {
                        int arLast = 0;
                        if(ar.Count > 0) arLast = ar.Last();
                        int alast = a.Last();
                        if (alast > arLast)
                        {
                            if (L > leftK)
                            {
                                totalTime -= (alast * leftK);
                                L -= leftK;
                                // remove a.last
                                a.RemoveAt(a.Count - 1);
                            }
                            else
                            {
                                // use all 
                                totalTime -= (alast * L);
                                L = 0;
                                break;
                            }
                        }
                        else if (ar.Count > 0)
                        {
                            L--;
                            totalTime -= ar.Last();
                            ar.RemoveAt(ar.Count - 1);
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if (ar.Count > 0)
                    {
                        L--;
                        totalTime -= ar.Last();
                        ar.RemoveAt(ar.Count - 1);
                    }
                    else
                    {
                        break;
                    }
                }
            }

            O(Result + totalTime);
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
