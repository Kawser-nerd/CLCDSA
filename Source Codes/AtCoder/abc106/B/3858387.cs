using System;
using System.Linq;
using System.Collections.Generic;

namespace _0030
{
    
    class Program
    {

        
        static void Main(string[] args)
        {

            int n = int.Parse(Console.ReadLine());
            int cnt = 0;
            int ans = 0;
            
            for (int i = 3; i <= n; i += 2)
            {
                cnt = 2;               
                for(int j = 3; j <= i - 2; j += 2)
                {
                    if(i % j == 0)
                    {
                        cnt++;                        
                    }
                    if(cnt > 8)
                    {
                        break;
                    }
                }

                if(cnt == 8)
                {
                    ans++;
                }

            }

            Console.WriteLine(ans);
           
        }
    }
}