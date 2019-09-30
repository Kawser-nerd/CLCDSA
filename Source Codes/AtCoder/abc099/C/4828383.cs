using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - Strange Bank
            int n = int.Parse(Console.ReadLine());
            int minCount = n;
            
            for(int i = 0; i <= 11111; i++)
            {
                if(i * 9 > n)
                {
                    break;    
                }
                else
                {
                    int rest = n - i * 9;
                    int remainder = rest % 6;
                    
                    int count = DrawerNineYen(i * 9);
                    count += DrawerSixYen(rest - remainder);
                    count += remainder;
                    
                    if(count < minCount)
                    {
                        minCount = count;    
                    }
                }
            }
            
            Console.WriteLine(minCount);
        }
        
        static int DrawerNineYen(int money)
        {
            int count = 0;
            var nines = new int[] { 59049, 6561, 729, 81, 9 };
            
            foreach(var nine in nines)
            {
                count += money / nine;
                money %= nine;
            }
            
            return count;
        }
        
        static int DrawerSixYen(int money)
        {
            int count = 0;
            var sixs = new int[] { 46656, 7776, 1296, 216, 36, 6 };
            
            foreach(var six in sixs)
            {
                count += money / six;
                money %= six;
            }
            
            return count;
        }
    }
}