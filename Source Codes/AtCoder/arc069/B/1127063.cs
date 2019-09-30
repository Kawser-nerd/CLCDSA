using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
 
class Program
    {
        static void Main(string[] args)
        {
            //var sr = new System.IO.StreamReader(@"test.txt", Encoding.UTF8);
            //string line = sr.ReadLine();
            string line = System.Console.ReadLine().Trim();
 
            int N = int.Parse(line);
 
 
            line = System.Console.ReadLine().Trim();
            //line = sr.ReadLine();
            string[] s = new string[line.Length];
 
            for (int i = 0; i < line.Length; i++)
            {
                s[i] = line[i].ToString();
            }
 
 
            List<XY> value = new List<XY>();
            XY xy = new XY();
            xy.x = 0;
            xy.y = 0;
            value.Add(xy);
 
            xy = new XY();
            xy.x = 0;
            xy.y = 1;
            value.Add(xy);
 
            xy = new XY();
            xy.x = 1;
            xy.y = 0;
            value.Add(xy);
 
            xy = new XY();
            xy.x = 1;
            xy.y = 1;
            value.Add(xy);
 
            List<int> output = new List<int>();
 
 
            bool flag = false;
 
            for (int j = 0; j < 4; j++)
            {
                int x = value[j].x;
                int y = value[j].y;
                int z = 0;
 
                List<int> list = new List<int>();
                list.Add(x);
                list.Add(y);
 
 
 
                for (int i = 1; i <= N - 1; i++)
                {
                    int sahen = x % 2;
                    int uhen = y % 2;
 
                    if (sahen == uhen)
                    {
                        if (s[i] == "o")
                        {
                            z = 0;
                        }
                        else if (s[i] == "x")
                        {
                            z = 1;
                        }
                    }
                    else if (sahen != uhen)
                    {
                        if (s[i] == "o")
                        {
 
                            z = 1;
 
                        }
                        else if (s[i] == "x")
                        {
                            z = 0;
 
                        }
                    }
 
                    list.Add(z);
 
                    x = y;
                    y = z;
                }
 
                output = list;
 
 
 
 
                if (list[0] == list[N])
                {
                    int sahen = x % 2;
                    int uhen = y % 2;
 
                    if (sahen == uhen)
                    {
                        if (s[0] == "o")
                        {
                            if (list[1] == 0)
                            {
                                flag = true;
                            }
 
                        }
                        else if (s[0] == "x")
                        {
                            if (list[1] == 1)
                            {
                                flag = true;
                            }
 
                        }
                    }
                    else if (sahen != uhen)
                    {
                        if (s[0] == "o")
                        {
                            if (list[1] == 1)
                            {
                                flag = true;
                            }
 
                        }
                        else if (s[0] == "x")
                        {
                            if (list[1] == 0)
                            {
                                flag = true;
                            }
 
                        }
                    }
 
                }
 
 
 
                if (flag == true)
                {                    
                    break;
                }
            }
 
            if(flag == false)
            {
                System.Console.WriteLine("-1");
            }
            else
            {
 
                for (int i = 0; i < N; i++)
                {
                    if(output[i] == 0)
                    {
                        System.Console.Write("S");
                    }
                    else
                    {
                        System.Console.Write("W");
                    }
                }
                System.Console.WriteLine("");                
            }
        }
    }
 
class XY
{
    public int x;
    public int y;
}