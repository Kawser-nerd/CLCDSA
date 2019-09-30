using System;
namespace Atcoder
{
    class AtCoderContest
    {
        static void Main()
        {
            string input = Console.In.ReadToEnd();
            string[] S = input.Split('\n');
            int number = 0;
            int count = S.Length - 1;
            while (count >= 0)
            {
                if (S[count].Contains("r") == true)
                {
                    number++;
                }
                count--;
            }
            Console.WriteLine(number);
        }
    }
}