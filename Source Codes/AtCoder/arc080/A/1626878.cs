using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace ConsoleApplication
{
    class Program
    {
        static void Main()
        {
            new Solution().answer();
        }
    }

    class Solution
    {
        string input1, input2 , ans;

        public Solution()
        {
            input1 = Console.ReadLine();  //N
            input2 = Console.ReadLine();  //a1 a2 a3....

            string[] input2_split = input2.Split(' ');

            List<int> list1 = new List<int>();  //4k?
            List<int> list2 = new List<int>();  //???
            List<int> list3 = new List<int>();  //2??????4???

            int i, k, p;

            for (i = 0; i < Convert.ToInt32(input1); i++)
            {
                p = Convert.ToInt32(input2_split[i]) % 2;
                k = Convert.ToInt32(input2_split[i]) % 4;

                if (p * k == 0)
                {
                    if (k == 0)
                    {
                        list1.Add(Convert.ToInt32(input2_split[i]));
                    }
                    else
                    {
                        list3.Add(Convert.ToInt32(input2_split[i]));
                    }
                }
                else
                {
                    list2.Add(Convert.ToInt32(input2_split[i]));
                }
            }

            if (list3.Count() == 0)
            {
                if ((list1.Count() >= list2.Count())||(list1.Count()+1 == list2.Count()))
                {
                    ans = "Yes";
                }
                else { ans = "No"; }
            }
            else
            {
                if ((list1.Count() >= list2.Count()+1) || (list1.Count() + 1 == list2.Count()+1))
                {
                    ans = "Yes";
                }
                else { ans = "No"; }
            
            }

        }

        public void answer()
        {
            Console.WriteLine(ans);
        }
    }
}