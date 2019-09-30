using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Solutions
{
    class GCJ20142A : Problem
    {
        public static void Main(String[] args)
        {
            var self = new GCJ20142A();
            self.Run();
        }


        public override void ProcessOne()
         {
            var abk = this.ReadLongList();
            long result = 0;
            var small = abk[0] < abk[1] ? abk[0] : abk[1];
            var large = abk[0] < abk[1] ? abk[1] : abk[0];
                
            for (var i = 0; i < small; i++)
            {
                var twice = i & i;
                if (twice < abk[2])
                {
                    result += large;
                    continue;
                }

                for (var j = 0; j < large; j++)
                {
                    var res = i & j;
                    if (res < abk[2])
                    {
                        result++;
                    }
                }
            }
            this.WriteLine(result.ToString());
         }


        private int NrOfCombinations(long Ma, long Mb, List<int> winningPositions, long winning)
        {
            var countPossibilitiesA = 0;


            var countPossibilitiesB = 0;
            return -1;

        }

        public long toBits(List<int> positions)
        {
            long result = 0;
            for (int i = 0; i < positions.Count(); i++)
            {
                result += (long)Math.Pow(2, positions[i]);
            }
            return result;
        }

        public List<int> ToBitPositions(long value)
        {
            var positions = new List<int>();
            while (value != 0)
            {
                var power = (Int32)Math.Floor(Math.Log(value, 2));
                value -= (long)Math.Pow(2, power);
                positions.Add(power);
            }

            return positions;
        }
    }

    abstract class Problem
    {
        
        private readonly TextWriter writer;

        protected Problem(String output = "test.out")
        {
            this.writer = new StreamWriter(output);
        }

        public int CurrentCase { get; private set; }

        public virtual void Run()
        {
            var firstline = Console.ReadLine();
            if (firstline == null)
                throw new Exception("No integer found");
            var testcases = Int32.Parse(firstline);
            for (int i = 1; i <= testcases; i++)
            {
                this.CurrentCase = i;
                this.ProcessOne();
            }
        }

        public string ReadLine()
        {
            var ret = Console.ReadLine();
            if (ret == null)
                throw new Exception("No line found");
            return ret;
        }

        public T[] ReadList<T>(Func<String, T> f, char seperator = ' ')
        {
            var line = Console.ReadLine();
            if (line == null)
                throw new Exception("No list found");
            var split = line.Split(new char[] { seperator });
            var ret = new T[split.Length];
            for (int i = 0; i < split.Length; i++)
            {
                ret[i] = f(split[i]);
            }
            return ret;
        }

        public BigInteger ReadBigInteger()
        {
            var line = Console.ReadLine();
            if (line == null)
                throw new Exception("No BigInteger found");
            return BigInteger.Parse(line);
        }

        public int ReadInt()
        {
            var line = Console.ReadLine();
            if (line == null)
                throw new Exception("No integer found");
            return Int32.Parse(line);
        }

        public int[] ReadIntList(char seperator = ' ')
        {
            return ReadList(Int32.Parse, seperator);
        }

        public long[] ReadLongList(char seperator = ' ')
        {
            return ReadList(long.Parse, seperator);
        }

        public char[,] ReadMultiCharArray(int x, int y)
        {
            var ret = new char[x, y];
            for (int j = 0; j < x; j++)
            {
                var line = Console.ReadLine();
                if (line == null)
                    throw new Exception("No list found");
                for (int i = 0; i < line.Length; i++)
                {
                    ret[j, i] = line[i];
                }
            }
            return ret;
        }

        public TwoDimNode<T>[,] ReadTwoDimMaze<T, T2>(Func<string, T2> f, Action<T2, TwoDimNode<T>> f2, int x, int y, TwoDimNode<T>[,] squares = null, char seperator = ' ')
        {
            var ret = squares ?? new TwoDimNode<T>[x, y];

            for (int j = 0; j < x; j++)
            {
                var line = Console.ReadLine();
                if (line == null)
                    throw new Exception("No list found");
                var split = line.Split(new char[] { seperator });
                for (int i = 0; i < split.Length; i++)
                {
                    if (ret[j, i] == null)
                        ret[j, i] = new TwoDimNode<T>(ret);
                    f2(f(split[i]), ret[j, i]);
                }
            }
            return ret;
        }

        public T[,] ReadMultiArray<T>(Func<string, T> f, int x, int y, T[,] ret = null, char seperator = ' ')
        {
            if (ret == null)
                ret = new T[x, y];
            for (int j = 0; j < x; j++)
            {
                var line = Console.ReadLine();
                if (line == null)
                    throw new Exception("No list found");
                var split = line.Split(new char[] { seperator });
                for (int i = 0; i < split.Length; i++)
                {
                    ret[j, i] = f(split[i]);
                }
            }
            return ret;
        }

        public double[] ReadDoubleList(char seperator = ' ')
        {
            return ReadList(Double.Parse, seperator);
        }

        public string[] ReadStringList(char seperator = ' ')
        {
            var line = Console.ReadLine();
            if (line == null)
                throw new Exception("No list found");
            var split = line.Split(new char[] { seperator });
            return split;
        }

        public void WriteLine(string value)
        {
            string val = "Case #" + this.CurrentCase + ": " + value;
            Console.WriteLine(val);
            this.writer.WriteLine(val);
            this.writer.Flush();
        }

        public void WriteLineNoCase(string value)
        {
            Console.WriteLine(value);
            this.writer.WriteLine(value);
            this.writer.Flush();
        }

        public abstract void ProcessOne();

        internal class TwoDimNode<T>
        {
            public TwoDimNode(TwoDimNode<T>[,] twoDims)
            {
                this.Squares = twoDims;
            }

            /// <summary>
            /// The row this square is in. This square is twoDims[X,Y]
            /// In the input, every input on the same line has the same value of X
            /// </summary>
            public int X { get; set; }

            /// <summary>
            /// The column this square is in. This square is twoDims[X,Y]
            /// In the input, every input on the same line has a different Y value
            /// </summary>
            public int Y { get; set; }

            public T Data { get; set; }

            public TwoDimNode<T>[,] Squares { get; private set; }

            public TwoDimNode<T> Down()
            {
                return X + 1 < this.Squares.GetLength(0) ? this.Squares[X + 1, Y] : null;
            }

            public TwoDimNode<T> Up()
            {
                return X - 1 >= 0 ? this.Squares[X - 1, Y] : null;
            }

            public TwoDimNode<T> Left()
            {
                return Y - 1 >= 0 ? this.Squares[X, Y - 1] : null;
            }

            public TwoDimNode<T> Right()
            {
                return Y + 1 < this.Squares.GetLength(1) ? this.Squares[X, Y + 1] : null;
            }
        }
    }
}
