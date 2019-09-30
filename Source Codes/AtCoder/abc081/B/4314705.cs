using System;

namespace AtCoder_20190218
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            string str1 = Console.ReadLine();
            int[] An = new int[int.Parse(str)];

            string[] ss = str1.Split(' ');
            bool isContinue = true;
            int count = 0;
            for (int i = 0; i < An.Length; i++)
            {
                An[i] = int.Parse(ss[i]);
            }

                while (isContinue)
            {
                for (int i = 0; i < An.Length; i++)
                {
                    if (An[i] % 2 == 0)
                    {
                        An[i] = An[i] / 2;
                    }
                    else
                    {
                        isContinue = false;
                        count--;
                        break;
                    }
                }
                count++;
            }
            Console.WriteLine(count);
        }
    }
}