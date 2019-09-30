using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static string InputPattern = "InputX";

    static List<string> GetInputList()
    {
        var WillReturn = new List<string>();

        if (InputPattern == "Input1") {
            WillReturn.Add("5 1 5 2 4");
            //YES
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("4 7 6 4 5");
            //NO
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("48792 105960835 681218449 90629745 90632170");
            //NO
        }
        else if (InputPattern == "Input4") {
            WillReturn.Add("491995 412925347 825318103 59999126 59999339");
            //YES
        }
        else {
            string wkStr;
            while ((wkStr = Console.ReadLine()) != null) WillReturn.Add(wkStr);
        }
        return WillReturn;
    }

    static void Main()
    {
        List<string> InputList = GetInputList();
        long[] wkArr = InputList[0].Split(' ').Select(X => long.Parse(X)).ToArray();
        long N = wkArr[0];
        long A = wkArr[1];
        long B = wkArr[2];
        long C = wkArr[3];
        long D = wkArr[4];

        bool IsOK = false;

        //+??????
        for (int I = 0; I <= N - 2; I++) {
            long MinusCnt = N - 1 - I;

            long MinVal = A + C * I - D * MinusCnt;
            long MaxVal = A + D * I - C * MinusCnt;

            //Console.WriteLine("+?{0}???-?{1}??????={2}", I, MinusCnt, MinVal);
            //Console.WriteLine("+?{0}???-?{1}??????={2}", I, MinusCnt, MaxVal);

            if (MinVal <= B && B <= MaxVal) {
                IsOK = true;
                break;
            }
        }
        Console.WriteLine(IsOK ? "YES" : "NO");
    }
}