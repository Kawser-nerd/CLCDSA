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
			 
            var num = int.Parse(Console.ReadLine());
            var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            int max = input.Max();
            int midCount = input.Length - input.Count(c => c == max);
            Array.Sort(input);
            Array.Reverse(input);
            var tmp = new int[max+1];
            tmp[0] =  max ;
            tmp[tmp.Length - 1] =  max ;

            bool check = true;
            if (input.Count(c => c == max) < 2) check = false; 
            
			int mid = (max + 1) / 2;
            if(max %2 == 1)
            {
                if (input.Count(c => c == mid) > 2) check = false;
            }
            else
            {
                if (input.Count(c => c == mid) > 1) check = false;
            }
           
            
            for (int i = 0; i < input.Length; i++)
            {
               
                int current = input[i];
                if (current == max) continue;
                if (current < (max + 1) / 2)
                {
                    check = false;
                    break;
                }

                if (tmp[current]==0)tmp[current] = current ;
                else if(tmp[max - current]== 0) tmp[max-current] =  current;
                else
                {
					if (tmp.Contains(current)) continue;
					
                    for (int j = 0; j < tmp.Length; j++)
                    {
                        
                        if((tmp[j] != 0 && (tmp[j] + 1 == current)))
                        {
                            break;
                        }

                        if (j == tmp.Length - 1) check = false;
                    }
                }
            }


            if (tmp.Contains(0)) check = false;

            if (!check ) Console.WriteLine("Impossible");
            else Console.WriteLine("Possible");

		}				 
	}
}