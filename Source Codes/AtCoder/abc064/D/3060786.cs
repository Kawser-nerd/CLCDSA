using System;

namespace ABC064D
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());
            string S = Console.ReadLine();

            int count = 0;

            for (int i = 0; i < N; i++)
            {
                if (S[i] == '(')
                {
                    count++;
                }
                else if (S[i] == ')')
                {
                    count--;
                }

                if (count < 0)
                {
                    S = '(' + S;
                    count = 0;
                    N++;
                    i++;
                }
            }

            if (count > 0)
            {
                for (int i = 0; i < count; i++)
                {
                    S += ')';
                }
            }

            Console.WriteLine(S);
        }
    }
}