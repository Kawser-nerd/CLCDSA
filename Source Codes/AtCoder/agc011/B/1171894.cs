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
            WillReturn.Add("3");
            WillReturn.Add("3 1 4");
            //2
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("5");
            WillReturn.Add("1 1 1 1 1");
            //5
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("6");
            WillReturn.Add("40 1 30 2 7 20");
            //4
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
        long[] AArr = InputList[1].Split(' ').Select(X => long.Parse(X)).ToArray();
        Array.Sort(AArr);

        long Ruisekiwa = 0;
        bool HasBundan = false;
        int BundanInd = 0;
        for (int I = 0; I <= AArr.GetUpperBound(0) - 1; I++) {
            Ruisekiwa += AArr[I];

            if (Ruisekiwa * 2 < AArr[I + 1]) {
                HasBundan = true;
                BundanInd = I;
            }
        }
        if (HasBundan) Console.WriteLine(AArr.Length - BundanInd - 1);
        else Console.WriteLine(AArr.Length);
    }
}