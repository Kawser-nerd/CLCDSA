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
            WillReturn.Add("5 5");
            WillReturn.Add("3 4");
            //2
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("10 20");
            WillReturn.Add("2 2");
            //10
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("1 1");
            WillReturn.Add("2 2");
            //0
        }
        else if (InputPattern == "Input4") {
            WillReturn.Add("10000000000 10000000000");
            WillReturn.Add("4 3");
            //4545454545
        }
        else {
            string wkStr;
            while ((wkStr = Console.ReadLine()) != null) WillReturn.Add(wkStr);
        }
        return WillReturn;
    }

    static long mR;
    static long mB;
    static long mX;
    static long mY;

    static void Main()
    {
        List<string> InputList = GetInputList();

        long[] wkArr = { };
        Action<string> SplitAct = pStr =>
            wkArr = pStr.Split(' ').Select(A => long.Parse(A)).ToArray();

        SplitAct(InputList[0]);
        mR = wkArr[0]; mB = wkArr[1];

        SplitAct(InputList[1]);
        mX = wkArr[0]; mY = wkArr[1];

        Console.WriteLine(ExecNibunHou());
    }

    //2????????????????????
    static long ExecNibunHou()
    {
        long L = 0;
        long R = Math.Min(mR, mB) + 1;

        while (L + 1 < R) {
            long Mid = (L + R) / 2;

            bool CanCreate = DeriveCanCreate(Mid);
            if (CanCreate) L = Mid;
            else R = Mid;
        }
        return L;
    }

    //K????????????
    static bool DeriveCanCreate(long pK)
    {
        long RestR = mR, RestB = mB;

        //?????????????1???1??????
        RestR -= pK;
        RestB -= pK;

        long CanCreateCnt = 0;

        //??????????????
        CanCreateCnt += RestR / (mX - 1);

        //??????????????
        CanCreateCnt += RestB / (mY - 1);

        return pK <= CanCreateCnt;
    }
}