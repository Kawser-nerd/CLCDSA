using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\Current\CodeJam\3\A-large.in";
            string output = @"d:\Work\Current\CodeJam\3\A-large.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task1(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                        Console.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

        static char [] vv = new char[]{'a', 'e', 'o', 'i', 'u'};
        static Dictionary<char, bool> vowels = new Dictionary<char, bool> { { 'a', true}, {'e', true}, { 'o', true}, { 'i', true}
            ,{'u', true} };

        struct Pair
        {
            public bool IsVowel;
            public long Number;
        }
        private static string Task1(StreamReader sin)
        {
            var s = sin.ReadLine().Split(' ');
            var word = s[0];
            var n = int.Parse(s[1]);

            bool isVowel = false;
            if (vowels.ContainsKey(word[0]))
                isVowel = true;
            long idx = 0;
            long count = 0;
            List<Pair> input = new List<Pair>();
            for (int i = 0; i < word.Length; i++)
            {
                bool iv = CharIsVowel(word[i]);
                if (iv == isVowel)
                {
                    count++;
                }
                else
                {
                    input.Add(new Pair() {IsVowel = isVowel, Number = count});
                    count = 1;
                    isVowel = iv;
                }
            }
            if (count > 0) input.Add(new Pair() { IsVowel = isVowel, Number = count });

            // calculate
            BigInteger sum = 0;
            long lastVowels = 0;
            bool isFirst = true;
            idx = -1;
            //foreach (var pair in input)
            //{
            //    if (!pair.IsVowel)
            //    {
                     
            //    }
            //}
            count = 0;
            idx = 0;
            for (long i = 0; i < word.Length; i++)
            {
                if (!CharIsVowel(word[(int)i]))
                {
                    count++;

                    if (count == n)
                    {
                        // calc
                        long A = i + 1 - n - idx + 1;
                        var B = word.Length - i;
                        sum += A*B;
                        //shift
                        idx = i + 2 - n;
                        count--;
                    }

                    
                }
                else
                {
                    count = 0;
                }
            }

            

            return sum.ToString();
        }

        private static bool CharIsVowel(char c)
        {
            return vowels.ContainsKey(c);
        }
    }
}
