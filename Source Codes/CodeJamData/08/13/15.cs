using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem3
{
    class Program
    {
        static void Main(string[] args)
        {
            //string str = "C-small-attempt0.in";
            // Обработаем аргументы
            foreach (string str in args)
            {
                if (File.Exists(str))
                {
                    try
                    {
                        StreamReader sr = new StreamReader(str);
                        StreamWriter sw = new StreamWriter(str + "2");
                        int count = int.Parse(sr.ReadLine());
                        for (int i = 0; i < count; i++)
                        {
                            N = int.Parse(sr.ReadLine());

                            Go();

                            sw.Write(String.Format("Case #{0}: {1}\n", i + 1, res));
                        }
                        sr.Close();
                        sw.Close();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
                else
                    Console.WriteLine(String.Format("Файл {0} не существует", str));
            }
        }

        static int N;
        static string res = String.Empty;

        static void Go()
        {
            //decimal skobki = 3 + (decimal)Math.Sqrt(5);
            decimal sk = 3 + sqrt();
            decimal pow = power(sk, N);

            string str = pow.ToString();
            string[] arr = str.Split(',');
            res = arr[0];

            if (res.Length == 1)
                res = "00" + res;
            else if (res.Length == 2)
                res = "0" + res;
            else if (res.Length > 3)
                res = res.Substring(res.Length - 3);
        }

        static decimal power(decimal t, int k)
        {
            decimal r = 1;
            for (int i = 0; i < k; i++)
                r *= t;
            return r;
        }

        static decimal sqrt()
        {
            decimal x = 1;
            for (int i = 0; i < 10000; i++)
            {
                decimal x5 = 5 / x;
                x = (decimal)0.5 * (x + x5);
            }
            return x;
        }
    }
}
