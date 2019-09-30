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
        private const string PROBLEM = "B-small";
        
        private static void Solve(int T)
        {
            for (int test = 1; test <= T; test++)
            {
                int n, x, y;
                Read(out n, out x, out y);
                double res;
                var fact = new long[n+1];
                fact[0] = 1;
                for (int i = 1; i <= n; i++)
                {
                    fact[i] = fact[i-1]*i;
                }

                var sum = Math.Abs(x) + Math.Abs(y);
                var k = sum/2;
                var prevLevelCount = k*(2*(k - 1) + 1);
                if (k == 0)
                {
                    res = 1.0;
                }
                else if (prevLevelCount >= n)
                {
                    res = 0.0;
                }
                else
                {
                    n -= prevLevelCount;
                    if (n < y)
                    {
                        res = 0.0;
                    }
                    else if (n >= 4*k + 1)
                    {
                        res = 1.0;
                    }
                    else if (x == 0 && n < 4*k + 1)
                    {
                        res = 0.0;
                    }
                    else
                    {
                        var needCount = y + 1;
                        var badCount = n - needCount + 1;
                        if (badCount > 2*k)
                        {
                            res = 1.0;
                        }
                        else
                        {
                            var prop = Math.Pow(0.5, n);
                            res = 0.0;
                            for (int i = needCount; i <= n; i++)
                            {
                                res += prop*fact[n]/fact[i]/fact[n - i];
                            }
                        }
                    }
                }

                Write(string.Format(OUPUT_STRING_FORMAT, test));
                WriteLine(res);
            }
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

        const string OUPUT_STRING_FORMAT = "Case #{0}: ";

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
