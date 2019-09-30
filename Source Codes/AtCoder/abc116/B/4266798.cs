using System;
using System.Collections.Generic;
using System.Linq;
//using System.Text;
//using System.Threading.Tasks;
using static System.Console;

namespace testConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            //var n = Array.ConvertAll(ReadLine().Split(), int.Parse);
            var s = int.Parse(ReadLine());
            var arr = new List<int>();
            arr.Add(s);

            for (var i = 1; ;i++)
            {
                var temp = arr[i - 1];

                if (temp % 2 == 0) arr.Add(temp / 2);
                else arr.Add(3 * temp + 1);

                temp = arr.Count(x => x == arr[i]);
                if (temp == 2) break;
            }

            WriteLine(arr.Count);
        }
    }
}