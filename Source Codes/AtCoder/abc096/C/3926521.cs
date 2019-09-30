using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {
        
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int h = int.Parse(input[0]);
            int w = int.Parse(input[1]);

            char[,] data = new char[h + 1, w + 1];
            for(int i = 1; i <= h; i++)
            {
                string s = Console.ReadLine();
                for(int j = 1; j <= w; j++)
                {
                    //Console.WriteLine($"i = {i} j = {j}");
                    data[i, j] = s[j - 1];
                }
            }

            for(int i = 1; i <= h; i++)
            {
                for(int j = 1; j <= w; j++)
                {
                    if (data[i, j] != '#') continue;
                    bool flag = false;
                    //1
                    if (i == 1 && j == 1)
                    {
                        if(w >= 2)
                        {
                            if (data[i, j + 1] == '#') flag = true;                           
                        }
                        if(h >= 2)
                        {
                            if (data[i + 1, j] == '#') flag = true;
                        }
                    }//2
                    else if(i == 1 && j == w)
                    {
                        if (data[i, j - 1] == '#') flag = true;
                        if(h >= 2)
                        {
                            if (data[i + 1, j] == '#') flag = true;
                        }
                    }//3
                    else if(i == h && j == 1)
                    {
                        if (data[i - 1, j] == '#') flag = true;
                        if(w >= 2)
                        {
                            if (data[i, j + 1] == '#') flag = true;
                        }
                    }//4
                    else if(i == h && j == w)
                    {
                        if (data[i - 1, j] == '#') flag = true;
                        if (data[i, j - 1] == '#') flag = true;
                    }//5
                    else
                    {
                        if(i == 1)
                        {
                            if (data[i, j - 1] == '#' || data[i, j + 1] == '#' || data[i + 1, j] == '#') flag = true;
                        }
                        else if(i == h)
                        {
                            if (data[i, j - 1] == '#' || data[i, j + 1] == '#' || data[i - 1, j] == '#') flag = true;
                        }
                        else
                        {
                            if(j == 1)
                            {
                                if (data[i - 1, j] == '#' || data[i, j + 1] == '#' || data[i + 1, j] == '#') flag = true;
                            }
                            else if(j == w)
                            {
                                if (data[i - 1, j] == '#' || data[i, j - 1] == '#' || data[i + 1, j] == '#') flag = true;
                            }
                            else
                            {
                                if (data[i - 1, j] == '#' || data[i, j - 1] == '#' || data[i + 1, j] == '#' || data[i, j + 1] == '#') flag = true;
                            }
                        }
                    }

                    if (!flag)
                    {
                        Console.WriteLine("No");
                        return;
                    }

                }
            }


            Console.WriteLine("Yes");

        }
    }
}