using System;
using System.Collections.Generic;
using System.Linq;

//AGC006-B-Median Pyramid Easy
//http://agc006.contest.atcoder.jp/tasks/agc006_b
class Program
{
    static string InputPattern = "InputX";

    static List<string> GetInputList()
    {
        var WillReturn = new List<string>();

        if (InputPattern == "Input1") {
            WillReturn.Add("4 4");
            //Yes
            //1
            //6
            //3
            //7
            //4
            //5
            //2
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("2 1");
            //No
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("3 2");
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
        int[] wkArr = InputList[0].Split(' ').Select(X => int.Parse(X)).ToArray();
        int N = wkArr[0];
        int x = wkArr[1];

        if (x == 1 || x == 2 * N - 1) {
            Console.WriteLine("No");
            return;
        }

        int[] TeihenArr = new int[2 * N - 1];
        int UB = TeihenArr.GetUpperBound(0);

        //?????
        int CenterInd = UB / 2;

        int UseNum = 1;
        var sb = new System.Text.StringBuilder();
        sb.AppendLine("Yes");
        for (int I = 0; I <= UB; I++) {
            if (I == CenterInd - 1) {
                sb.Append(x - 1); sb.AppendLine();
            }
            else if (I == CenterInd) {
                sb.Append(x); sb.AppendLine();
            }
            else if (I == CenterInd + 1) {
                sb.Append(x + 1); sb.AppendLine();
            }
            else {
                while (x - 1 <= UseNum && UseNum <= x + 1) UseNum++;
                sb.Append(UseNum++); sb.AppendLine();
            }
        }
        Console.WriteLine(sb.ToString());
    }
}