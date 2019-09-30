using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            IO io = new IO();

            //????
            int n, k;
            int[] str = io.ReadLineToIntArray();
            n = str[0];
            k = str[1];
            int[] height = new int[n];
            for(int i = 0; i < n; i++)
            {
                height[i] = io.ReadLineToInt();
            }
            height = height.OrderBy(h => h).ToArray();

            int min = int.MaxValue;
            for(int i = 0; i < n - k+1; i++)
            {
                int temp = height[i + k - 1] - height[i];
                if (min > temp)
                {
                    min = temp;
                }
            }

            //????
            Console.Write(min);
            Console.ReadKey();
        }
    }

    //??
    public class Func
    {
        public void Swap<T>(ref T a,ref T b)
        {
            T temp;
            temp = a;
            a = b;
            b = temp;
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