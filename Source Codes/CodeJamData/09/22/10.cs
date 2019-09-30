using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.ComponentModel;
using System.Globalization;

namespace R1B
{
    class Program
    {
        static void Main(string[] args)
        {
            var InputFile = "input.txt";
            if (args.Length >= 1)
            {
                InputFile = args[0];
            }

            OpenFile(InputFile);
            StartCompute();

            int T = Read<int>();

            for (int t = 1; t <= T; t++)
            {
                string strN = "0" + reader.ReadLine();
                //string strN = N.ToString();
                char[] n = strN.ToCharArray();
                int i = n.Length - 2;
                while (n[i] >= n[i + 1])
                {
                    i--;
                }

                int j = n.Length - 1;
                while (n[i] >= n[j])
                {
                    j--;
                }

                char tmp = n[i];
                n[i] = n[j];
                n[j] = tmp;

                Array.Sort(n, i + 1, n.Length - i - 1);

                StringBuilder sb = new StringBuilder(n.Length);
                if (n[0] != '0') sb.Append(n[0]);
                sb.Append(n, 1, n.Length - 1);

                Console.WriteLine("Case #{0}: {1}", t, sb.ToString());
            }

            EndCompute();
        }

        // Read methods

        static int time;
        static void StartCompute()
        {
            int time = System.Environment.TickCount;
        }

        static int EndCompute()
        {
            return System.Environment.TickCount - time;
        }

        static TextReader reader;
        static Queue<string> LineBuffer;

        static void OpenFile(string FileName)
        {
            reader = new StreamReader(FileName);
            LineBuffer = new Queue<string>();
        }

        static T Read<T>() where T : struct
        {
            if (LineBuffer == null)
                throw new NullReferenceException("Word queue is not initilized.");

            if (reader == null)
                throw new NullReferenceException("Text file reader is not initialized.");

            if (LineBuffer.Count == 0)
            {
                string line = reader.ReadLine();
                foreach (string val in line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
                    LineBuffer.Enqueue(val);
            }

            if (TypeDescriptor.GetConverter(typeof(T)).CanConvertFrom(typeof(string)))
                return (T)TypeDescriptor.GetConverter(typeof(T)).ConvertFrom(null, CultureInfo.GetCultureInfo(0x0409), LineBuffer.Dequeue());

            throw new Exception("Unknown error while reading value.");
        }

    }
}