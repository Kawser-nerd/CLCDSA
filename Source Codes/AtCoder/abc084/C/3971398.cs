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

            int[] c = new int[N ];
            int[] s = new int[N];
            int[] f = new int[N];
            long time = 0;

            for (int i = 0; i < N -1; i++)
            {
                string[] str = Console.ReadLine().Split(' ');
                c[i] = int.Parse(str[0]);
                s[i] = int.Parse(str[1]);
                f[i] = int.Parse(str[2]);
            }
                    
            //i???N??????????
            for(int i = 0; i < N - 1; i++)
            {
                time = s[i] + c[i];
                
                //???j???j + 1?????
                for(int j = i + 1; j < N - 1; j++)
                {
                    
                    //????
                    if(time < s[j])
                    {
                        time = s[j];
                    }
                    else if(time > s[j] && (time - s[j]) % f[j] != 0)
                    {
                        
                        time += (f[j] - (time - s[j]) % f[j]);
                    }

                    //??
                    time += c[j];                    

                }

                Console.WriteLine(time);
                
            }

            Console.WriteLine(0);

        }
    }
}