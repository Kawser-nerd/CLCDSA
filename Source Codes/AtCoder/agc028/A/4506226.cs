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
            Func func = new Func();

            //????


            int[] str = io.ReadLineToIntArray();
            int n = str[0];
            int m = str[1];
            
            string s = io.ReadLineToString();
            string t = io.ReadLineToString();

            int gcd = (int)func.Gcd(n, m);
            for (int i = 0; i < gcd; i++)
            {
                if (s[(n / gcd) * i] != t[(m / gcd) * i])
                {
                    Console.WriteLine(-1);
                    return;
                }
            }

            long ans = func.Lcm(n, m);


            //????

            Console.WriteLine(ans);
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

        public long Gcd(int a,int b)
        {
            return b != 0 ? Gcd(b, a % b) : a;
        }

        public long Lcm(int a,int b)
        {
            long gcd = Gcd(a, b);
            return (long)a * b / gcd;
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