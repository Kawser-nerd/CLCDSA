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
            WillReturn.Add("1 4 5");
            WillReturn.Add("2 4 9");
            //18
            //????1?2???????????????????
            //1?1???????????????????????
            //???18???????????
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("6 6");
            WillReturn.Add("1 3 4 6 7 5");
            WillReturn.Add("1 2 4 8 8 7");
            WillReturn.Add("2 7 9 2 7 2");
            WillReturn.Add("9 4 2 7 6 5");
            WillReturn.Add("2 8 4 6 7 6");
            WillReturn.Add("3 7 9 1 2 7");
            //170
        }
        else {
            string wkStr;
            while ((wkStr = Console.ReadLine()) != null) WillReturn.Add(wkStr);
        }
        return WillReturn;
    }

    const int Hou = 1000000007;

    struct ValInfoDef
    {
        internal int X;
        internal int Y;
        internal int Val;
    }

    static void Main()
    {
        List<string> InputList = GetInputList();

        int[] wkArr = { };
        Action<string> SplitAct = pStr =>
            wkArr = pStr.Split(' ').Select(X => int.Parse(X)).ToArray();

        SplitAct(InputList[0]);
        int H = wkArr[0];
        int W = wkArr[1];
        int[,] AArr = new int[W, H];
        int UB_X = W - 1;
        int UB_Y = H - 1;

        var ValInfoList = new List<ValInfoDef>();
        for (int I = 1; I <= InputList.Count - 1; I++) {
            SplitAct(InputList[I]);
            for (int J = 0; J <= wkArr.GetUpperBound(0); J++) {
                ValInfoDef WillAdd;
                WillAdd.X = J;
                WillAdd.Y = I - 1;
                WillAdd.Val = wkArr[J];
                ValInfoList.Add(WillAdd);

                AArr[J, I - 1] = wkArr[J];
            }
        }

        int[,] CntArr = new int[W, H];
        for (int X = 0; X <= UB_X; X++) {
            for (int Y = 0; Y <= UB_Y; Y++) {
                CntArr[X, Y] = 1;
            }
        }

        ValInfoList.Sort((A, B) => A.Val.CompareTo(B.Val));
        foreach (ValInfoDef EachValInfo in ValInfoList) {

            int BaseX = EachValInfo.X;
            int BaseY = EachValInfo.Y;

            Action<int, int> AddAct = (pX, pY) =>
            {
                if (pX < 0 || UB_X < pX) return;
                if (pY < 0 || UB_Y < pY) return;

                if (AArr[pX, pY] <= AArr[BaseX, BaseY]) return;

                CntArr[pX, pY] += CntArr[BaseX, BaseY];
                CntArr[pX, pY] %= Hou;
            };

            AddAct(BaseX, BaseY - 1);
            AddAct(BaseX, BaseY + 1);
            AddAct(BaseX - 1, BaseY);
            AddAct(BaseX + 1, BaseY);
        }

        int Answer = 0;
        for (int X = 0; X <= UB_X; X++) {
            for (int Y = 0; Y <= UB_Y; Y++) {
                Answer += CntArr[X, Y];
                Answer %= Hou;
            }
        }
        Console.WriteLine(Answer);
    }
}