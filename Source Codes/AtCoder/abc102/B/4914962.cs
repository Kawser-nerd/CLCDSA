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
            Scan sc = new Scan();
            write wr = new write();

            int n = sc.intarr[0];
            int[] array = sc.intarr;

            Array.Sort(array);

            int output = array[array.Length - 1] - array[0];

            Console.WriteLine(output);
        }
    }

    class Scan
    {
        public string str => Console.ReadLine();

        public string[] strarr => str.Split(' ');

        public long[] longarr => strarr.Select(long.Parse).ToArray();
        public int[] intarr => strarr.Select(int.Parse).ToArray();
        public char[] chararr => str.ToArray();


    }



    class write
    {
        public void wri<Type>(Type x)
        {
            Console.WriteLine(x);
        }
    }
}