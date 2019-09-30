using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace All_Your_Base
{
    using System.IO;

    class Program
    {
        static int Conv(char ch)
        {
            if (ch >= '0' && ch <= '9')
            {
                return ch - '0';
            }

            return ch - 'a' + 10;
        }

        private static char[] digits = new char[36];

        static string ToSmallest(string s)
        {
            char[] mas = new char[255];
            StringBuilder str = new StringBuilder();
            int cur = 0;
            bool oneAssigned = false;
            for (int i=0; i<s.Length; ++i)
            {
                if (mas[s[i]] == 0)
                {
                    if (cur==0 && i==0)
                    {
                        mas[s[0]] = '1';
                        oneAssigned = true;
                    }
                    else
                    {
                        mas[s[i]] = digits[cur];
                        ++cur;
                        if (cur==1 && oneAssigned)
                            ++cur;
                    }
                }
                str.Append(mas[s[i]]);
            }
            return str.ToString();
        }

        static void Main(string[] args)
        {
            for (int i=0; i<10; ++i)
            {
                digits[i] = (char)('0' + i);
            }
            for (int i = 0; i < 26; ++i)
            {
                digits[i+10] = (char)('a' + i);
            }
            string[] str = File.ReadAllLines("a.txt");
            var writer = new StreamWriter("a_out.txt");
            int t = int.Parse(str[0]);
            int j = 0;
            while (t-- > 0)
            {
                string s = ToSmallest(str[++j]);
                int bas = 0;
                foreach (var ch in s)
                {
                    bas = Math.Max(bas, Conv(ch));
                }
                ++bas;
                long seconds = 0;
                foreach (var ch in s)
                {
                    seconds = seconds * bas + Conv(ch);
                }
                
                writer.WriteLine(String.Format("Case #{0}: {1}", j, seconds));                                
            }
            writer.Close();
        }
    }
}
