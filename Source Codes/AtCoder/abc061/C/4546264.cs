using System;
using System.Collections.Generic;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var NK = Console.ReadLine().Split(' ').Select(s=> long.Parse(s)).ToArray();
            var N = NK[0];
            var K = NK[1];
            var array = new List<KeyValuePair<long, long>>();

            for (var i=0;i<N;i++)
            {
                var ab = Console.ReadLine().Split(' ').Select(s=> long.Parse(s)).ToArray();
                array.Add(new KeyValuePair<long, long>(ab[0],ab[1]));
            }

            array = array.OrderBy(s => s.Key).ToList();
            var tmpK=K;
            for(var i=0;i<N;i++)
            {
                tmpK -= array[i].Value;
                if(tmpK<1)
                {
                    Console.WriteLine(array[i].Key);
                    return;
                }
            }
        }
    }