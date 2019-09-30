using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApp7
{
    class Program
    {
        static void Main(string[] args)
        {

            string A = Console.ReadLine();
            string B = Console.ReadLine();
            string C = Console.ReadLine();

            int countA = 0;//
            int countB = -1;
            int countC = -1;
            var flagA = true;
            var flagB = false;
            var flagC = false;


            while (A.Length > countA && B.Length > countB && C.Length > countC)
            {


                if (flagA == true)
                {
                    flagA = false;
                    if (A[countA] == 'a')
                    {
                        countA++;
                        flagA = true;
                    }
                    else if (A[countA] == 'b')
                    {
                        countB++;
                        flagB = true;
                    }
                    else if (A[countA] == 'c')
                    {
                        countC++;
                        flagC = true;
                    }
                }
                else if (flagB == true)
                {
                    flagB = false;
                    if (B[countB] == 'a')
                    {
                        countA++;
                        flagA = true;
                    }
                    else if (B[countB] == 'b')
                    {
                        countB++;
                        flagB = true;
                    }
                    else if (B[countB] == 'c')
                    {
                        countC++;
                        flagC = true;
                    }
                }
                else if (flagC == true)
                {
                    flagC = false;
                    if (C[countC] == 'a')
                    {
                        countA++;
                        flagA = true;
                    }
                    else if (C[countC] == 'b')
                    {
                        countB++;
                        flagB = true;
                    }
                    else if (C[countC] == 'c')
                    {
                        countC++;
                        flagC = true;
                    }
                }
            }

            if (flagA == true)
            {
                Console.WriteLine('A');
            }
            else if(flagB == true)
            {
                Console.WriteLine('B');
            }
            else
            {
                Console.WriteLine('C');
            }


        }

    }
}