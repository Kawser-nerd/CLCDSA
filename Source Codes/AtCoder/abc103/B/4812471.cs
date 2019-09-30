using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }
        static void MainStream()
        {
            char[] s = Console.ReadLine().ToCharArray();
            char[] t = Console.ReadLine().ToCharArray();

            if (Judge(s,t))
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }

        static bool Judge(char[] list1, char[] list2)
        {
            for(int i =0; i<list1.Length; i++)
            {
                if(ArrayJudge(list1,list2))
                {
                    return true;
                }
                char tmp = list1[0];
                for (int j=0; j<list1.Length-1; j++)
                {
                    list1[j] = list1[j + 1];
                }
                list1[list1.Length - 1] = tmp;
            }
            return false;
        }
        static bool ArrayJudge(char[] list1,char[] list2)
        {
            for(int i=0;i<list1.Length; i++)
            {
                if(list1[i]!=list2[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}