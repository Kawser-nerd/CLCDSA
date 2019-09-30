using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();
            string sT = Console.ReadLine().Trim();

            // ??
            string sOut = "";
            if (!sS.Contains("@") && !sT.Contains("@"))
            {
                if (sS == sT) { sOut = "You can win"; }
                else { sOut = "You will lose"; }
            }
            else
            {
                Boolean bOK = true;
                for (int i = 0; i < sS.Length; i++)
                {
                    if (sS.Substring(i, 1) == sT.Substring(i, 1)) { }
                    else
                    {
                        if (sS.Substring(i, 1) == "@" || sT.Substring(i, 1) == "@")
                        {
                            if (sS.Substring(i, 1) == "@")
                            {
                                if (chkExists(sT.Substring(i, 1))) { }
                                else { bOK = false; break; }
                            }
                            else
                            {
                                if (chkExists(sS.Substring(i, 1))) { }
                                else { bOK = false; break; }
                            }
                        }
                        else { bOK = false; break; }
                    }
                }
                if (bOK) { sOut = "You can win"; }
                else { sOut = "You will lose"; }
            }

            //??
            Console.WriteLine("{0}", sOut.ToString());

#if DEBUG
        Console.WriteLine("?????????????????????");
        Console.ReadKey();
#endif

    }

        public static Boolean chkExists(string sD)
        {
            Boolean bEx = false;
            switch (sD)
            {
                case "a":
                case "t":
                case "c":
                case "o":
                case "d":
                case "e":
                case "r":
                    bEx= true;
                    break;
            }
            return bEx;
        }

}