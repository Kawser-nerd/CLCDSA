using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{
   
    class Program
    {
        
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            var diclist = new HashSet<string>[5];
            var M = new HashSet<string>();
            var A = new HashSet<string>();
            var R = new HashSet<string>();
            var C = new HashSet<string>();
            var H = new HashSet<string>();

            for (int i = 0; i < N; i++)
            {
                string str = Console.ReadLine();
                if (str[0] == 'M') M.Add(str);
                else if (str[0] == 'A') A.Add(str);
                else if (str[0] == 'R') R.Add(str);
                else if (str[0] == 'C') C.Add(str);
                else if (str[0] == 'H') H.Add(str);
            }

            diclist[0] = M;
            diclist[1] = A;
            diclist[2] = R;
            diclist[3] = C;
            diclist[4] = H;

            long ans = 0;            
            for(int i = 0; i <= 2; i++)
            {
                for(int j = i + 1; j <= 3; j++)
                {
                    for(int k = j + 1; k <= 4; k++)
                    {
                        ans += (long)diclist[i].Count * diclist[j].Count * diclist[k].Count;
                    }
                }
            }
            
            Console.WriteLine(ans);
            
        }
    }
}