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
            var n = int.Parse(Console.ReadLine());

            var data = new List<int[]>();
            foreach(var i in Enumerable.Range(0, n))
            {
                var item = Console.ReadLine().Split('-').Select(x => int.Parse(x)).ToArray();
                data.Add(item);
            }

            var table = new bool[24 * 12];
            foreach(var se in data)
            {
                //???????
                var start = (se[0] / 5) * 5;
                //???????
                var end = ((se[1] + 4) / 5) * 5;
                if(end % 100 >= 60)
                {
                    end = (end / 100 + 1) * 100;
                }
                //??????
                var si = 12 * (start / 100) + (start % 100) / 5;
                var ei = 12 * (end / 100) + (end % 100) / 5;
                //???
                for (var i = si; i < ei; i++) table[i] = true;
            }

            var activated = false;
            foreach(var i in Enumerable.Range(0, table.Length))
            {
                if(!activated)
                {
                    if(table[i])
                    {
                        var time = (i / 12) * 100 + (i % 12) * 5;
                        Console.Write(time.ToString("D4") + "-");
                        activated = true;
                    }
                }
                else
                {
                    if (!table[i])
                    {
                        var time = (i / 12) * 100 + (i % 12) * 5;
                        Console.WriteLine(time.ToString("D4"));
                        activated = false;
                    }
                    else if(i == table.Length -1)
                    {
                        Console.WriteLine("2400");
                    }
                }
            }
        }
    }

}