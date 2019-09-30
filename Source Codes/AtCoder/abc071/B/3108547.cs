using System;
using System.Linq;

namespace Sample101
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] S = Console.ReadLine().ToArray();
            bool[] letters = Enumerable.Repeat<bool>(false, 26).ToArray();

            for (int i = 0; i < S.Length; ++i)
            {
                letters[(int)S[i] - (int)'a'] = true;
            }

            string result = "None";
            for (int i = 0; i < letters.Length; ++i)
            {
                if (letters[i] == false)
                {
                    result = ((char)((int)'a' + i)).ToString();
                    break;
                }
            }

            Console.WriteLine(result);
        }
    }
}