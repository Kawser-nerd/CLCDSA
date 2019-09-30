using System;

namespace ABC052B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Int32.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            int cur = 0;
            int res = 0;

            foreach (char c in s.ToCharArray())
            {
                if(c == 'I')
                {
                    cur++;
                    if(res < cur) { res++; }
                }
                else
                {
                    cur--;
                }
            }

            Console.WriteLine(res);
        }
    }
}