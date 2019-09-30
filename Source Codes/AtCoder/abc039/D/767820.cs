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
            WillReturn.Add("4 4");
            WillReturn.Add("##..");
            WillReturn.Add("##..");
            WillReturn.Add("..##");
            WillReturn.Add("..##");
            //possible
            //#...
            //....
            //....
            //...#
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("4 4");
            WillReturn.Add("###.");
            WillReturn.Add("####");
            WillReturn.Add("..##");
            WillReturn.Add("..##");
            //possible
            //##..
            //....
            //...#
            //...#
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("4 4");
            WillReturn.Add("###.");
            WillReturn.Add("##.#");
            WillReturn.Add("..##");
            WillReturn.Add("..##");
            //impossible
        }
        else {
            string wkStr;
            while ((wkStr = Console.ReadLine()) != null) WillReturn.Add(wkStr);
        }
        return WillReturn;
    }

    static int UB_X;
    static int UB_Y;

    static void Main()
    {
        List<string> InputList = GetInputList();

        int[] wkArr = InputList[0].Split(' ').Select(X => int.Parse(X)).ToArray();
        int H = wkArr[0];
        int W = wkArr[1];
        char[,] InputBanArr = new char[W, H];
        UB_X = W - 1;
        UB_Y = H - 1;

        for (int Y = 1; Y <= InputList.Count - 1; Y++) {
            for (int X = 0; X <= InputList[Y].Length - 1; X++) {
                InputBanArr[X, Y - 1] = InputList[Y][X];
            }
        }
        //Console.WriteLine(BanToStr(BeforeBanArr));

        //????????
        //????8???????????????????????
        char[,] AnswerBanArr = new char[W, H];
        for (int X = 0; X <= UB_X; X++) {
            for (int Y = 0; Y <= UB_Y; Y++) {
                if (Is8KinbouAllBlack(InputBanArr, X, Y))
                    AnswerBanArr[X, Y] = '#';
                else AnswerBanArr[X, Y] = '.';
            }
        }

        //????????
        //???????????????????????????
        char[,] AfterBanArr = new char[W, H];
        for (int X = 0; X <= UB_X; X++) {
            for (int Y = 0; Y <= UB_Y; Y++) {
                if (Is8KinbouAnyBlack(AnswerBanArr, X, Y))
                    AfterBanArr[X, Y] = '#';
                else AfterBanArr[X, Y] = '.';
            }
        }

        if (InputBanArr.Cast<char>().SequenceEqual(AfterBanArr.Cast<char>())) {
            Console.WriteLine("possible");
            Console.Write(BanToStr(AnswerBanArr));
        }
        else Console.WriteLine("impossible");
    }

    //??????8???????????
    static bool Is8KinbouAllBlack(char[,] pBanArr, int pX, int pY)
    {
        Func<int, int, bool> wkFunc = (pTargetX, pTargetY) =>
        {
            if (pTargetX < 0 || UB_X < pTargetX) return true;
            if (pTargetY < 0 || UB_Y < pTargetY) return true;
            return pBanArr[pTargetX, pTargetY] == '#';
        };

        for (int HeniX = -1; HeniX <= 1; HeniX++)
            for (int HeniY = -1; HeniY <= 1; HeniY++)
                if (wkFunc(pX + HeniX, pY + HeniY) == false) return false;
        return true;
    }

    //??????8?????????1???????
    static bool Is8KinbouAnyBlack(char[,] pBanArr, int pX, int pY)
    {
        Func<int, int, bool> wkFunc = (pTargetX, pTargetY) =>
        {
            if (pTargetX < 0 || UB_X < pTargetX) return false;
            if (pTargetY < 0 || UB_Y < pTargetY) return false;
            return pBanArr[pTargetX, pTargetY] == '#';
        };

        for (int HeniX = -1; HeniX <= 1; HeniX++)
            for (int HeniY = -1; HeniY <= 1; HeniY++)
                if (wkFunc(pX + HeniX, pY + HeniY)) return true;
        return false;
    }

    static string BanToStr(char[,] pBanArr)
    {
        var sb = new System.Text.StringBuilder();
        for (int Y = 0; Y <= UB_Y; Y++) {
            for (int X = 0; X <= UB_X; X++) {
                sb.Append(pBanArr[X, Y]);
            }
            sb.AppendLine();
        }
        return sb.ToString();
    }
}