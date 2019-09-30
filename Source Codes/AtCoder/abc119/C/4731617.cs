using System;
using System.Collections.Generic;
class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int a = int.Parse(input[1]);
            int b = int.Parse(input[2]);
            int c = int.Parse(input[3]);
            int[] bamboo = new int[n];
            for (int i=0; i<n; i++) bamboo[i] = int.Parse(Console.ReadLine());

            int ans = 1000000000;

            for (int i=0; i<Math.Pow(4, n); i++)
            {
                List<int> aList = new List<int>(), bList = new List<int>(), cList = new List<int>();
                for (int j=0; j<n; j++)
                {
                    switch ((i >> (2 * j)) % 4)
                    {
                        case 0:
                        break;

                        case 1:
                        aList.Add(bamboo[j]);
                        break;

                        case 2:
                        bList.Add(bamboo[j]);
                        break;

                        case 3:
                        cList.Add(bamboo[j]);
                        break;
                    }
                }
                if (aList.Count * bList.Count * cList.Count == 0) continue;
                int buf = (aList.Count + bList.Count + cList.Count - 3) * 10;
                int sum = 0;
                foreach (int j in aList) sum += j;
                buf += Math.Abs(sum - a);
                sum = 0;
                foreach (int j in bList) sum += j;
                buf += Math.Abs(sum - b);
                sum = 0;
                foreach (int j in cList) sum += j;
                buf += Math.Abs(sum - c);

                ans = Math.Min(ans, buf);
            }

            Console.WriteLine(ans);



            
            

            
            
        }
    }
    //mcs Main.cs
    //mono Main.exe