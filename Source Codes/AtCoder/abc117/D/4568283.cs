using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    
    class Program
    {

        static int numofbinarydigit = 40;

        //O(numofbinarydigit)
        static long ChangeBinaryToDecimal(int[] binary)
        {
            long deci = 0;

            int expo = 0;
            for(int i = numofbinarydigit - 1; i >= 0; i--)
            {
                if(binary[i] == 1)
                {
                    deci += (long)Math.Pow(2, expo) * binary[i];
                }
                expo++;
            }
            
            return deci;
        }

        //O(numofbinarydigit)
        static int[] ChangeDecimalToBinary(long deci)
        {
            int[] binary = new int[numofbinarydigit];

            long quotient = deci;
            long remainder = 0;
            int indexnum = numofbinarydigit - 1;

            while (quotient != 0)
            {
                remainder = quotient % 2;
                quotient /= 2;
                binary[indexnum] = (int)remainder;
                indexnum--;              
            }

            return binary;
        }

        //O(1)
        static bool IsLessThan_max_x(int[] check_binary, int indexnum, int alt_num, long max_x)
        {
            bool ans = true;

            int origin_num = check_binary[indexnum];
            check_binary[indexnum] = alt_num;

            if(ChangeBinaryToDecimal(check_binary) > max_x)
            {
                ans = false;
            }

            check_binary[indexnum] = origin_num;

            return ans;
        }

        //O(numofbinarydigit)
        static int[] XOR(int[] binary1, int[] binary2)
        {
            int[] ans_binary = new int[binary1.Length];

            for(int i = 0; i < binary1.Length; i++)
            {
                if (binary1[i] != binary2[i])
                {
                    ans_binary[i] = 1;
                }
                else
                {
                    ans_binary[i] = 0;
                }
            }

            return ans_binary;
        }

        
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int numofdata = int.Parse(input[0]);
            long max_x = long.Parse(input[1]);

            long[] data_decimal = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
            int[][] data_binary = new int[numofdata][];
            int[] x_binary = new int[numofbinarydigit];

            for(int i = 0; i < numofdata; i++)
            {
                data_binary[i] = ChangeDecimalToBinary(data_decimal[i]);               
            }            
            
            //O(numofbinarydigit * numofdata)
            for(int secondpar = 0; secondpar < numofbinarydigit; secondpar++)
            {

                int numofone = 0;
                int numofzero = 0;
                for(int firstpar = 0; firstpar < numofdata; firstpar++)
                {
                    if(data_binary[firstpar][secondpar] == 1)
                    {
                        numofone++;
                    }
                    else
                    {
                        numofzero++;
                    }
                }

                //????ans_binary?max_x????????
                //numofone = numofzero ???0?ans_binary?????????
                if(numofone < numofzero)
                {
                    if(IsLessThan_max_x(x_binary, secondpar, 1, max_x))
                    {
                        x_binary[secondpar] = 1;
                    }
                    else
                    {
                        x_binary[secondpar] = 0;
                    }
                }
                else
                {
                    x_binary[secondpar] = 0;
                }
                
            }
            
            long ans_decimal = 0;

            for(int i = 0; i < numofdata; i++)
            {                
                ans_decimal += ChangeBinaryToDecimal(XOR(x_binary, data_binary[i]));
            }

            Console.WriteLine(ans_decimal);

        }
    }
}