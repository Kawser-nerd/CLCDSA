using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        string[] line = System.Console.ReadLine().Trim().Split(' ');
        int n = int.Parse(line[0]);
        int m = int.Parse(line[1]);

        //m???????

        List<int> list = new List<int>();

        for(int i = 1; i<= Math.Sqrt(m);i++)
        {
            if(m%i == 0)
            {
                list.Add(i);
                if (i!= m/1)
                {
                    list.Add(m / i);
                }
            }
        }

        //m/n????????????????
        int rlt = 1;
        foreach(int i in list)
        {
            if(i<= m/n && i > rlt)
            {
                rlt = i;
            }
        }

        System.Console.WriteLine(rlt.ToString());

    }
}