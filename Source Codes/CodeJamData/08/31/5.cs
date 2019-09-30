using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.IO;
using System.Globalization;

namespace Marius.A
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
                var data = reader.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

                var P = data[0];
                var K = data[1];
                var L = data[2];

                data = reader.ReadLine().Split().Select(s => long.Parse(s)).OrderByDescending(s => s).ToArray();

                long result = 0;
                for (int i = 0; i < data.Length; i++)
                {
                    result += (i / K + 1) * data[i];
                }

                writer.WriteLine("Case #{0}: {1}", n, result);
            }

            if (reader != Console.In)
                reader.Close();
            if (writer != Console.Out)
                writer.Close();
        }
    }
}
