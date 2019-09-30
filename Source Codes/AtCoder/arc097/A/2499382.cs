using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        public static void Main(string[] args)
        {
            List<string> kouho = new List<string>();
            string s = Console.ReadLine();
            int k = int.Parse(Console.ReadLine());
            for (int i = 'a'; i < 'z' + 1; i++)
            {
                int focus = s.IndexOf((char)i);
                while(focus != -1)
                {
                    for (int c = 0; c < 5; c++)
                    {
                        try
                        {
                            if (!kouho.Contains(s.Substring(focus, c + 1)))
                            {
                                kouho.Add(s.Substring(focus, c + 1));
                            }
                        }
                        catch
                        {
                            break;
                        }
                    }
                    if (focus == 0)
                    {
                        s = 'X' + s.Substring(focus + 1);
                    }
                    else if (focus + 1 <= s.Length)
                    {

                        string look1 = s.Substring(0, focus - 1);
                        string look2 = s.Substring(focus + 1);
                        s = s.Substring(0, focus) + 'X' + s.Substring(focus + 1);
                    }
                    else
                    {
                       
                        s = s.Substring(0, focus) + 'X';
                    }
                    focus = s.IndexOf((char)i);

                    if (focus == -1)
                    {
                        s = s.Replace('X', (char)i);
                        break;
                    }
                    else
                    {

                    }

                }
                if (kouho.Count >= 5) break;
            }
            ;
            kouho.Sort();
            ;
            Console.WriteLine(kouho[k - 1]);
        }

    }
}