using System;
using System.Collections.Generic;
using System.Linq;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }

        static void MainStream()
        {
            int flag = 0;
            int n = int.Parse(Console.ReadLine());
            var list = new List<char[]>() ;

            for (var i = 0; i < n; i++)
            {
                char[] tmp = Console.ReadLine().ToCharArray();
                list.Add(tmp);
            }

            for (var i =0;i<n;i++)
            { 
                if (i!=0)
                {
                    if (list[i][0] != list[i - 1].Last())
                    {
                        flag = 1;
                        break;
                    }

                    for(var j=0; j<i;j++)
                    {
                        if(list[i].Length==list[j].Length)
                        {
                            for(var m =0;m<list[i].Length;m++)
                            {
                                if(list[i][m]!=list[j][m])
                                {
                                    break;
                                }
                                if(m == list[i].Length-1)
                                {
                                    flag = 1;
                                }
                            }
                        }
                        if(flag==1)
                        {
                            break;
                        }
                    }
                }
            }

            if(flag == 1)
            {
                Console.WriteLine("No");
            }
            else
            {
                Console.WriteLine("Yes");
            }
        }



    }
}