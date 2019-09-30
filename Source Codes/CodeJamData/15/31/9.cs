using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace stage1_c
{
    class Helper
    {
        internal static double[] ReadDoubles(StreamReader read)
        {
            string line = read.ReadLine();
            string[] tokens = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            double[] arr = new double[tokens.Length];
            int j = 0;
            for (int i = 0; i < tokens.Length; i++)
            {
                if (!string.IsNullOrWhiteSpace(tokens[i]))
                {
                    arr[j++] = double.Parse(tokens[i]);
                }
            }
            return arr;
        }


        internal static long[] ReadNumbersLine(StreamReader read)
        {
            string line = read.ReadLine();
            string[] tokens = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            long[] arr = new long[tokens.Length];
            int j = 0;
            for (int i = 0; i < tokens.Length; i++)
            {
                if (!string.IsNullOrWhiteSpace(tokens[i]))
                {
                    arr[j++] = long.Parse(tokens[i]);
                }
            }
            return arr;
        }

        internal static long ReadNumber(StreamReader read)
        {
            string line = read.ReadLine();

            long n = long.Parse(line);
            return n;
        }
    }
    class Program
    {

        static void Main(string[] args)
        {
            StreamReader read = new StreamReader("Input.txt");
            StreamWriter output = new StreamWriter("Output.txt");
            long T = long.Parse(read.ReadLine());

            for (int i = 0; i < T; i++)
            {
                long[] RCW = Helper.ReadNumbersLine(read);
                long R = RCW[0];
                long C = RCW[1];
                long W = RCW[2];

                long s = (C / W) * R + W;
                if ((C/W)*W ==C) s -= 1;
//                else if ((C/W)*W ==(C-1))  s -= 1;

                
                output.WriteLine("Case #" + (i + 1) + ": " + s);
            }
            read.Close();
            output.Close();
        }
    }
}
