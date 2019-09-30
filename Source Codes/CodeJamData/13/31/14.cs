using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consonants
{
    class Program
    {
        const string vowels = "aeiou";

        private static bool HasNValue(string s, int n)
        {
            for (int i = 0; i < s.Length - n + 1; i++)
            {
                bool hasValue = true;
                for (int j = 0; j < n; j++)
                {
                    if (vowels.Contains(s[i + j]))
                    {
                        hasValue = false;
                        break;
                    }
                }

                if (hasValue) return true;
            }

            return false;
        }

        private static int Calculate(string name, int n)
        {
            int value = 0;
            for (int begin = 0; begin < name.Length; begin++)
            {
                for (int length = 0; length < name.Length - begin + 1; length++)
                {
                    if (HasNValue(name.Substring(begin, length), n))
                    {
                        value++;
                    }
                }
            }

            return value;
        }

        private static long Search(string name, int n)
        {
            long result = 0;
            // try to do linear search here
            long consonants = 0;
            for (int i = 0; i < n; i++)
            {
                if (!vowels.Contains(name[i])) consonants++;
            }

            int index = 0;
            int previousIndex = -1;
            while (true)
            {
                if (consonants >= n)
                {
                    // calculate multiplication here
                    long optionsLeft = index - previousIndex;
                    long otionsRight = name.Length - index - n + 1;

                    result += optionsLeft*otionsRight;

                    previousIndex = index;
                }

                // shift right
                if (index + n >= name.Length) break;

                if (!vowels.Contains(name[index])) consonants--;

                index++;
                if (!vowels.Contains(name[index + n - 1])) consonants++;
            }
            
            return result;
        }


        static void Main(string[] args)
        {
            try
            {
                int started = Environment.TickCount;
                string path = @"..\..\..\..\";
                string filenameIn = "A-large.in";
                string filenameOut = "A-large.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                for (int t = 0; t < testCount; t++)
                {
                    Console.WriteLine(t);

                    string[] splitted = sr.ReadLine().Split(' ');
                    string name = splitted[0];
                    int n = Convert.ToInt32(splitted[1]);

                    string message = Search(name, n).ToString();
                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);
                }

                sr.Close();
                sw.Close();

                int elapsed = Environment.TickCount - started;
                Console.WriteLine("Time elapsed: " + elapsed);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }

        }
    }
}
