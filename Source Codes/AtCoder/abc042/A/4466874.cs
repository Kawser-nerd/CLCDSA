using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int[] Number=new int[3];
            int A = int.Parse(s[0]);
            int B = int.Parse(s[1]);
            int C = int.Parse(s[2]);
            int five=0;
            int seven = 0;

            for (int i = 0; i < 3; i++)
            {
                Number[i] = int.Parse(s[i]);
                if (Number[i] == 5)
                {
                    five = five + 1;
                }
                else if (Number[i] == 7)
                {
                    seven = seven + 1;
                }

            }

            if (five==2&&seven==1)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}