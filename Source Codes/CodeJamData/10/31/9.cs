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

            string[] splits;

            // int n = int.Parse(splits[0]);
            // int m = int.Parse(splits[1]);
            int N = int.Parse(reader.ReadLine());

            int[] A = new int[N];
            int[] B = new int[N];

            for (int i = 0; i < N; i++)
            { 
                splits = reader.ReadLine().Split(SPLITERS);;
                A[i] = int.Parse(splits[0]);
                B[i] = int.Parse(splits[1]);
            }

            int count = 0;

            for (int i = 0; i < N; i++)
            {
                int a = A[i];
                int b = B[i];

                for (int x = 0; x < i; x++)
                {
                    int a0 = A[x];
                    int b0 = B[x];

                    if ((a - a0) * (b - b0) < 0)
                    {
                        count++;   
                    }
                }
            }

            O(Result + count.ToString());
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
