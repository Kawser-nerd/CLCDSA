using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {

        static bool ok(string a)
        {
            for (int i = 1; i < a.Length; ++i)
                if (a[i - 1] > a[i])
                    return false;
            return true;
        }
        static int bb(int n)
        {
            for (int i = n; i >= 1; --i)
            {
                if (ok(i.ToString()))
                    return i;
            }

            return 1;
        }

        static void Main(string[] args)
        {
            int cases = 0;
            int Case = Convert.ToInt32(Console.ReadLine());
            while (Case-- > 0)
            {
                
                string ins =Console.ReadLine();

                StringBuilder ans = new StringBuilder();
                ans.Append(ins[0]);
                int i;
                for (i = 1; i < ins.Length; ++i)
                {
                    if (ins[i - 1] > ins[i])
                    {
                        while (i > 1 && (ans[i - 1] == ans[i - 2]))
                            --i;
                        
                        ans[i - 1]--;
                        if (ans[i - 1] <= '0')
                            ans.Clear();
                        break;
                    }
                    ans.Append(ins[i]);
                }

                for (; i < ins.Length; ++i)
                {
                    if (i < ans.Length)
                        ans[i] = '9';
                    else
                        ans.Append('9');
                }

            /*    if (ans.ToString() != bb(Convert.ToInt32(ins)).ToString())
                {
                    Console.Write("WTF {2} {0} {1}", ans.ToString(), bb(Convert.ToInt32(ins)).ToString(), ins);
                    return;
                }*/

                Console.WriteLine("Case #{0}: {1}", ++cases, ans);

            }
        }
    }
}
