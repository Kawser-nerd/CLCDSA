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
            WillReturn.Add("3 4");
            WillReturn.Add("2 1 3");
            WillReturn.Add("3 1 2 3");
            WillReturn.Add("2 3 2");
            //1
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("5 5");
            WillReturn.Add("4 2 3 4 5");
            WillReturn.Add("4 1 3 4 5");
            WillReturn.Add("4 1 2 4 5");
            WillReturn.Add("4 1 2 3 5");
            WillReturn.Add("4 1 2 3 4");
            //0
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("1 30");
            WillReturn.Add("3 5 10 30");
            //3
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

        var AArrList = new List<int[]>();
        foreach (string EachStr in InputList.Skip(1)) {
            int[] wkArr = { };
            Action<string> SplitAct = pStr =>
                wkArr = pStr.Split(' ').Select(X => int.Parse(X)).Skip(1).ToArray();
            SplitAct(EachStr);
            AArrList.Add(wkArr);
        }

        var InterSectArrSet = new HashSet<int>(AArrList[0]);
        for (int I = 1; I <= AArrList.Count - 1; I++) {
            InterSectArrSet.IntersectWith(AArrList[I]);
        }
        Console.WriteLine(InterSectArrSet.Count);
    }
}