using System;
using System.Collections.Generic;

namespace ABC105D
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] input1 = Console.ReadLine().Split(' ');
            int N = int.Parse(input1[0]);
            int M = int.Parse(input1[1]);

            string[] input2 = Console.ReadLine().Split(' ');
            List<int> A = new List<int>();
            for (int i = 0; i < N;i++)
            {
                A.Add(int.Parse(input2[i]));
            }

            // make sum
            List<int> SUM = new List<int>();

            SUM.Add(0);
            for (int j = 0; j < N;j++){
                SUM.Add((SUM[j] + A[j]) % M);
            }


            Dictionary<int, int> map = new Dictionary<int, int>();
            long ans = 0;

            for (int k = 0; k < SUM.Count; k++){

                if(map.ContainsKey(SUM[k])){
                    ans += map[SUM[k]];
                    map[SUM[k]]++;
                }else{
                    map.Add(SUM[k], 0);
                    ans += map[SUM[k]];
                    map[SUM[k]]++;
                }

                /*
                ans += map[SUM[k]];
                map[SUM[k]]++;
                */

                }


            /*
            for (int k = 0; k < SUM.Count;k++){
                if (!map.ContainsKey(SUM[k]))
                {
                    map.Add(SUM[k], 1);
                }else{
                    map[SUM[k]]++;
                }
            }

            long ans = 0;

            foreach(KeyValuePair<int,int> pair in map){
                ans += (pair.Value * (pair.Value - 1)) / 2;
            }

            */
            Console.WriteLine(ans);
        }
    }
}