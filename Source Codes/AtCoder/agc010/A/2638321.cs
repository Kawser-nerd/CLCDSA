using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            string szLine = Console.ReadLine();
            long n = long.Parse(szLine);
            szLine = Console.ReadLine();
            string[] szArr = szLine.Split(' ');

            long[] arr = new long[n];

            for (int i = 0; i < arr.Length; ++i)
            {
                arr[i] = long.Parse(szArr[i]);
            }


            // odd???2???????
            int oddTotal = 0;
            foreach(long val in arr)
            {
                if(val % 2 != 0)
                {
                    oddTotal++;
                }
            }

            string result = oddTotal % 2 == 0 ? "YES" : "NO";
            Console.WriteLine(result);
        }
    }
}