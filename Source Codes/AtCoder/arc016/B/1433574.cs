using System;

namespace arc016_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            bool[] hold = new bool[9];
            long ret = 0;
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < 9; j++)
                {
                    switch (s[j])
                    {
                        case ('x'):
                            {
                                ret++;
                                hold[j] = false;
                                break;
                            }
                        case ('o'):
                            {
                                if (!hold[j])
                                {
                                    hold[j] = true;
                                    ret++;
                                }
                                break;
                            }
                        default:
                            {
                                hold[j] = false;
                                break;
                            }
                    }
                }
            }
            Console.WriteLine(ret);
        }
    }
}