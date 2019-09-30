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

            var list = new List<int>();
            
            for(int i = 0; i < N; i++)
            {
                list.Add(int.Parse(Console.ReadLine()));
            }

            list.Sort();

            
            int u = list.First();
            
            int cnt = 0;
            int ans = 0;
            for(int i = 0; i < N; i++)
            {
                if(list[i] != u)
                {
                    
                    if(cnt % 2 != 0)
                    {
                        ans++;
                    }
                    u = list[i];
                    cnt = 1;
                }
                else
                {
                    cnt++;
                }

            }

            
            if(cnt % 2 != 0)
            {             
                ans++;
            }

            Console.WriteLine(ans);

        }
    }
}