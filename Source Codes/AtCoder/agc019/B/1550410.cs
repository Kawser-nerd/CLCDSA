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
            WillReturn.Add("aatt");
            //5
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("xxxxxxxxxx");
            //1
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("abracadabra");
            //44
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
        string A = InputList[0];

        long Answer = 1 + Derive_nC2(A.Length);
        foreach (var Each in A.ToCharArray().GroupBy(X => X)) {
            if (Each.Count() <= 1) continue;
            Answer -= Derive_nC2(Each.Count());
        }
        Console.WriteLine(Answer);
    }

    //nC2???
    static long Derive_nC2(long pN)
    {
        return pN * (pN - 1) / 2;
    }
}