using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s1 = Console.ReadLine().Split(' ');

            int N = int.Parse(s1[0]);
            int Q = int.Parse(s1[1]);

            string s = Console.ReadLine();

            char[] c = s.ToCharArray();

            int[] ans = new int[Q];
            System.Collections.ArrayList array = new System.Collections.ArrayList();


            for (int i =0;i<c.Length-1;i++)
            {
                if(c[i] == 'A' && c[i+1] == 'C')
                {
                    array.Add(i+1);
                }
            }

            if(array.Count == 0)
            {
                for (int i = 0; i < Q; i++)
                    Console.WriteLine("0");
                return;
            }

            for(int i=0;i<Q;i++)
            {
                string[] s2 = Console.ReadLine().Split(' ');
                int Start = int.Parse(s2[0]);
                int End = int.Parse(s2[1]);
                ans[i] = search(array, End-1) - search(array, Start-1);
            }

            for(int i=0;i<Q;i++)
                Console.WriteLine(ans[i].ToString());
        }

        private static int search(System.Collections.ArrayList array, int value)
        {
            int mid;
            int Start = 0;
            int End = array.Count - 1;

            if (value < (int)array[Start] )
                return 0;
            if ((int)array[Start] == value)
                return 1;
            if ((int)array[End] <= value)
                return array.Count;

            while (true)
            {
                mid = Start + (End - Start) / 2;

                if(value < (int)array[mid])
                {
                    if ((int)array[mid - 1] < value)
                        return mid;
                    End = mid;
                }
                else if((int)array[mid] < value)
                {
                    if (value < (int)array[mid + 1])
                        return mid + 1;
                    Start = mid;
                }
                else
                {
                    return mid + 1;
                }
            }

        }
    }
}