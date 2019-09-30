using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {
        
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            int A = int.Parse(str[0]);
            int B = int.Parse(str[1]);

            int ans = 0;
            for(int i = A; i <= B; i++)
            {
                string s = i.ToString();
                if (s[0] == s[4] && s[1] == s[3]) ans++;
            }

            Console.WriteLine(ans);

        }
    }
}