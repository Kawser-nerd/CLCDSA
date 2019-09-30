using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace template
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            if (s.Length % 2 == 0)
            {
                int ret = 0;
                char hikaku = s[s.Length / 2 - 1];
                for (int i = 0; i < s.Length / 2; i++)
                {
                    if (s[s.Length / 2 - (1 + i)] == hikaku && s[s.Length / 2 + i] == hikaku)
                    {
                        ret++;
                    }
                    else
                    {
                        break;
                    }
                }
                Console.WriteLine(s.Length / 2 + ret);
            }
            else
            {
                int ret = 0;
                char hikaku = s[(s.Length - 1) / 2];
                for (int i = 1; i <= (s.Length - 1) / 2; i++)
                {
                    if (s[(s.Length - 1) / 2 - i] == hikaku && s[(s.Length - 1) / 2 + i] == hikaku)
                    {
                        ret++;
                    }
                    else
                    {
                        break;
                    }
                }
                Console.WriteLine((s.Length + 1) / 2 + ret);
            }
        }
    }
}