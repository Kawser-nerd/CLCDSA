using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var Slist = new List<char[]>();
            for(var i = 0;i<n;i++)
            {
                Slist.Add(Console.ReadLine().ToCharArray());
            }
            var resultStr = "";
            for (var i = 0; i < Slist[0].Length; i++)
            {
                var c = Slist[0][i];
                var all = true;
                for(var k = 1;k<Slist.Count;k++)
                {
                    var tmp = false;
                    for(var j = 0;j<Slist[k].Length;j++)
                    {
                        if(Slist[k][j]==c)
                        {
                            tmp = true;
                            Slist[k][j] = '_';
                            break;
                        }
                    }
                    if(!tmp)
                    {
                        all = false;
                        break;
                    }
                }
                if (all) resultStr += c;
            }

            Console.WriteLine(resultStr.OrderBy(c=>c).ToArray());
        }
    }