using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static int GetSum(int a,int b)
        {
            int m = 5,sum=0;
            for(int i = m; i >=0; i--)
            {
                sum += (a / (int)Math.Pow(10, i)) + (b / (int)Math.Pow(10, i));
                a -= (a / (int)Math.Pow(10, i))*(int)Math.Pow(10,i);
                b -= (b / (int)Math.Pow(10, i))*(int)Math.Pow(10,i);
            }
            return sum;
        }

        static void Main()
        {
            IO io = new IO();

            //????

            int n = io.ReadLineToInt();

            int a = n-2, b = 2, min = int.MaxValue,sum=0;

            for(int i = 0; i < n / 2 +1; i++)
            {
                sum = GetSum(a-i, b+i);
                if (min > sum)
                {
                    min = sum;
                }
            }

            //????
            Console.Write(min);
            Console.ReadKey();
        }
    }

    //IO??????
    public class IO
    {
        //string???
        public string ReadLineToString()
        {
            return Console.ReadLine();
        }

        //int???
        public int ReadLineToInt()
        {
            return int.Parse(Console.ReadLine());
        }

        //????????????????string[]?????
        public string[] ReadLineToStringArray()
        {
            return Console.ReadLine().Split(' ').ToArray();
        }


        //???????????????int[]?????
        public int[] ReadLineToIntArray()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }

        //????????????????List<string>?????
        public List<string> ReadLineToStringList()
        {
            return Console.ReadLine().Split(' ').ToList();
        }

        //???????????????List<int>?????
        public List<int> ReadLineToIntList()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        }

    }

}