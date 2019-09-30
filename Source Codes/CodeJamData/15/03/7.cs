using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace km.gcj.gcj2015
{
    class Program
    {
        static System.Diagnostics.Stopwatch sw;

        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args)
        {
            Problem p = Problem.createProblem(args);
            if (p==null) {
                return;
            }

            // 試行回数を取得し、ループする。
            long repeat = p.getNextInt64s().ToArray()[0];
            for (int i = 0; i < repeat; i++)
            {
                // MainLoop
                var cnt = p.getNextInt64s().ToArray()[1];

                var quaternions = p.getNext().ToCharArray();
                bool result = false;

                var pairValue = quaternions.Aggregate(new Quaternion(), (agg, c) => { return agg * (new Quaternion { Identifier = c }); });

                if (pairValue.Minus && pairValue.Identifier == '1' && cnt % 2 == 1)
                {
                    result = true;
                }
                else if (pairValue.Identifier == 'i' && cnt % 4 == 2)
                {
                    result = true;
                }
                else if (pairValue.Identifier == 'j' && cnt % 4 == 2)
                {
                    result = true;
                }
                else if (pairValue.Identifier == 'k' && cnt % 4 == 2)
                {
                    result = true;
                }

                result = result && !quaternions.All(x => x == 'i');
                result = result && !quaternions.All(x => x == 'j');
                result = result && !quaternions.All(x => x == 'k');

                if (result)
                {
                    result = false;
                    int counter;
                    var calcI = new Quaternion();
                    for (counter = 0; counter < quaternions.Length * Math.Min(cnt, 8); counter++)
                    {
                        calcI *= new Quaternion { Identifier = quaternions[counter % quaternions.Length] };
                        if (!calcI.Minus && calcI.Identifier == 'i')
                        {
                            break;
                        }
                    }
                    var calcJ = new Quaternion();
                    for (counter++; counter < quaternions.Length * Math.Min(cnt, 8); counter++)
                    {
                        calcJ *= new Quaternion { Identifier = quaternions[counter % quaternions.Length] };
                        if (!calcJ.Minus && calcJ.Identifier == 'j')
                        {
                            result = true;
                            break;
                        }
                    }
                }

                var answer = result ? "YES" : "NO";
                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(answer);

                if (i % 10 == 0) Console.WriteLine("{0}\t->{1}", i, sw.Elapsed);
            }
        }

        class Quaternion
        {
            public bool Minus = false;
            public char Identifier = '1';

            public static Quaternion operator *(Quaternion left, Quaternion right)
            {
                bool minus = left.Minus ^ right.Minus;
                char identifier = '1';
                if (left.Identifier=='1')
                {
                    identifier = right.Identifier;
                }
                else if (left.Identifier == right.Identifier)
                {
                    minus ^= true;
                    identifier = '1';
                }
                else if (left.Identifier == 'i' && right.Identifier == 'j')
                {
                    identifier = 'k';
                }
                else if (left.Identifier == 'j' && right.Identifier == 'i')
                {
                    minus ^= true;
                    identifier = 'k';
                }
                else if (left.Identifier == 'j' && right.Identifier == 'k')
                {
                    identifier = 'i';
                }
                else if (left.Identifier == 'k' && right.Identifier == 'j')
                {
                    minus ^= true;
                    identifier = 'i';
                }
                else if (left.Identifier == 'k' && right.Identifier == 'i')
                {
                    identifier = 'j';
                }
                else if (left.Identifier == 'i' && right.Identifier == 'k')
                {
                    minus ^= true;
                    identifier = 'j';
                }

                return new Quaternion { Identifier = identifier, Minus = minus };
            }
        }

        private static Int64 gcd(Int64 a, Int64 b)
        {
            if (a > b)
            {
                var c = a;
                a = b;
                b = c;
            }
            if (b % a == 0)
            {
                return a;
            }
            else
            {
                return gcd(a, b % a);
            }
        }
    }

    class Diner
    {
        public int Pancakes;

        public int getShares(int maxPancake)
        {
            for (int i = 0; i < Math.Sqrt(Pancakes); i++)
            {
                if ((this.Pancakes + i) / (i+1) <= maxPancake)
                {
                    return i;
                }
            }
            return 0;
        }

        public IEnumerable<EatPattern> getEatPatterns()
        {
            for (int i = 0; i < Math.Sqrt(Pancakes); i++)
            {
                yield return new EatPattern { Shares = i, Pancakes = (this.Pancakes + (i-1)) / i };
            }
            yield break;
        }
    }

    struct EatPattern
    {
        public int Shares;
        public int Pancakes;
    }
}
