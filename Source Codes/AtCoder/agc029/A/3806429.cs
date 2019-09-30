using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
     
    namespace AGC029
    {
        class Program
        {
            static void Main(string[] args)
            {
                string S = Console.ReadLine();
                long ans = 0;
                long count = 0;
                for (int i = 0; i < S.Length; i++)
                {
                    if (S[i] == 'W') { ans += i - count; count++; }
                }
                Console.WriteLine(ans);
            }
        }
    }