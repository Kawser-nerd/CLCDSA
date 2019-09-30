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
                var xrc = p.getNextInt64s().ToArray();
                var x = xrc[0];
                var r = xrc[1];
                var c = xrc[2];
                bool canFill = true;

                // 平面充填できるか？
                canFill &= (r * c % x == 0);

                // 辺の長さ的に収まらない形を選べるか？
                var edge = (x + 1) / 2;
                canFill &= (edge <= r && edge <= c);

                // 7-omino以上ではないか？（充填不可能な形状を選べるか？）
                // ■■■
                // ■□■
                // ■■□
                canFill &= (x <= 6);

                // 4-ominoの妨害図形TまたはZ（幅2で常に有効）
                // ■■■
                // □■□
                // 4x3以上はどの図形をどの図形が含まれても充填可能
                if (x == 4 && (r==2||c==2))
                {
                    canFill = false;
                }
                // 5-ominoの妨害図形M（幅3かつ長さ限定）
                // ■■□
                // □■■
                // □□■
                // □□□□■■□□□□
                // □□□□□■■□□□
                // □□□□□□■□□□
                // 5x4以上はどの図形をどの図形が含まれても充填可能
                if (x == 5 && ((r == 3 && c < 10) || (c == 3 && r < 10)))
                {
                    canFill = false;
                }
                // 6-ominoの妨害図形Gun（幅3で常に有効）
                // ■■■□
                // □□■■
                // □□□■
                // 6x4以上は？
                if (x == 6 && (r == 3 || c == 3))
                {
                    canFill = false;
                }

                var answer = canFill ? "GABRIEL" : "RICHARD";
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
