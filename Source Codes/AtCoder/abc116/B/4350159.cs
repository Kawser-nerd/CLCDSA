using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            int s;
            int m = 0;
            s = int.Parse(Console.ReadLine());
            var array = new List<int>{s};

            for (var i = 0; ;i++)//??????????
            {
                if(array[i] % 2 != 0)
                {
                    array.Add(array[i] * 3 + 1);
                }else{
                    array.Add(array[i] / 2);
                }
                for (var j = 0; j < array.Count-1 ;j++)
                {
                    if (array[i+1] ==array[j])
                    {
                        m = i + 2;//??????index?1??????
                        break;
                    }
                }
                if(m != 0)
                {
                    break;
                }
            }
            Console.WriteLine(m);
        }

    }
}