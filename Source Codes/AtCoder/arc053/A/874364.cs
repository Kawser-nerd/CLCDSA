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
            //7
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("4 1");
            //3
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("1 1");
            //0
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

        int H = wkArr[0];
        int W = wkArr[1];

        int Answer = 0;

        //????
        if (H > 1) Answer += W * (H - 1);

        //????
        if (W > 1) Answer += H * (W - 1);

        Console.WriteLine(Answer);
    }
}