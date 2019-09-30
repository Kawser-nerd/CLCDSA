using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C073
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            Dictionary<int, int> dic = new Dictionary<int, int>();
            for(int i = 0; i < N; i++)
            {
                int A = int.Parse(Console.ReadLine());
                if (!dic.ContainsKey(A)) dic.Add(A, 0);
                dic[A]++;
            }
            int count = dic.Values.Count(x => x % 2 == 1);
            Console.WriteLine(count);
        }

    }
}