using System;
using System.Collections.Generic;

//ARC055-A-????
//http://arc055.contest.atcoder.jp/tasks/arc055_a
class Program
{
    static string InputPattern = "InputX";

    static List<string> GetInputList()
    {
        var WillReturn = new List<string>();

        if (InputPattern == "Input1") {
            WillReturn.Add("9");
            //1000000007
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("3");
            //1007
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("50");
            //100000000000000000000000000000000000000000000000007
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
        int N = int.Parse(InputList[0]);

        var sb = new System.Text.StringBuilder();
        sb.Append("1");
        for (int I = 2; I <= N; I++) {
            sb.Append("0");
        }
        sb.Append("7");
        Console.WriteLine(sb.ToString());
    }
}