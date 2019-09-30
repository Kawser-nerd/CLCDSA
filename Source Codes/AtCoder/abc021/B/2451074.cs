using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace VirtualAtCorder
{
    class Program
    {



        static void Main(string[] args)
        {
            int townCount = int.Parse( Console.ReadLine());
            string[] startAndEnd = Console.ReadLine().Split(' ');
            int length = int.Parse(Console.ReadLine());
            string[] townTree = Console.ReadLine().Split(' ');

            bool liar = false;

            string output = "";

            int treeMax = townTree.Length;

            foreach(string c in townTree)
            {
                if(startAndEnd[0] == c)
                {
                    liar = true;
                    break;
                }
                if(startAndEnd[1] == c)
                {
                    liar = true;
                    break;
                }
            }

            townTree = townTree.Distinct().ToArray();

            if (!liar)
            {

                liar = !(treeMax == townTree.Length); ;
            }


            output = (liar) ? "NO" : "YES";

            Console.WriteLine(output);



            Console.ReadKey();
        }

    }
}