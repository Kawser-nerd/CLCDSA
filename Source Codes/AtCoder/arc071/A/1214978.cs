using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC071
{
    static class DebiousDocument
    {
        class SlicedString
        {
            int[] chars = new int[26];
            public SlicedString(string str)
            {
                foreach (var c in str)
                    chars[c - 'a'] += 1;
            }
            public static implicit operator SlicedString(string str)
            {
                return new SlicedString(str);
            }
            private SlicedString(int[] cs)
            {
                chars = cs;
            }
            public static SlicedString operator|(SlicedString a, SlicedString b)
            {
                var cs = new int[26];
                for (var i = 0; i < 26; ++i)
                    cs[i] = (a.chars[i] < b.chars[i]) ? a.chars[i] : b.chars[i];
                return new SlicedString(cs);
            }
            static string Repeat(char c, int t)
            {
                var sb = new StringBuilder();
                for (var i = 0; i < t; ++i)
                    sb.Append(c);
                return sb.ToString();
            }
            private int Chars(char c)
            {
                return chars[c - 'a'];
            }
            public override string ToString()
            {
                var sb = new StringBuilder();
                foreach (var c in "abcdefghijklmnopqrstuvwxyz")
                    sb.Append(Repeat(c, Chars(c)));
                return sb.ToString();
            }
        }
        static int[] To(this int from, int t)
        {
            var res = new int[t - from + 1];
            for (;from <= t; ++from)
                res[t - from] = from;
            return res;
        }
        static T FoldLeft<T>(this T[] vec, Func<T, T, T> func)
        {
            var init = vec[0];
            for (var i = 1; i < vec.Length; ++i)
                init = func(init, vec[i]);
            return init;
        }
        public static void Main()
        {
            var n = int.Parse(ReadLine().Trim());
            WriteLine(1.To(n).Select(i => new SlicedString(ReadLine().Trim())).ToArray().FoldLeft((a, b) => { return a | b; }).ToString());
        }
    }
}