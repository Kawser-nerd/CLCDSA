using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtcoderTemplateForCSharp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');

            var n = int.Parse(input[0]);
            var m = int.Parse(input[1]);

            var listA = new List<List<char>>();

            var listB = new List<List<char>>();

            for (var i = 0; i < n; i++)
            {
                listA.Add(new List<char>());
                var inputString = Console.ReadLine();

                for (var j = 0; j < n; j++)
                {
                    listA[i].Add(inputString[j]);
                }
            }

            for (var i = 0; i < m; i++)
            {
                listB.Add(new List<char>());
                var inputString = Console.ReadLine();

                for (var j = 0; j < m; j++)
                {
                    listB[i].Add(inputString[j]);
                }
            }

            var flag = true;

            for (var i = 0; i < n - m + 1; i++)
            {
                for (var j = 0; j < n - m + 1; j++)
                {
                    for (var k = 0; k < m; k++)
                    {
                        for (var l = 0; l < m; l++)
                        {
                            if (listA[i + k][j + l] == listB[k][l])
                            {
                                flag = true;
                            }
                            else
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag)
                        {
                            break;
                        }
                    }
                    if (flag)
                    {
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
            if (flag)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}