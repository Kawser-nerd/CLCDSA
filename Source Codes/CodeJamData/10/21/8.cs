using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace File_Fix_it
{
    class Program
    {
        private static HashSet<string> hashSet;

        private static void AddExistingDirectory(string s)
        {
            var builder = new StringBuilder();
            var dirs = s.Split(new char[] { '/' }, StringSplitOptions.RemoveEmptyEntries);            
            foreach(var dir in dirs)
            {
                builder.Append('/').Append(dir);
                hashSet.Add(builder.ToString());
            }
        }

        private static int AddNewDirectory(string s)
        {
            var builder = new StringBuilder();
            int res = 0;
            var dirs = s.Split(new char[]{'/'}, StringSplitOptions.RemoveEmptyEntries);            
            foreach (var dir in dirs)
            {
                builder.Append('/').Append(dir);
                if (!hashSet.Contains(builder.ToString()))
                {
                    hashSet.Add(builder.ToString());
                    ++res;
                }
            }
            return res;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var reader = new StreamReader("a.txt");
            var writer = new StreamWriter("a_out.txt");

            var testNumber = long.Parse(reader.ReadLine());
            for (long test = 1; test <= testNumber; ++test)
            {
                var input = reader.ReadLine().Split(' ');
                int N = int.Parse(input[0]);
                int M = int.Parse(input[1]);

                int result = 0;
                hashSet = new HashSet<string>();

                while (N-->0)
                {
                    AddExistingDirectory(reader.ReadLine());
                }

                while (M-- > 0)
                {
                    result += AddNewDirectory(reader.ReadLine());
                }

                writer.WriteLine("Case #{0}: {1}", test, result);
            }

            reader.Close();
            writer.Close();
        }
    }
}
