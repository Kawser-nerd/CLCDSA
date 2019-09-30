using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            long ans = 0;
            string[] s = Console.ReadLine().Split(' ');

            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);

            int[][] drink = new int[N][];

            for(int i=0;i<N;i++)
            {
                drink[i] = new int[2];

                s = Console.ReadLine().Split(' ');
                drink[i][0] = int.Parse(s[0]);
                drink[i][1] = int.Parse(s[1]);
            }

            OrgComparer comp = new OrgComparer();
            Array.Sort(drink, comp);

            int count = M;

            for(int i=0;i<N;i++)
            {
                if(drink[i][1] >= count)
                {
                    ans += (long)drink[i][0] * count;
                    break;
                }

                ans += (long)drink[i][0] * drink[i][1];
                count -= drink[i][1];

            }

            Console.WriteLine(ans.ToString());
        }
    }

    public class OrgComparer : System.Collections.IComparer
    {
        public int Compare(object x, object y)
        {
            int[] X = (int[])x;
            int[] Y = (int[])y;

            if (X[0] < Y[0])
                return -1;
            if (X[0] > Y[0])
                return 1;

            return 0;
        }
    }

}