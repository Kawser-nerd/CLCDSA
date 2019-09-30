using System;

    class AGC027A
    {
        static void Main(string[] args)
        {
            Method(args);
        }

        static void Method(string[] args)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            int n = int.Parse(inputs[0]);
            int x = int.Parse(inputs[1]);

            int[] a = new int[n];
            string[] somea = Console.ReadLine().Split(' ');

            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(somea[i]);
            }

            /*
             ?????????????????????????????????
             ????????????????
             ?????????
             */

            int temp;

            for(int i = 0; i < n; i++)
            {
                for(int j = n - 1; j > i; j--)
                {
                    if(a[i] > a[j])
                    {
                        temp = a[j];
                        a[j] = a[i];
                        a[i] = temp;
                    }
                }
            }

            int cnt = 0;

            for(int i = 0; i < n; i++)
            {
                //Console.WriteLine(a[i]);
                // ??????????????????
                if (i == n - 1)
                {
                    if (x == a[i])
                        cnt++;
                }
                else
                {
                    if (x >= a[i])
                    {
                        x -= a[i];
                        cnt++;
                    }
                    else
                        break;
                }
            }

            Console.WriteLine(cnt);
        }
    }