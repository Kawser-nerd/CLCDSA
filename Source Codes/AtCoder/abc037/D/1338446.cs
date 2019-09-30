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
    static int UB_X;
    static int UB_Y;
    static int[,] AArr;
    static Nullable<long>[,] MemoArr;

    static void Main()
    {
        List<string> InputList = GetInputList();

        int[] wkArr = { };
        Action<string> SplitAct = pStr =>
            wkArr = pStr.Split(' ').Select(X => int.Parse(X)).ToArray();

        SplitAct(InputList[0]);
        int H = wkArr[0];
        int W = wkArr[1];
        AArr = new int[W, H];
        MemoArr = new Nullable<long>[W, H];
        UB_X = AArr.GetUpperBound(0);
        UB_Y = AArr.GetUpperBound(1);

        for (int I = 1; I <= InputList.Count - 1; I++) {
            SplitAct(InputList[I]);
            for (int J = 0; J <= wkArr.GetUpperBound(0); J++) {
                AArr[J, I - 1] = wkArr[J];
            }
        }

        long Answer = 0;
        for (int X = 0; X <= UB_X; X++) {
            for (int Y = 0; Y <= UB_Y; Y++) {
                Answer += ExecDFS(X, Y);
                Answer %= Hou;
            }
        }
        Console.WriteLine(Answer);
    }

    //?????????
    static long ExecDFS(int pStaX, int pStaY)
    {
        //?????
        if (MemoArr[pStaX, pStaY].HasValue)
            return MemoArr[pStaX, pStaY].Value;

        long WillReturn = 1;

        Action<int, int> wkAct = (pNewStaX, pNewStaY) =>
        {
            if (pNewStaX < 0 || UB_X < pNewStaX) return;
            if (pNewStaY < 0 || UB_Y < pNewStaY) return;
            if (AArr[pStaX, pStaY] < AArr[pNewStaX, pNewStaY]) {
                WillReturn += ExecDFS(pNewStaX, pNewStaY);
                WillReturn %= Hou;
            }
        };
        wkAct(pStaX, pStaY - 1);
        wkAct(pStaX, pStaY + 1);
        wkAct(pStaX - 1, pStaY);
        wkAct(pStaX + 1, pStaY);

        MemoArr[pStaX, pStaY] = WillReturn % Hou;
        return MemoArr[pStaX, pStaY].Value;
    }
}