using System;
    using System.Collections.Generic;
    using static System.Console;
    using System.Linq;


class Program
{
    static void Main(string[] Args) {
        int N = Int32.Parse(ReadLine());
        string stn = N.ToString();

        bool isten = true;
        if (stn[0] != '1') isten = false;
        for(int i = 1;i < stn.Length; i++) {
            if (stn[i] != '0') isten = false;
        }
        int Result = 0;
        if (isten) Result = 10;
        else {
            foreach(char c in stn) {
                Result += Int32.Parse(c.ToString());
            }
        }

        WriteLine(Result);

        ReadLine();
    }
}