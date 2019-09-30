using System;

namespace abc035_b
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int x = 0;
            int y = 0;
            int question = 0;
            for (int i = 0; i < s.Length; i++)
            {
                switch (s[i])
                {
                    case ('L'):
                        {
                            x--;
                            break;
                        }
                    case ('R'):
                        {
                            x++;
                            break;
                        }
                    case ('U'):
                        {
                            y++;
                            break;
                        }
                    case ('D'):
                        {
                            y--;
                            break;
                        }
                    default:
                        {
                            question++;
                            break;
                        }
                }
            }
            if (Console.ReadLine() == "1")
            {
                Console.WriteLine(Math.Abs(x) + Math.Abs(y) + question);
            }
            else
            {
                question = Math.Abs(x) + Math.Abs(y) - question;
                Console.WriteLine(question > 0 ? question : Math.Abs(question % 2));
            }
        }
    }
}