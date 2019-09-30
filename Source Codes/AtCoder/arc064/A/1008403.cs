using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Numerics;




namespace contest
{

    class contest
    {


        static void Main(string[] args)
        {


            //int n = int.Parse(Console.ReadLine());
            //var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

            //var num = Console.ReadLine().Split().Select(int.Parse).ToArray();



            //int n = int.Parse(Console.ReadLine());

            var num = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = num[0];
            int x = num[1];

            long amount = 0;
            for(int i=1; i< n; i++)
            {
                int sum = Math.Abs(arr[i]+arr[i-1]);
                int diff = sum - x;
                if (diff <= 0) continue;

                if(arr[i]>=diff)
                {
                    arr[i] -= diff;
                    amount += diff;
                }
                else
                {
                    arr[i - 1] -= diff - arr[i];
                    arr[i] = 0;
                    amount += diff;
                }
            }



            Console.WriteLine(amount);






        }

       
       

    }

 
    
}