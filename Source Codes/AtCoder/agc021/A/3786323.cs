using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            Scanner cin = new Scanner();
            long N = cin.Long();

            string num = "9";
            while (long.Parse(num) < N)
            {
                num += "9";
            }
            if (long.Parse(num) == N) Console.WriteLine(9 * num.Length);
            else
            {
                int ans = 9 * (num.Length - 1), tmp = 0;
                for (int i = 0; i < num.Length; i++)
                {
                    tmp = 0;
                    while (long.Parse(num) > N&&int.Parse(num[i].ToString()) > (i == 0 ? 0 : 1))
                    {
                        num = num.Substring(0, i) + (int.Parse(num[i].ToString()) - 1).ToString() + num.Substring(i + 1);
                    }
                }
                foreach(var x in num)
                {
                    tmp += int.Parse(x.ToString());
                }
                ans = Math.Max(ans, tmp);
                Console.WriteLine(ans);
            }
            Console.ReadLine();
        }

        static string GetNextPermutation(string pTarget)
        {
            var query = pTarget.ToCharArray().OrderBy(X => X);
            string BaseStr = "";
            foreach (char each in query)
            {
                BaseStr += each;
            }

            var stk = new Stack<string>();

            for (int I = 0; I <= BaseStr.Length - 1; I++)
            {
                stk.Push(BaseStr[I].ToString());
            }

            var answerList = new List<string>();

            while (stk.Count > 0)
            {
                string wkStr = stk.Pop();

                if (wkStr.Length == BaseStr.Length)
                {
                    answerList.Add(wkStr);
                    continue;
                }

                for (int I = 0; I <= BaseStr.Length - 1; I++)
                {
                    if (wkStr.Contains(BaseStr[I].ToString()) == false)
                    {
                        stk.Push(wkStr + BaseStr[I].ToString());
                    }
                }
            }

            foreach (string each in answerList.OrderBy(X => X))
            {
                if (pTarget.CompareTo(each) >= 0) continue;
                return each;
            }
            return pTarget;
        }

        static long Factorial(int n) //??
        {
            if (n == 1) return 1;
            return n * Factorial(n - 1);
        }

        static long Permutaion(int n, int k) //??
        {
            long ans = 1;
            for (int i = 0; i < k; i++)
            {
                ans *= (n - i);
            }
            return ans;
        }

        static long Combination(int n, int k) //?????
        {
            long ans = 1;
            for (int i = n; i > n - k; --i)
            {
                ans = ans * i;
            }
            for (int i = 1; i < k + 1; ++i)
            {
                ans = ans / i;
            }
            return ans;
        }

        static int GCD(int a, int b) //a,b??????
        {
            if (a < b)
                // ??????????????
                return GCD(b, a);
            while (b != 0)
            {
                var remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }

        static int LCM(int a, int b) //a,b??????
        {
            return a / GCD(a, b) * b;
        }
    

        static int BinarySearch<T>(T[] array, T target) where T : IComparable<T> //2???
        {
            int min = 0;
            int max = array.Length - 1;

            while (true)
            {
                // ????????????
                if (max < min) return -1;
                // ????????????
                int mid = min + (max - min) / 2;
                switch (target.CompareTo(array[mid]))
                {
                    case -1:    // ????????
                        max = mid - 1;
                        break;
                    case 1:     // ????????
                        min = mid + 1;
                        break;
                    case 0:     // ?????
                        return mid;
                }
            }
        }

        static void Swap<T>(ref T a, ref T b) //????
        {
            T tmp = a;
            a = b;
            b = tmp;
        }
    }

    class Scanner //????
    {
        string[] s;
        int i;

        char[] cs = new char[] { ' ' };

        public Scanner()
        {
            s = new string[0];
            i = 0;
        }

        public string next()
        {
            if (i < s.Length) return s[i++];
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            if (s.Length == 0) return next();
            i = 0;
            return s[i++];
        }

        public int Int()
        {
            return int.Parse(next());
        }
        public int[] ArrayInt(int N, int add = 0)
        {
            int[] Array = new int[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Int() + add;
            }
            return Array;
        }

        public long Long()
        {
            return long.Parse(next());
        }

        public long[] ArrayLong(int N, long add = 0)
        {
            long[] Array = new long[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Long() + add;
            }
            return Array;
        }

        public double Double()
        {
            return double.Parse(next());
        }


        public double[] ArrayDouble(int N, double add = 0)
        {
            double[] Array = new double[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Double() + add;
            }
            return Array;
        }
    }
}

/* Dictionary?value??????????????????
var removeTargetLst = dic.Where(kv => kv.Value == value).ToList();
foreach(var item in removeTargetLst)
{
   dic.Remove(item.Key);
}
*/