using System;
using System.Collections.Generic;
using System.Linq;

//ARC049-A "??"
//http://arc049.contest.atcoder.jp/tasks/arc049_a
class Program
{
    static string InputPattern = "InputX";

    static List<string> GetInputList()
    {
        var WillReturn = new List<string>();

        if (InputPattern == "Input1") {
            WillReturn.Add("MinnnahaNakayoshi");
            WillReturn.Add("0 6 8 17");
            //"Minnna"ha"Nakayoshi"
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("Niwawo_Kakemeguru_Chokudai");
            WillReturn.Add("11 17 18 26");
            //Niwawo_Kake"meguru"_"Chokudai"
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("___");
            WillReturn.Add("0 1 2 3");
            //"_"_"_"
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
        string S = InputList[0];
        int[] wkArr = InputList[1].Split(' ').Select(X => int.Parse(X)).ToArray();
        int A = wkArr[0];
        int B = wkArr[1];
        int C = wkArr[2];
        int D = wkArr[3];

        string Answer = S;
        Answer = Answer.Insert(D, @"""");
        Answer = Answer.Insert(C, @"""");
        Answer = Answer.Insert(B, @"""");
        Answer = Answer.Insert(A, @"""");
        Console.WriteLine(Answer);
    }
}