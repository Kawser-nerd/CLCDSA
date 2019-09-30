using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForArRecoder
{
    class Program
    {
        static void Main(string[] args)
        {
            Comand comand = new Comand();
       
                Console.WriteLine(comand.AllAttack());
            Console.ReadLine();
        }    
    }

    class Comand
    {
        int length;
        char[] input;
        int minimumCount = 0;

        public Comand()
        {
            length = int.Parse(Console.ReadLine().ToString());
            input = Console.ReadLine().ToCharArray();
        }


        public int AllAttack()
        {
           
            char[] comand = { 'A', 'B', 'X', 'Y' };
            for(int i = 0; i < comand.Length; i++)
            {
                for(int j = 0; j < comand.Length; j++)
                {
                    for(int k = 0; k < comand.Length; k++)
                    {
                        for (int l = 0; l < comand.Length; l++)
                        {
                            char[] left = { comand[i], comand[j] };
                            char[] right = { comand[k], comand[l]};
                            Check(left, right);
                        }
                    }
                }
            }
            return minimumCount;
        }

        private void Check(char[] left,char[] right)
        {
            int count = 0;
            for (int i = 0; i < length;)
            {
                if ((length - 1) == i)
                {
                    count++;
                    break;
                }
                if ((input[i] == left[0] && input[i + 1] == left[1]) ||
                    (input[i] == right[0] && input[i + 1] == right[1]))
                {
                    count++;
                    i++;
                    i++;
                    continue;
                }
                else
                {
                    count++;
                    i++;
                    continue;
                }
                if(i >= length - 1)
                {
                    
                    break;
                }
            
            }
            if(minimumCount == 0)
            {
                minimumCount = count;
            }
            if(minimumCount > count)
            {
                minimumCount = count;
            }
        }

       
       
    }
}