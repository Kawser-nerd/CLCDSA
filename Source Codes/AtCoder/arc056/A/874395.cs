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
            WillReturn.Add("3 7 10 3");
            //24
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("4 5 11 3");
            //20
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("3 8 3 3");
            //8
        }
        else if (InputPattern == "Input4") {
            WillReturn.Add("3 8 2 3");
            //6
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
        long A = wkArr[0];
        long B = wkArr[1];
        long K = wkArr[2];
        long L = wkArr[3];

        long Answer = 0;
        long Rest = K;

        //????????????
        if (Rest >= L) {
            Answer += B * (K / L);
            Rest %= L;
        }

        if (Rest > 0) {
            //????????
            long wkSum1 = B;

            //???????
            long wkSum2 = A * Rest;

            Answer += Math.Min(wkSum1, wkSum2);
        }

        Console.WriteLine(Answer);
    }
}