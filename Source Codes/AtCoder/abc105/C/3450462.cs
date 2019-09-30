using System;

namespace ABC105C_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var x = new IntegerNumber(n);
            Console.WriteLine(x.BaseMinus2Number());
        }
    }
    public class IntegerNumber
    {
        private readonly int v;

        public IntegerNumber(int v)
        {
            this.v = v;
        }

        public string BaseMinus2Number()
        {
            if (v == 0)
            {
                return "0";
            }

            int n = v;
            string ans = "";
            while (n != 0)
            {
                if (n % 2 == 0)
                {
                    ans = "0" + ans;
                }
                else
                {
                    n--;
                    ans = "1" + ans;
                }
                n = n / -2;
            }
            return ans;
        }
    }

}