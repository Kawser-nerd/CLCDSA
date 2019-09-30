using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static T Get<T>(object obj)
        {
            return (T)Convert.ChangeType(obj, typeof(T));
        }

       

        static void Main(string[] args)
        {
#if !DEBUG
            Console.SetIn(new StreamReader("input.txt"));
            Console.SetOut(new StreamWriter("output.txt"));      
#endif
            int t = Get<int>(Console.ReadLine());
            for (var i = 1; i <= t; ++i)
            {
                int n = Get<int>(Console.ReadLine());
                var arr = new List<Tuple<string, string>>();
                for (var j = 1; j <= n; ++j)
                {
                    var str = Console.ReadLine().Split(' ');                    
                    arr.Add(Tuple.Create(str[0], str[1]));
                }
                int possible = 0;
                for (var z = 0; z < (1 << n); z++)
                {
                    var u = z;
                    var tt = 0;
                    var fake = new List<Tuple<string, string>>();
                    var origin = new List<Tuple<string, string>>();
                    for (var y = 0; y < n; y++)
                    {
                        if ((u & 1) == 1)
                        {
                            fake.Add(arr[y]);
                            tt++;
                        }
                        else {
                            origin.Add(arr[y]);
                        }
                        u >>= 1;
                    }
                    if (tt > possible)
                    {
                        var cool = true;
                        foreach (var y in fake)
                        {
                            var s = 0;
                            foreach (var q in origin)
                            {
                                if (q.Item1 == y.Item1)
                                {
                                    s |= 1;
                                }
                                if (q.Item2 == y.Item2)
                                {
                                    s |= 2;
                                }
                                if (s == 3)
                                    break;
                            }
                            if (s != 3)
                            {
                                cool = false;
                                break;
                            }
                        }
                        if (cool)
                            possible = tt;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i, possible);
            }
            Console.Out.Flush();
        }
    }
}