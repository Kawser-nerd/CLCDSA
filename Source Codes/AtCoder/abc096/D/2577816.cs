using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace practice1
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = int.Parse(Console.ReadLine());
            int[] a = new int[number];
            int i, j, k, count;

            for (i = 1; i < 5; i++)
            {
                count = 0;

                for (j = 0; j + i <= 55555; j += 5)
                {
                    if (MYCP.PrimeCheck(j + i))
                    {
                        a[count] = j + i;
                        count++;
                        if (count == number)
                        {
                            MYCP.PrintNumbers(a);
                            return;
                        }
                    }
                }
            }
            

        }
    }

    class MYCP
    {
        //??????????
        public static void Println(string str)
        {
            Console.WriteLine(str);
        }

        //???????????
        public static void Print(string str)
        {
            Console.Write(str);
        }


        //int?????????
        public static void PrintNumber(long number)
        {
            Console.WriteLine("" + number);
        }

        //????????
        private static string MyScanf()
        {
            return Console.ReadLine();
        }

        //???????????
        public static string[] MyScanfSplit()
        {
            return MyScanf().Split();
        }


        //double????????
        public static void MyDoubleSort(double[] boo)
        {
            if (boo.Length < 2) return;

            long i, count;
            double a;

            while (true)
            {
                count = 0;

                for (i = 0; i < boo.Length - 1; i++)
                {
                    if (boo[i] > boo[i + 1])
                    {
                        a = boo[i];
                        boo[i] = boo[i + 1];
                        boo[i + 1] = a;
                        count++;
                    }
                }

                if (count == 0) break;
            }
        }

        //int????????
        public static void MyIntSort(int[] boo)
        {
            if (boo.Length < 2) return;

            long i, count;
            int a;

            while (true)
            {
                count = 0;

                for (i = 0; i < boo.Length - 1; i++)
                {
                    if (boo[i] > boo[i + 1])
                    {
                        a = boo[i];
                        boo[i] = boo[i + 1];
                        boo[i + 1] = a;
                        count++;
                    }
                }

                if (count == 0) break;
            }
        }

        //int????????
        public static int MyIntSum(int[] a)
        {
            int sum = 0;
            for(int i = 0; i < a.Length; i++)
            {
                sum += a[i];
            }

            return sum;
        }

        //double????????
        public static double MyDoubleSum(double[] a)
        {
            double sum = 0;
            for(int i = 0; i < a.Length; i++)
            {
                sum += a[i];
            }

            return sum;
        }

        //????????int???????
        public static int[] ReadNumbers(long number)
        {
            int[] a = new int[number];
            string[] buff = MyScanfSplit();
            for (long i = 0; i < number; i++)
            {
                a[i] = int.Parse(buff[i]);
            }

            return a;
        }

        //int?????????????
        public static void PrintNumbers(int[] a)
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

        //???????????????
        public static bool PrimeCheck(int number)
        {
            if (number < 2) return false;

            int a = (int)Math.Sqrt(number);

            for(int i = 2; i <= a; i++)
            {
                if (number % i == 0) return false;
            }

            return true;
        }

        //??????????????????????true????
        public static bool Bekizyousuu_Check(int number)
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
    }
}