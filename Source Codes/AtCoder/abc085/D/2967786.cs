using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ForBlue.ABC_085
{
    class D
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int h = int.Parse(input[1]);
            int[] katana = new int[n];
            int[] throwPow= new int[n];
            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split(' ');
                katana[i] = int.Parse(input[0]);
                throwPow[i] = int.Parse(input[1]);
            }
            Array.Sort(katana);
            Array.Sort(throwPow);

            int throwGreatIndex = 0;
            for (; throwGreatIndex < throwPow.Length; throwGreatIndex++)
            {
                if (throwPow[throwGreatIndex] > katana[n - 1])
                {
                    break;
                }
            }

            int cnt = 0;
            for(int i = n - 1; i >= throwGreatIndex; i--)
            {
                h -= throwPow[i];
                cnt++;
                if (h <= 0)
                {
                    Console.WriteLine(cnt);
                    return;
                }
            }

            int pow = katana[n - 1];
            cnt += h / pow;
            if (h % pow > 0)
            {
                cnt++;
            }
            Console.WriteLine(cnt);
        }
    }
}