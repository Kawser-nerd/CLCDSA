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


            var num = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = num[0];
            int t = num[1];

            //long cost = 0;

            var memo = new int[3];
            memo[0] = int.MaxValue;
            for(int i =0; i< n; i++)
            {
                if (arr[i] < memo[0])
                {
                    memo[0] = arr[i];
                }
                else if(arr[i]>memo[0] && Math.Abs(arr[i]-memo[0])>memo[1])
                {
                    memo[1] = arr[i] - memo[0];
                    memo[2] = 1;
                }
                else if (arr[i] > memo[0] && Math.Abs(arr[i] - memo[0]) == memo[1])
                {
                    
                    memo[2] ++;
                }

            }



            Console.WriteLine(memo[2]);
            


          


        }

        

    }


}