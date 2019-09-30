using System;
using System.Globalization;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    class Program
    {
        const string InputFile = @"..\..\Input.txt";
        const string OutputFile = @"..\..\Output.txt";

        //static int[] SplitInts(string line)
        //{
        //    var tokens = line.Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries);
        //    var res = new int[tokens.Length];
        //    for (int i = 0; i < res.Length; i++)
        //        res[i] = int.Parse(tokens[i], CultureInfo.InvariantCulture);
        //    return res;
        //}

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(InputFile))
            using (StreamWriter writer = new StreamWriter(OutputFile))
            {
                int T = int.Parse(reader.ReadLine());
                for (int i = 0; i < T; i++)
                {
                    var N = reader.ReadLine();
                    writer.WriteLine("Case #{0}: {1}", i + 1, Next(N));
                }
            }
        }

        public static void Swap<T>(T[] array, int index0, int index1)
        {
            var t = array[index0];
            array[index0] = array[index1];
            array[index1] = t;
        }

        public static bool NextPermutation<T>(T[] array) where T : IComparable<T>
        {
            var n = array.Length;
            var k = n - 1;
            while (k > 0 && array[k].CompareTo(array[k - 1]) <= 0)
                k--;
            if (k > 0)
            {
                var l = n - 1;
                while (array[l].CompareTo(array[k - 1]) <= 0)
                    l--;
                Swap(array, k - 1, l);
                Array.Sort(array, k, array.Length - k);
                return true;
            }
            return false;
        }

        static string Next(string now)
        {
            var array = (new string('0', now.Length) + now).ToCharArray();
            NextPermutation(array);
            var res = new string(array).TrimStart('0');
            if (res.Length == 0)
                res = "0";
            return res;
        }
    }
}