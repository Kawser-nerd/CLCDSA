using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;




namespace contest
{

    class contest
    {


        static void Main(string[] args)
        {


            //int n = int.Parse(Console.ReadLine());
            //var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

            //var num = Console.ReadLine().Split().Select(int.Parse).ToArray();


            string s = Console.ReadLine();
            int len = s.Length;
            int count = int.MaxValue;

            int wCount = 0;
            int bCount = 0;
            bool w = false;
            bool b = false;
            for(int i =0; i<len; i++)
            {
                if (i == 0 && s[0] == 'W')
                {
                    w = true;
                }
                else if(i == 0 && s[0] == 'B') b = true;

                if(s[i]=='W' && !w)
                {
                    wCount++;
                    w = true;
                    b = false;
                }
                else if(s[i] == 'B' && !b)
                {
                    bCount++;
                    b = true;
                    w = false; 
                }

            }
            count = Math.Min(count,(wCount+bCount));

            wCount = 0;
            bCount = 0;
            w = false;
            b = false;
            for (int i = len-1; i >=0; i--)
            {
                if (i == len-1 && s[len-1] == 'W')
                {
                    w = true;
                }
                else if (i == len-1 && s[len-1] == 'B') b = true;


                if (s[i] == 'W' && !w)
                {
                    wCount++;
                    w = true;
                    b = false;
                }
                else if (s[i] == 'B' && !b)
                {
                    bCount++;
                    b = true;
                    w = false;
                }

            }
            count = Math.Min(count, (wCount + bCount));


            Console.WriteLine(count);
            


        

        }

        

    }


}