using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;


namespace practice1
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] str = Console.ReadLine().ToCharArray();
            int count_pa = 0;
            int max;
            int i;
            for (i = 0; i < str.Length; i++)
            {
                
                if (str[i] == 'p')
                {
                    count_pa++;
                }
            }

            max = str.Length / 2;
            MYCP.Print_Int(max - count_pa);
        }
    }

    

    class MYCP
    {
        //int?????????
        public static void Print_Int(long number)
        {
            Console.WriteLine("" + number);
        }

        //int????????????
        public static void Print_Ints(int[] a)
        {
            if (a.Length == 0) return;

            Console.Write(a[0]);

            for(int i = 1; i < a.Length; i++)
            {
                Console.Write(" ");
                Console.Write(a[i]);
            }

            Console.WriteLine();
        }


        //???????????
        public static string[] MyReadLineSplit()
        {
            return Console.ReadLine().Split();
        }

        //????????int???????
        public static int[] Read_Ints(long number)
        {
            int[] a = new int[number];
            string[] buff = MyReadLineSplit();
            for (long i = 0; i < number; i++)
            {
                a[i] = int.Parse(buff[i]);
            }

            return a;
        }

        //????????BigInteger???????
        public static BigInteger[] Read_BigIntegers(long number)
        {
            BigInteger[] a = new BigInteger[number];
            string[] buff = MyReadLineSplit();
            for(long i = 0; i < number; i++)
            {
                a[i] = BigInteger.Parse(buff[i]);
            }

            return a;
        }



        //????????????????????true????
        public static bool PrimeCheck_Int(int number)
        {
            if (number < 2) return false;

            for(int i = 2; i < number; i++)
            {
                if (number % i == 0) return false;
            }

            return true;
        }

        //??????????????????????true????
        public static bool Bekizyousuu_Check_Int(int number)
        {
            if (number == 1) return true;

            int i, copy;


            for (i = 2; i < number; i++)
            {
                copy = number;
                while (copy % i == 0)
                {
                    copy /= i;
                }

                if (copy == 1) return true;
            }

            return false;
        }

        //BIgInteger????????
        public static BigInteger MyPower_BigInteger(BigInteger a,BigInteger b)
        {
            BigInteger i, x = 1;

            for (i = 0; i < b; i++)
            {
                x *= a;
            }

            return x;
        }

        //????BigInteger?????????
        public static BigInteger MySum_BigInteger(BigInteger[] a)
        {
            BigInteger sum = 0;
            int i;

            for (i = 0; i < a.Length; i++)
            {
                sum += a[i];
            }

            return sum;

        }

        //a?N?????????????????
        public static int SumKeta_Int(int a,int N_shinhou)
        {
            if (a <= 0) return 0;
            int sum = 0;

            while (a > 0)
            {
                sum += a % N_shinhou;
                a -= a % N_shinhou;
                a /= N_shinhou;

            }

            return sum;

        }

        //????????????
        public static BigInteger NPR_BigInteger(int n,int r)
        {
            BigInteger a = 1;
            for(int i = 0; i < r; i++)
            {
                a *= n;
                n--;
            }

            return a;

            
        }

        //?????????????
        public static BigInteger NCR_BigInteger(int n,int r)
        {
            BigInteger a = 1;
            for(int i = 0; i < r; i++)
            {
                a *= n;
                n--;
            }

            a /= NPR_BigInteger(r, r);

            return a;
        }
    }
}