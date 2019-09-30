using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class D064
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string S = Console.ReadLine();

            List<char> list = new List<char>();

            int counter = 0;
            for(int i = 0; i < N; i++)
            {
                char c = S[i];

                if (c == '(')
                {
                    list.Add(c);
                    counter++;
                }
                else
                {
                    if (counter > 0)
                    {
                        for(int k = list.Count - 1; k >= 0; k--)
                        {
                            if (list[k] == '(')
                            {
                                list[k] = '[';
                                counter--;
                                list.Add(']');
                                break;
                            }
                        }
                    }
                    else
                    {
                        list.Insert(0, '[');
                        list.Add(']');
                    }
                }
            }

            for(int i = 0; i < counter; i++)
            {
                list.Add(')');
            }

            string r = new string(list.ToArray()).Replace('[', '(').Replace(']', ')');
            Console.WriteLine(r);
        }

    }
}