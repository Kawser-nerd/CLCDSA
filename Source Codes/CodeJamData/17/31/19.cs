using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;

namespace CodeJam
{
    public class Cake
    {
        public long H, R;
        public Cake(int r, int h)
        {
            this.H = h;
            this.R = r;
        }
    }

    class Program
    {
        static int n;
        static int k;
        
        static void Main(string[] args)
        {
            //string fileName = "in";
            //string fileName = "A-small-attempt4.in";
            string fileName = "A-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                n = NextInt();
                k = NextInt();
                var cakes = new Cake[n];
                for (int i = 0; i < n; i++)
                {
                    cakes[i] = new Cake(NextInt(), NextInt());
                }

                //cakes = cakes.OrderByDescending(x => 2 * x.H * x.R + x.R * x.R).ToArray();
                //cakes = cakes.OrderByDescending(x => 2 * x.H * x.R).ToArray();

                Array.Sort(cakes, new Comparison<Cake>((c1, c2) => (2* c2.H * c2.R).CompareTo(2 * c1.H * c1.R)));
                //Array.Sort(cakes, new Comparison<Cake>((c1, c2) => (2*c2.H * c2.R + c2.R*c2.R).CompareTo(2*c1.H * c1.R + c1.R * c1.R)));

                decimal rbest = -1;
                for (int i = 0; i < n; i++)
                {
                    var first = cakes[i];
                    decimal rr = (decimal)((2 * first.H * first.R + first.R * first.R) * Math.PI);
                    
                    var cnt = 1;
                    var ind = 0;
                    while (cnt < k && ind < n)
                    {
                        if (cakes[ind] != first && cakes[ind].R <= first.R)
                        {
                            rr += (decimal)((2 * cakes[ind].H * cakes[ind].R) * Math.PI);
                            cnt++;
                        }
                        ind++;
                    }

                    if (cnt == k && rr > rbest)
                    {
                        rbest = rr;
                    }
                }

                
                //decimal res = rr * (decimal)Math.PI;

                Console.WriteLine("Case #{0}: {1}", testCase, rbest.ToString().Replace(",", "."));
            }

            //Console.WriteLine(string.Format(NumberFormatInfo.InvariantInfo, "{0:F4}", res));

            Console.In.Close();
            Console.Out.Close();
        }

        private static char[] _defaultSplitter = new char[] { ' ', '\t' };

        private static void SetCulture()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        }

        private static char[] ReadChars(int n)
        {
            char[] buffer = new char[n];
            Console.In.ReadBlock(buffer, 0, n);
            return buffer;
        }

        private static string[] ReadAll()
        {
            return Console.In.ReadToEnd().Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords()
        {
            return ReadWords(_defaultSplitter);
        }

        private static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        private static int[] ReadInts(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray();
        }

        private static int[] ReadInts()
        {
            return ReadInts(_defaultSplitter);
        }

        private static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }

        private static double ReadDouble()
        {
            return double.Parse(Console.ReadLine(), NumberFormatInfo.InvariantInfo);
        }

        private static int _pos = 0;
        private static string[] _inputLine = new string[0];

        private static void CheckInputLine()
        {
            if (_pos >= _inputLine.Length)
            {
                _inputLine = ReadWords();
                _pos = 0;
            }
        }

        private static string NextWord()
        {
            CheckInputLine();
            return _inputLine[_pos++];
        }

        private static int NextInt()
        {
            CheckInputLine();
            return int.Parse(_inputLine[_pos++]);
        }

        private static long NextLong()
        {
            CheckInputLine();
            return long.Parse(_inputLine[_pos++]);
        }
    }
}
