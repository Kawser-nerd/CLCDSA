using System;

namespace AtCoderBC113C_ID
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);

            int[][] city = new int[M][];

            for(int i=0;i<M;i++)
            {
                string[] c = Console.ReadLine().Split(' ');

                city[i] = new int[4];

                city[i][0] = int.Parse(c[0]);
                city[i][1] = int.Parse(c[1]);
                city[i][2] = i;
            }

            OrgComparer comp = new OrgComparer();
            Array.Sort(city, comp);

            int[] pref = new int[N];

            for(int i=0;i<M;i++)
            {
                city[i][3] = pref[city[i][0]-1];
                pref[city[i][0]-1]++;
            }

            IdComparer icomp = new IdComparer();
            Array.Sort(city, icomp);

            for(int i=0;i<M;i++)
            {
                String ans = city[i][0].ToString("000000") + (city[i][3] + 1).ToString("000000");
                Console.WriteLine(ans);
            }

            Console.ReadKey();
        }
    }

    public class PrefComparer : System.Collections.IComparer
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


    public class OrgComparer : System.Collections.IComparer
    {
        public int Compare(object x,object y)
        {
            int[] X = (int[])x;
            int[] Y = (int[])y;

            if (X[1] < Y[1])
                return -1;
            if (X[1] > Y[1])
                return 1;

            return 0;
        }
    }
    public class IdComparer : System.Collections.IComparer
    {
        public int Compare(object x, object y)
        {
            int[] X = (int[])x;
            int[] Y = (int[])y;

            if (X[2] < Y[2])
                return -1;
            if (X[2] > Y[2])
                return 1;

            return 0;
        }
    }
}