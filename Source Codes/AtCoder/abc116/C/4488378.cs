using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
class Program
{
    static void Main(string[] args)
    {
        string temp = System.Console.ReadLine();
        int N = int.Parse(temp);
        string[] temp1 = System.Console.ReadLine().Split(' ');
        int[] H = new int[N];
        int plusnum = 0;
        for (int i = 0; i < N; i++)
        {
            H[i] = int.Parse(temp1[i]);
            if (i == 0) { plusnum = H[i]; }
            else if (i >= 1&&(H[i]-H[i-1])>0)
            {
                plusnum += H[i] - H[i - 1];
            }
        }
        Console.WriteLine(plusnum);
    }
}