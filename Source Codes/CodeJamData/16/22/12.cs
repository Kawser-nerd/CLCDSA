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

        static string mini(string c)
        {
            return new string(c.Select(e => e == '?' ? '0' : e).ToArray());
        }

        static string maxi(string c)
        {
            return new string(c.Select(e => e == '?' ? '9' : e).ToArray());
        }

        struct Res {
            public string c;
            public string j;
            public long dif;

            public Res(string a, string b, int c)
            {
                this.c = a;
                j = b;
                dif = c;
            }
        }

        static Res fromDif(string c, string j)
        {
            var r = new Res("", "", 0);
            r.c = c;
            r.j = j;
            if (c != "")
            {
                r.dif = Math.Abs(long.Parse(c) - long.Parse(j));
            }
            return r;
        }

        static Res result(string c, string j)
        {
            if (c.Length == 0)
                return fromDif("", "");
            var C = c[0];
            var J = j[0];
            if (C != '?' && J != '?')
            {
                Res res;
                if (C == J)
                {
                    res = result(c.Substring(1), j.Substring(1));
                }
                else if (C < J)
                {
                    res = fromDif(maxi(c.Substring(1)), mini(j.Substring(1)));
                }
                else 
                {
                    res = fromDif(mini(c.Substring(1)), maxi(j.Substring(1)));
                }
                return fromDif(C + res.c, J + res.j);
            }
            else if (C == '?' && J == '?')
            {
                var res = result('0' + c.Substring(1), '0' + j.Substring(1));
                var res01 = result('0' + c.Substring(1), '1' + j.Substring(1));
                var res10 = result('1' + c.Substring(1), '0' + j.Substring(1));
                if (res.dif <= res01.dif && res.dif <= res10.dif)
                {
                    return res;
                }
                else if (res01.dif <= res10.dif)
                {
                    return res01;
                }
                else
                {
                    return res10;
                }
            }
            else if (C == '?')
            {
                var res = result(J + c.Substring(1), j);
                if (J > '0')
                {
                    var res01 = result((char)(J - 1) + c.Substring(1), j);
                    if (res01.dif <= res.dif)
                    {
                        res = res01;
                    }
                }
                if (J < '9')
                {
                    var res01 = result((char)(J + 1) + c.Substring(1), j);
                    if (res01.dif < res.dif)
                    {
                        res = res01;
                    }
                }
                return res;
            }
            else 
            {
                var res = result(c, C + j.Substring(1));
                if (C > '0')
                {
                    var res01 = result(c, (char)(C - 1) + j.Substring(1));
                    if (res01.dif <= res.dif)
                    {
                        res = res01;
                    }
                }
                if (C < '9')
                {
                    var res01 = result(c, (char)(C + 1) + j.Substring(1));
                    if (res01.dif < res.dif)
                    {
                        res = res01;
                    }
                }
                return res;
            }
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
                var str = Console.ReadLine().Split(' ');
                var c = str[0];
                var j = str[1];
                var res = result(c, j);
                Console.WriteLine("Case #{0}: {1} {2}", i, res.c, res.j);
            }
            Console.Out.Flush();
        }
    }
}