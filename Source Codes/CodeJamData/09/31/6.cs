using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Csharp
{
    class A
    {
        static void Main(string[] args)
        {
            int T,ca=0;
            T = Convert.ToInt32(Console.ReadLine());
	        for (; T > 0; --T) {
		        string line;
                SortedList<char, int> aa = new SortedList<char,int>();
                line = Console.ReadLine();
		        aa[line[0]] = 1;
		        int cur = 0;
		        for (int i = 1; i < line.Length; ++i) {
                    if (!aa.ContainsKey(line[i])) {
				        aa[line[i]] = cur++;
				        if (cur == 1) ++cur;
			        }
		        }
		        int ba = aa.Count > 1 ? aa.Count : 2;
		        Decimal res;
		        res = 0;
		        for (int i = 0; i < line.Length; ++i) {
			        res = res * ba + aa[line[i]];
		        }

                Console.WriteLine("Case #{0}: {1}", ++ca, res);
	        }
        }
    }
}
