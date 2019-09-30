using System;
using System.Collections.Generic;
class Solution
{
    static void Main(string[] args)
    {
        List<int> data = new List<int>();
        int n = int.Parse(System.Console.ReadLine().Trim()),sum=0;
        for (int i = 0; i < n; i++) 
        {
            int x =int.Parse(System.Console.ReadLine().Trim());
            data.Add(x);
            sum += x;
        }
        data.Sort((a, b) => a-b);
        int pos = -1,kai=0;
        if (sum % 10 == 0)
        {
            for(int i = 0;i<data.Count;i++)
            {
                if (data[i] % 10 != 0) { pos = i; break; }
            }
            if (pos == -1) kai = 0;
            else kai = sum - data[pos];
        }
        else
        {
            kai = sum;
        }
        System.Console.WriteLine(kai);
        System.Console.ReadLine();
    }
}