using System;
using System.Collections;
using System.Linq;
namespace ARC097
{
    class Program
    {
        static void Main()
        {
            //?????????
            string s = Console.ReadLine();
            int k = int.Parse(Console.ReadLine());

            //??????
            ArrayList sub = new ArrayList();

            for (int i = 1; i <= k; i++)
            {
                for (int j = 0; j <= s.Length - i; j++)
                {
                    string st = s.Substring(j, i);
                    sub.Add(st);
                }
            }


            string[] sub2 = (string[])sub.ToArray(typeof(string));
            Array.Sort(sub2);

            ArrayList sub3 = new ArrayList();
            sub3.Add(sub2[0]);
            for (int i = 1; i < sub2.Length; i++)
                if (sub2[i - 1] != sub2[i])
                    sub3.Add(sub2[i]);

            //for (int i = 0; i < sub2.Length; i++)
            //    Console.WriteLine(sub2[i]);

            //???????
            Console.WriteLine((string)sub3[k - 1]);
        }
    }
}