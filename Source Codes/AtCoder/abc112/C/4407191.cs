using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var N = Int32.Parse(Console.ReadLine());
        var list = new List<long[]>();
        for (int i=0;i<N;++i)
        {
            var xyh = Console.ReadLine().Split(' ').Select(num => Int64.Parse(num)).ToArray();
            var x = xyh[0];
            var y = xyh[1];
            var h = xyh[2];
            list.Add(new long[3] { x, y, h });
        }
        var kizyun = list.Where(x=>x[2]!=0).First();
        for (int i=0;i<=100;++i)
        {
            for (int j=0;j<=100;++j)
            {
                var height = kizyun[2]+ Math.Abs(kizyun[0] - i) + Math.Abs(kizyun[1] - j);
                var isCorrect = true;
                for (int k = 0; k < N; ++k)
                {
                    if (Math.Max(0,height- Math.Abs(list[k][0] - i) - Math.Abs(list[k][1] - j)) != list[k][2])
                    {
                        isCorrect = false;
                        break;
                    }
                }
                if (isCorrect)
                {
                    Console.WriteLine($"{i} {j} {height}");
                    return;
                }
            }
        }
    }
}