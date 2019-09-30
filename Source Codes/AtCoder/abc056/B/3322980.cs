using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iWid = int.Parse(sS[0]);                            // ?
            int iAx1 = int.Parse(sS[1]);                            // A???
            int iBx1 = int.Parse(sS[2]);                            // B???

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iAx2 = iAx1 + iWid;                                 // A???
            int iBx2 = iBx1 + iWid;                                 // B???
            int iOut = 0;                                           // ???
            Boolean bLnk = false;                                   // ????
            if (iAx1 <= iBx1 && iBx1 <= iAx2) { bLnk = true; }      // A????B???????????
            if (iAx1 <= iBx2 && iBx2 <= iAx2) { bLnk = true; }      // A????B???????????
            if (!bLnk)                                              // ?????????
            {
                Boolean bRig = false;                               // B?A????????
                if (iAx1 < iBx1) { bRig = true; }                   // B?A???????
                if (bRig) { iOut = iBx1 - iAx2; }                   // B????A???????(B?A???????)
                else { iOut = iAx1 - iBx2; }                        // B????A???????(B?A???????)
            }

            //??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}