using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoderGrandContest010
{
    class ProgramB
    {
        private const string kYes = "YES";
        private const string kNo = "NO";
        static void Main(string[] args)
        {
            string szTotal = Console.ReadLine();
            int nTotal = int.Parse(szTotal);
            long[] arr = new long[nTotal];

            string szLine = Console.ReadLine();
            string[] szSplittedLine = szLine.Split(' ');

            for (int i = 0; i < szSplittedLine.Length; ++i)
            {
                long a = long.Parse(szSplittedLine[i]);
                arr[i] = a;
            }
            string ret = Solve(arr) ? kYes : kNo;
            Console.WriteLine(ret);
        }

        private static bool Solve(long[] arr)
        {
            long nTotal = arr.Length;
            long nStoneTotal = 0;// ???
            for (int i = 0; i < arr.Length; ++i)
            {
                nStoneTotal += arr[i];
            }

            long nSubTotal = (nTotal * (nTotal + 1)) / 2;// ???????????

            if (nStoneTotal % nSubTotal != 0) { return false; ; }
            long step = nStoneTotal / nSubTotal;// K?????

            // ???????????????
            long[] arr_custom = new long[nTotal];
            for (int i = 0; i < arr_custom.Length; ++i)
            {
                long dt = arr[(i + 1) % nTotal] - arr[i];
                arr_custom[i] = dt - step;
            }

            // ???? N ????? K??N???????????
            long nAddTotal = 0;
            for (int i = 0; i < arr_custom.Length; ++i)
            {
                long dt = arr_custom[i];
                if (dt > 0) { return false; }
                if( dt == 0) { continue; }
                if (Math.Abs(dt) % nTotal != 0) { return false; }
                nAddTotal += Math.Abs( dt) / nTotal;
            }
            if( nAddTotal != step) { return false; }
            return true;
        }
    }
}