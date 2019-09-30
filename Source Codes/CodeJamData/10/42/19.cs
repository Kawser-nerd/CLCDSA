using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;
using System.Threading;

namespace B
{
    class ProgramB
    {
        #region common
        public TextReader Input { get; set; }
        public TextWriter Output { get; set; }
        NumberFormatInfo nfi = NumberFormatInfo.InvariantInfo;

        public ProgramB()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            Input = Console.In;
            Output = Console.Out;
        }


        static void Main(string[] args)
        {
            ProgramB p = new ProgramB();
            if (args.Length > 0)
            {
                string inFile = args[0] + ".in";
                string outFile = args[0] + ".out";
                p.Input = new StreamReader(inFile);
                p.Output = new StreamWriter(outFile);
            }
            p.Run();
        }

        private void SkipWs()
        {
            while (true)
            {
                int c = Input.Peek();
                if (c != -1 && Char.IsWhiteSpace((char)c))
                    Input.Read();
                else
                    break;
            }
        }

        private string ReadStringUntilWs()
        {
            StringBuilder sb = new StringBuilder();
            SkipWs();
            while (true)
            {
                int c = Input.Peek();
                if (c == -1 || Char.IsWhiteSpace((char)c))
                    break;
                else
                    sb.Append((char)Input.Read());
            }
            return sb.ToString();
        }

        private string[] ReadStringArray(int count)
        {
            string[] res = new string[count];
            for (int i = 0; i < count; i++)
            {
                res[i] = ReadStringUntilWs();
            }
            return res;
        }

        private char ReadChar()
        {
            SkipWs();
            return (char)Input.Read();
        }

        private int ReadInt()
        {
            String s = ReadStringUntilWs();
            return int.Parse(s);
        }

        private int[] ReadIntArray()
        {
            SkipWs();
            return Input.ReadLine().Split()
                .Where(s => !String.IsNullOrEmpty(s)).Select(s => Convert.ToInt32(s)).ToArray();
        }

        private int[] ReadIntArray(int count)
        {
            int[] res = new int[count];
            for (int i = 0; i < count; i++)
            {
                res[i] = ReadInt();
            }
            return res;
        }

        private long ReadLong()
        {
            String s = ReadStringUntilWs();
            return long.Parse(s);
        }

        private double ReadDouble()
        {
            String s = ReadStringUntilWs();
            return double.Parse(s, nfi);
        }

        private double[] ReadDoubleArray()
        {
            SkipWs();
            return Input.ReadLine().Split().Select(s => Convert.ToDouble(s, nfi)).ToArray();
        }

        private double[] ReadDoubleArray(int count)
        {
            double[] res = new double[count];
            for (int i = 0; i < count; i++)
            {
                res[i] = ReadDouble();
            }
            return res;
        }


        private void WriteInt(int value)
        {
            Output.Write(value.ToString(CultureInfo.InvariantCulture));
        }

        private void WriteDouble(double value)
        {
            Output.Write(value.ToString(CultureInfo.InvariantCulture));
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <param name="format">e.g. "0.00" for two decimal places</param>
        private void WriteDouble(double value, string format)
        {
            Output.Write(value.ToString(format, CultureInfo.InvariantCulture));
        }

        #endregion

        int[] M;
        int[][] prices;
        bool[][] attend;
        private long MinSol(int r, int m, int skips)
        {
            long cp = prices[r][m];

            if (r == 0)
            {
                if (M[m*2] < skips || M[m*2+1] < skips)
                    return 2000000;
                else if (Math.Min(M[m*2], M[m*2+1]) == skips)
                    return cp;
                else
                    return 0;

            }

            long op1 = cp + MinSol(r - 1, m * 2, skips) + MinSol(r - 1, m * 2 + 1, skips);
            long op2 = MinSol(r - 1, m * 2, skips+1) + MinSol(r - 1, m * 2 + 1, skips+1);

            return Math.Min(op1, op2);
        }

        public void Run()
        {
            int TestCaseNum = ReadInt();
            for (int testCase = 0; testCase < TestCaseNum; testCase++)
            {
                int P = ReadInt();
                int N = 1 << P;

                M = ReadIntArray(N);
                prices = new int[P][];
                attend = new bool[P][];
                for (int i = 0; i < P; i++)
                {

                    prices[i] = ReadIntArray(1 << (P - i - 1));
                    attend[i] = new bool[1 << (P - i - 1)];
                }


                long result = MinSol(P-1, 0, 0);


                Output.WriteLine("Case #{0}: {1}", testCase + 1, result);
            }

            Output.Close();
        }


    }

}
