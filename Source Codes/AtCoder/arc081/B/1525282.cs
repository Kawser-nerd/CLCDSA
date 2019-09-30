using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ProCon
{

    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            string input = Console.ReadLine();
            Console.ReadLine();

            char before = ' ';
            long ans = 1;
            int state = 0; //0: start 1:tate 2:yoko
            bool isrenzoku = false;
            foreach(char ch in input)
            {
                if(before == ' ')
                {
                    
                }
                else if (ch == before)
                {
                    isrenzoku = true;
                }
                else
                {
                    if (isrenzoku)
                    {
                        isrenzoku = false;
                        if (state == 0)
                        {
                            ans = (ans * 6) % 1000000007;
                        }
                        else if (state == 1)
                        {
                            ans = (ans * 2) % 1000000007;
                        }
                        else
                        {
                            ans = (ans * 3) % 1000000007;
                        }
                        state = 2;
                    }
                    else
                    {
                        if (state == 0)
                        {
                            ans = (ans * 3) % 1000000007;
                        }
                        else if (state == 1)
                        {
                            ans = (ans * 2) % 1000000007;
                        }
                        else
                        {
                        }
                        state = 1;
                    }                       
                }
                before = ch;
            }
            if (isrenzoku)
            {
                isrenzoku = false;
                if (state == 0)
                {
                    ans = (ans * 6) % 1000000007;
                }
                else if (state == 1)
                {
                    ans = (ans * 2) % 1000000007;
                }
                else
                {
                    ans = (ans * 3) % 1000000007;
                }
                state = 2;
            }
            else
            {
                if (state == 0)
                {
                    ans = (ans * 3) % 1000000007;
                }
                else if (state == 1)
                {
                    ans = (ans * 2) % 1000000007;
                }
                else
                {
                }
                state = 2;
            }
            Console.WriteLine(ans);
        }
    }

}