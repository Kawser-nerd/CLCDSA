using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace template
{
    class Program
    {
        static void Main(string[] args)
        {
            string imp = Console.ReadLine();//???????????????
            string first = Convert.ToString(imp[0]);//???????1?????
            string second = Convert.ToString(imp[1]);
            string third = Convert.ToString(imp[2]);

            int counta = 0;
            int countb = 0;
            int countc = 0;


            if (((first == "a")||(second == "a"))||(third == "a")) {
                counta++;
            }

            if (((first == "b") || (second == "b")) || (third == "b"))
            {
                countb++;
            }

            if (((first == "c") || (second == "c")) || (third == "c"))
            {
                countc++;
            }

            if (((counta == 1) && (countb == 1)) && (countc == 1))
            {
                Console.WriteLine("Yes");
            }



            else {
                Console.WriteLine("No");
            }
            
            
        }
    }
}