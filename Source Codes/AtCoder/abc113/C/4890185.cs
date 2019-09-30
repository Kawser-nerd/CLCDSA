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
            WillReturn.Add("2 3");
            WillReturn.Add("1 32");
            WillReturn.Add("2 63");
            WillReturn.Add("1 12");
            //000001000002
            //000002000001
            //000001000001
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("2 3");
            WillReturn.Add("2 55");
            WillReturn.Add("2 77");
            WillReturn.Add("2 99");
            //000002000001
            //000002000002
            //000002000003
        }
        else {
            string wkStr;
            while ((wkStr = Console.ReadLine()) != null) WillReturn.Add(wkStr);
        }
        return WillReturn;
    }

    struct PairDef
    {
        internal int P;
        internal int M;
    }

    static void Main()
    {
        List<string> InputList = GetInputList();

        int[] wkArr = { };
        Action<string> SplitAct = pStr =>
            wkArr = pStr.Split(' ').Select(X => int.Parse(X)).ToArray();

        var PairList = new List<PairDef>();
        foreach (string EachStr in InputList.Skip(1)) {
            SplitAct(EachStr);
            PairDef WillAdd;
            WillAdd.P = wkArr[0];
            WillAdd.M = wkArr[1];
            PairList.Add(WillAdd);
        }

        int CurrP = -1;
        int MCnt = 0;
        var HashDict = new Dictionary<string, string>();
        foreach (PairDef EachPair in PairList.OrderBy(X => X.P).ThenBy(X => X.M)) {
            if (CurrP != EachPair.P) {
                CurrP = EachPair.P;
                MCnt = 1;
            }
            else MCnt++;

            string Hash = string.Format("{0},{1}", EachPair.P, EachPair.M);
            HashDict.Add(Hash, string.Format("{0:D6}{1:D6}", EachPair.P, MCnt));
        }

        foreach (PairDef EachPair in PairList) {
            string Hash = string.Format("{0},{1}", EachPair.P, EachPair.M);
            Console.WriteLine(HashDict[Hash]);
        }
    }
}