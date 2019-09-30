using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.IO;
using System.Globalization;

namespace Marius.B
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            Thread.CurrentThread.CurrentUICulture = CultureInfo.InvariantCulture;

            var reader = Console.In;
            var writer = Console.Out;

            if (args.Length == 2)
            {
                reader = File.OpenText(args[0]);
                writer = new StreamWriter(args[1]);
            }

            int numCases = int.Parse(reader.ReadLine().Trim());

            for (int n = 1; n <= numCases; n++)
            {
                var data = reader.ReadLine().Trim();

                long result = Count(data);

                writer.WriteLine("Case #{0}: {1}", n, result);
            }

            if (reader != Console.In)
                reader.Close();
            if (writer != Console.Out)
                writer.Close();
        }

        private static long Count(string data)
        {
            long r = 0;

            string s;
            for (int i = 0; i < data.Length; i++)
            {
                s = data.Substring(0, i + 1);
                r += Count(long.Parse(s), data.Substring(i + 1));
            }

            return r;
        }

        private static long Count(long left, string right)
        {
            if (string.IsNullOrEmpty(right))
                if (left % 2 == 0
                    || left % 3 == 0
                    || left % 5 == 0
                    || left % 7 == 0)
                    return 1;
                else
                    return 0;

            long result = 0;
            string s;
            for (int i = 0; i < right.Length; i++)
            {
                s = right.Substring(0, i + 1);
                var ss = right.Substring(i + 1);
                result += Count(left + long.Parse(s), ss);
                result += Count(left - long.Parse(s), ss);
            }

            return result;
        }
    }
}
