using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    class Point
    {
        internal int basic;
        internal int bonus;
        internal int num;
    }

    
    class Program
    {
        static int G;
        static int D;
        static List<string> strlist;
        static Point[] point;
        static int ans;
        
        static void MakeList(string s, int i)
        {
            if(i == D)
            {
                strlist.Add(s);
                return;
            }
            
            MakeList(s + "0", i + 1);

            MakeList(s + "1", i + 1);

        }


        static void Main(string[] args)
        {
            int[] input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            D = input[0];
            G = input[1];

            

            strlist = new List<string>();

            MakeList("", 0);

            point = new Point[D];

            for (int i = 0; i < D; i++)
            {
                string[] str = Console.ReadLine().Split(' ');
                point[i] = new Point();
                point[i].num = int.Parse(str[0]);
                point[i].bonus = int.Parse(str[1]);
                point[i].basic = (i + 1) * 100;
            }

            ans = int.MaxValue;

            for(int i = 0; i < strlist.Count; i++)
            {
                string str = strlist[i];
                int cnt = 0;
                int sum = 0;
                bool flag = false;
                //?????2?????????????
                for(int j = 0; j < strlist[i].Length; j++)
                {
                    //1??????????????
                    if(str[j] == '1')
                    {
                        //j??????????
                        //k?j??????k?????
                        for(int k = 0; k < point[j].num; k++)
                        {
                            sum += point[j].basic;
                            //Console.WriteLine($"sum = {sum}");
                            cnt++;                           
                            if(k == point[j].num - 1)
                            {
                                sum += point[j].bonus;
                            }
                            if (sum >= G)
                            {
                                if (ans > cnt) ans = cnt;
                                flag = true;
                            }
                        }

                    }

                    if (flag)
                    {
                        break;
                    }

                }

                //??????
                if(sum < G)
                {
                    //str??????????????
                    //??????????????0???????????????????????
                    for(int s = str.Length - 1; s >= 0; s--)
                    {
                        if(str[s] != '1')
                        {
                            //Console.WriteLine($"s = {s}");
                            for(int k = 0; k < point[s].num; k++)
                            {
                                sum += point[s].basic;
                                cnt++;
                                if(k < point[s].num - 1 && sum >= G)
                                {
                                    if (ans > cnt) ans = cnt;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }

                //Console.WriteLine($"str = {str}");
                //Console.WriteLine($"cnt = {cnt}");

            }

            Console.WriteLine(ans);

        }
    }
}