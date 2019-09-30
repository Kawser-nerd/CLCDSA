using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC002_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var z = scan();
            var a = scan();
            int last=0;
            bool flag=false;
            for (int i = 0; i < z[0]-1; i++)
            {
                if (a[i]+a[i+1]>=z[1])
                {
                    last = i + 1;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                var sb = new StringBuilder();
                sb.AppendLine("Possible");
                for (int i = 1; i < last; i++)
                {
                    sb.AppendLine(i.ToString());
                }
                for (int i = z[0]-1; i > last; i--)
                {
                    sb.AppendLine(i.ToString());
                }
                sb.AppendLine(last.ToString());
                Console.Write(sb);
            }
            else
            {
                Console.WriteLine("Impossible");
            }
                   
        }
        static int[] scan()
        {
            return
                Array.ConvertAll
                (Console.ReadLine().Split(' '), int.Parse);
        }
    }
}