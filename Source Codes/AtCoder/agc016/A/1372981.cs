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
            WillReturn.Add("serval");
            //3
            //????serval ? srvvl ? svvv ? vvv ?????????
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("jackal");
            //2
            //????jackal ? aacaa ? aaaa ?????????
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("zzz");
            //0
            //????s????????????????
        }
        else if (InputPattern == "Input4") {
            WillReturn.Add("whbrjpjyhsrywlqjxdbrbaomnw");
            //8
            //8?????????s?rrrrrrrrrrrrrrrrrr???????????
        }
        else {
            string wkStr;
            while ((wkStr = Console.ReadLine()) != null) WillReturn.Add(wkStr);
        }
        return WillReturn;
    }

    static string ms;
    static void Main()
    {
        List<string> InputList = GetInputList();
        ms = InputList[0];

        //???????
        char[] KouhoArr = ms.Distinct().ToArray();

        int Answer = int.MaxValue;
        foreach (char EachKouho in KouhoArr) {
            int wkTesuu = DeriveTesuu(EachKouho);
            if (Answer > wkTesuu)
                Answer = wkTesuu;
        }
        Console.WriteLine(Answer);
    }

    //????????????????????
    static int DeriveTesuu(char pKouho)
    {
        int WillReturn = 0;
        string CurrStr = ms;

        while (true) {
            if (CurrStr.Distinct().Count() == 1) {
                return WillReturn;
            }

            var sb = new System.Text.StringBuilder();
            for (int I = 0; I <= CurrStr.Length - 2; I++) {
                if (CurrStr[I] == pKouho || CurrStr[I + 1] == pKouho) {
                    sb.Append(pKouho);
                }
                else sb.Append(CurrStr[I]);
            }
            WillReturn++;
            CurrStr = sb.ToString();
        }
    }
}