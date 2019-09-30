using System;

namespace AtCoderBeginnerContest118_4
{
    class Program
    {
        public static int[] act = null;

        static void Main(string[] args)
        {

            string[] s = Console.ReadLine().Split(' ');

            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);

            s = Console.ReadLine().Split(' ');
            bool[] number = new bool[6];
            int[] buf = new int[6];

            int[] A = new int[M];

            for (int i = 0; i < M; i++)
            {
                A[i] = int.Parse(s[i]);
            }

            Array.Sort(A);

            for (int i = 0; i < M; i++)
            {
                switch (A[i])
                {
                    case 1:
                        number[0] = true;
                        buf[0] = A[i];
                        break;
                    case 7:
                        number[1] = true;
                        buf[1] = A[i];
                        break;
                    case 4:
                        number[2] = true;
                        buf[2] = A[i];
                        break;
                    case 2:
                    case 3:
                    case 5:
                        number[3] = true;
                        buf[3] = A[i];
                        break;
                    case 6:
                    case 9:
                        number[4] = true;
                        buf[4] = A[i];
                        break;
                    case 8:
                        number[5] = true;
                        buf[5] = A[i];
                        break;
                }
            }

            int tmp = 0;

            for (int i = 0; i < 6; i++)
            {
                if (number[i])
                    tmp++;
            }

            act = new int[tmp];

            tmp = 0;

            for (int i = 0; i < 6; i++)
            {
                if (number[i])
                {
                    act[tmp] = i + 2;
                    tmp++;
                }
            }

            int[] real = new int[act.Length];
            int[] lag = new int[act.Length];

            for (int i = 0; i < act.Length; i++)
            {
                real[i] = buf[act[i] - 2];
                lag[i] = buf[act[i] - 2];
            }

            Array.Sort(lag);
            Array.Reverse(lag);

            int digits = check(N, 0);
            int rem = N;

            for (int i = 0; i < digits; i++)
            {
 
                for (int j = 0; j < lag.Length; j++) {
                    if (digits - i - 1 == check(rem - getNuber(lag[j]), 0))
                    {
                        Console.Write(lag[j]);
                        rem -= getNuber(lag[j]);
                        break;
                    }
                }
            }


                        
        }

        private static int getNuber(int i)
        {
            switch (i)
            {
                case 1:
                    return 2;
                case 7:
                    return 3;
                case 4:
                    return 4;
                case 2:
                case 3:
                case 5:
                    return 5;
                case 6:
                case 9:
                    return 6;
                case 8:
                    return 7;
            }
            return 0;
        }

        private static int check(int rem, int x)
        {


            for (int i = rem / act[x]; i >= 0; i--)
            {
                int rem2 = rem - i * act[x];

                if (rem2 == 0)
                {
                    return i;
                }

                if (x == act.Length - 1)
                    return -1;

                int res = check(rem2, x + 1);
                if (res>0)
                {
                    return i+res;
                }
            }

            return -1;
        }
    }
}