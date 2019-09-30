using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;


namespace tes
{
	class contest
	{
				
		
		static void Main(string[] args)
		{

			 string s = Console.ReadLine();
            int n = s.Length;
            int g = 0;
            int p = 0;
            for(int i=0; i< n; i++)
            {
                if (s[i] == 'g') g++;
                else p++;
            }
            //int p = n / 2 ;

            int count = 0;
            int tmp = n / 2;
            for(int i =n-1; i>=0; i--)
            {
                if (s[i] == 'g')
                {
                    if (tmp >= p && tmp>0)
                    {
                        
                        tmp--;
                        count++;
                    }
                }
                else
                {

                    if (tmp == 0) count--;
                    else  tmp--;
                    p--;
                }
            }

            Console.WriteLine(count);

        }
			
	}
}