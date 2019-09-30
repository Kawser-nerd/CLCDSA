using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoderABC115
{
    class Program
    {
        public static long[] powarray = new long[1000];
        public static long Pow(long a, long b)
        {
            return
                (powarray[b] != 0)? powarray[b] :
                (b == 0)? powarray[b] = 1 :
                powarray[b] = a * Pow(a, b - 1);
        }
        public static long Eat(long num, int burgerLevel)
        {
            if (burgerLevel == 0) return 1;
            if (num == 1) return 0;
            num--;

            long eatNum = 0;
            if (num <= (Pow(2, burgerLevel + 1) - 3)) return eatNum + Eat(num, burgerLevel - 1);
            eatNum += Pow(2, burgerLevel) - 1;
            num -= Pow(2, burgerLevel + 1) - 3;

            if (num == 1) return eatNum + 1;
            num--;
            eatNum++;

            if (num <= (Pow(2, burgerLevel + 1) - 3)) return eatNum + Eat(num, burgerLevel - 1);
            eatNum += Pow(2, burgerLevel) - 1;
            num -= Pow(2, burgerLevel + 1) - 3;

            num--;
            return eatNum;
        }
        public static void Main(string[] args)
        {
            for (int i = 0; i < 1000; i++) powarray[i] = 0;
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            long X = long.Parse(s[1]);
            Console.WriteLine(Eat(X, N));
        }
    }
}