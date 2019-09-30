using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace GoogleJam
{
    class Program
    {
        private const string PROBLEM = "A-large";
        
        private static void Solve(int T)
        {
            for (int test = 1; test <= T; test++)
            {
                int a,n;
                Read(out a, out n);
                var sizes = ReadIntArray();
                sizes.Sort();
                int res;
                res = a == 1 ? n : Go(0, a, sizes);

                WriteLine(string.Format(OUPUT_STRING_FORMAT, test, res));
            }
        }

        private static int Go(int index, int a, List<int> sizes)
        {
            var res = 0;
            for (int i = index; i < sizes.Count; i++)
            {
                var size = sizes[i];
                if (a > size)
                    a += size;
                else
                {
                    var count = 0;
                    var temp = a;
                    while (temp <= size)
                    {
                        temp += temp - 1;
                        count++;
                    }
                    temp += size;
                    res += Math.Min(sizes.Count - i, count + Go(i + 1, temp, sizes));
                    break;
                }
            }
            return res;
        }

        static void Main(string[] args)
        {
            Console.SetIn(new StreamReader(String.Format(@"..\..\..\..\{0}.in", PROBLEM)));
            if (!Debugger.IsAttached)
                Console.SetOut(new StreamWriter(String.Format(@"..\..\{0}.out", PROBLEM)));

            var T = ReadInt();
            Solve(T);   

            Console.In.Close();
            Console.Out.Flush();
            Console.Out.Close();
         
            if (Debugger.IsAttached)
            {
                Console.SetIn(new StreamReader(Console.OpenStandardInput()));
                Console.ReadLine();
            }
        }

        const string OUPUT_STRING_FORMAT = "Case #{0}: {1}";

        #region Reader

        private static string Read()
        {
            return Console.ReadLine();
        }
        
        private static void Read<T>(out T a1, out T a2)
        {
            var input = ReadArray();
            a1 = (T)Convert.ChangeType(input[0], typeof(T));
            a2 = (T)Convert.ChangeType(input[1], typeof(T));
        }

        private static void Read<T>(out T a1, out T a2, out T a3)
        {
            var input = ReadArray();
            a1 = (T)Convert.ChangeType(input[0], typeof(T));
            a2 = (T)Convert.ChangeType(input[1], typeof(T));
            a3 = (T)Convert.ChangeType(input[2], typeof(T));
        }

        private static void Read<T>(out T a1, out T a2, out T a3, out T a4)
        {
            var input = ReadArray();
            a1 = (T)Convert.ChangeType(input[0], typeof(T));
            a2 = (T)Convert.ChangeType(input[1], typeof(T));
            a3 = (T)Convert.ChangeType(input[2], typeof(T));
            a4 = (T)Convert.ChangeType(input[3], typeof(T));
        }

        private static int ReadInt()
        {
            return Int32.Parse(Read());
        }

        private static long ReadLong()
        {
            return long.Parse(Read());
        }

        private static double ReadDouble()
        {
            return double.Parse(Read(), CultureInfo.InvariantCulture);
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(Read(), typeof(T));
        }

        private static string[] ReadArray()
        {
            var readLine = Console.ReadLine();
            if (readLine != null)
                return readLine.Split(' ');

            throw new ArgumentException();
        }

        private static List<int> ReadIntArray()
        {
            return ReadArray().Select(Int32.Parse).ToList();
        }

        private static List<long> ReadLongArray()
        {
            return ReadArray().Select(long.Parse).ToList();
        }

        private static List<double> ReadDoubleArray()
        {
            return ReadArray().Select(d => double.Parse(d, CultureInfo.InvariantCulture)).ToList();
        }

        private static List<T> ReadArray<T>()
        {
            return ReadArray().Select(x => (T)Convert.ChangeType(x, typeof(T))).ToList();
        }
        
        private static void WriteLine(double value)
        {
            Console.WriteLine(value.ToString(CultureInfo.InvariantCulture));
        }

        private static void WriteLine(double value, string stringFormat)
        {
            Console.WriteLine(value.ToString(stringFormat, CultureInfo.InvariantCulture));
        }

        private static void WriteLine<T>(T value)
        {
            Console.WriteLine(value);
        }
        
        private static void Write(double value)
        {
            Console.Write(value.ToString(CultureInfo.InvariantCulture));
        }
        
        private static void Write(double value, string stringFormat)
        {
            Console.Write(value.ToString(stringFormat, CultureInfo.InvariantCulture));
        }

        private static void Write<T>(T value)
        {
            Console.Write(value);
        }

        #endregion


    }
}
