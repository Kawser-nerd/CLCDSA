using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication14
{


    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string[] msg = Console.ReadLine().Split(' ');
            bool isOdd = ((N & 0x00000001) == 1) ? true : false;
            Dictionary<int, int> dic = new Dictionary<int, int>();

            //?????
            //????????1?(N-1)???(???????)
            //????????0?????2?(N-1)???(???????)
            //????????
            //??????0????????
            bool valid = true;
            for (int i = 0; i < N; i++)
            {
                int num = int.Parse(msg[i]);
                if (num >= N) { valid = false; break; }
                if ((isOdd) && ((num & 0x00000001) != 0)) { valid = false; break; }
                if ((!isOdd) && ((num & 0x00000001) == 0)) { valid = false; break; }

                if (dic.ContainsKey(num)) dic[num]++;
                else dic.Add(num, 1);

                if (dic[num] > 2) { valid = false; break; }
            }

            //??????????????????????????
            if ((isOdd) && (dic.Count != ((N / 2) + 1))) { valid = false; }
            if ((!isOdd) && (dic.Count != (N / 2))) { valid = false; }

            //N?????????0?????????????????
            if (isOdd){
                if (!dic.ContainsKey(0)) valid = false;
                else if (dic[0] != 1) valid = false;
            }

            if(!valid)
            {
                //????
                Console.WriteLine("0");
            }
            else
            {
                //????????????????????
                //??????????????
                UInt64 result = 1;
                for (int i = 0; i < (N / 2); i++) result = (result * 2) % 1000000007;
                Console.WriteLine(result.ToString());
            }

            Console.ReadLine();
        }
    }
}