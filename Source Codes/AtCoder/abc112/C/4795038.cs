using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var x = new int[N];
            var y = new int[N];
            var h = new int[N];

            for (int i = 0; i < N; i++)
            {
                var str = Console.ReadLine();
                var strs = str.Split(' ');
                x[i] = int.Parse(strs[0]);
                y[i] = int.Parse(strs[1]);
                h[i] = int.Parse(strs[2]);
            }

            var MAX = 100;

            for (int posY = 0; posY <= MAX; posY++)
            {
                for (int posX = 0; posX <= MAX; posX++)
                {
                    int needH = -1;

                    for (int i = 0; i < N; i++)
                    {
                        if (h[i] > 0)
                        {
                            int tmp = h[i] + Math.Abs(posY - y[i]) + Math.Abs(posX - x[i]);
                            if (needH == -1)
                            {
                                needH = tmp;
                            }
                            else
                            {
                                if (needH != tmp)
                                {
                                    needH = -2;
                                    break;
                                }
                            }
                        }
                    }

                    if (needH == -2) continue;

                    for (int i = 0; i < N; i++)
                    {
                        if (h[i] == 0)
                        {
                            var dist = Math.Abs(posY - y[i]) + Math.Abs(posX - x[i]);
                            if (needH > dist)
                            {
                                needH = -2;
                                break;
                            }
                        }
                    }

                    if (needH == -2) continue;

                    Console.WriteLine(posX + " " + posY + " " + needH);
                    return;
                }
            }
        }
    }
}