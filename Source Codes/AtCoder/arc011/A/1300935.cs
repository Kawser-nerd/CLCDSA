using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

public class Hello
{
    public static void Main()
    {
        int[] m_n_N = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int m = m_n_N[0];
        int n = m_n_N[1];
        int N = m_n_N[2];

        int products = N;
        int allProducts = N;

        while(true)
        {
            if(products >= m)
            {
                int recycle = products / m;
                products = (recycle * n) + (products % m);
                allProducts += recycle * n;
            }
            else
            {
                break;
            }
        }
        Console.WriteLine(allProducts);
    }
}