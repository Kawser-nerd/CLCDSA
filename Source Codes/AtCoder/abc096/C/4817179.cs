using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var hw = Console.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();
        var H = hw[0];
        var W = hw[1];
        var array = new int[H,W];
        for (int i=0;i<H;++i)
        {
            var line = Console.ReadLine();
            for (int j=0;j<W;++j)
            {
                array[i, j] = line[j];
            }
        }
        var disable = false;
        for (int i=0;i<H;++i)
        {
            for (int j=0;j<W;++j)
            {
                if(array[i,j]== '#')
                {
                    if ((i != 0 && array[i - 1, j] == '#')
                        || (i != H - 1 && array[i + 1, j] == '#')
                        || (j != 0 && array[i, j - 1] == '#')
                        || (j != W - 1 && array[i, j + 1] == '#')) ;
                    else
                    {
                        disable = true;
                        break;
                    }
                }
            }
            if (disable) break;
        }
        Console.WriteLine(disable?"No":"Yes");
    }
}