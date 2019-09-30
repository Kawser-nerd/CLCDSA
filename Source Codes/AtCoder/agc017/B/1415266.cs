using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.AGC017
{
    class ModerateDifferences
    {
        public static void Main()
        {
            var nabcd = ReadLine().Trim().Split(' ').Select(_ => long.Parse(_)).ToArray();
            var n = nabcd[0]; var a = nabcd[1]; var b = nabcd[2]; var c = nabcd[3]; var d = nabcd[4];
            var yes = "YES"; var no = "NO";
            var option = BinSearch(_ =>
           {
               return new Range(a + c * _ - d * (n - _ - 1), a + d * _ - c * (n - _  - 1)).CompareTo(b);
           }, 0, n);
            if (option.HasValue) {
                WriteLine(yes);
            }
            else {
                WriteLine(no);
            }
            /*
            for (var i = 0; i <= n; ++i) {
                if (a + c * i - d * (n - i - 1) <= b && b <= a + d * i - c * (n - i - 1)) {
                    WriteLine(yes);
                    return;
                }
            }
            WriteLine(no);
            */
        }
        static Option<long> BinSearch(Func<long, Compare> func, long left, long right)

        {
            if (left >= right) return func(left) == Compare.Contain ? Option<long>.Just(left) : Option<long>.None();
            else {
                var mid = (left + right) / 2;
                if (func(mid) != Compare.Larger) {
                    return BinSearch(func, left, mid);
                }
                else {
                    return BinSearch(func, mid + 1, right);
                }
            }
        }
        class Option<T>
        {
            public T Value { get; private set; }
            public bool HasValue { get; private set; }
            public static Option<T> Just(T val)
            {
                return new Option<T> { Value = val, HasValue = true };
            }
            public static Option<T> None()
            {
                return new Option<T> { HasValue = false };
            }
        }
        enum Compare
        {
            Larger, Smaller, Contain
        }
        struct Range
        {
            public Range(long from, long to)
            {
                From = from; To = to;
            }
            public long From { get; private set; }
            public long To { get; private set; }
            public Compare CompareTo(long other)
            {
                if (other < From) return Compare.Smaller;
                else if (other > To) return Compare.Larger;
                else return Compare.Contain;
            }
        }
    }
}