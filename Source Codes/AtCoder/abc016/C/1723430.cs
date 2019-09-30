using System;
using System.Collections.Generic;
using System.Linq;

//ABC016-C ????????????
class Program
{
    static string InputPattern = "Input";

    static List<string> GetInputList()
    {
        var WillReturn = new List<string>();

        if (InputPattern == "Input1") {
            WillReturn.Add("3 2");
            WillReturn.Add("1 2");
            WillReturn.Add("2 3");
            //1
            //0
            //1
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("3 3");
            WillReturn.Add("1 2");
            WillReturn.Add("1 3");
            WillReturn.Add("2 3");
            //0
            //0
            //0
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("8 12");
            WillReturn.Add("1 6");
            WillReturn.Add("1 7");
            WillReturn.Add("1 8");
            WillReturn.Add("2 5");
            WillReturn.Add("2 6");
            WillReturn.Add("3 5");
            WillReturn.Add("3 6");
            WillReturn.Add("4 5");
            WillReturn.Add("4 8");
            WillReturn.Add("5 6");
            WillReturn.Add("5 7");
            WillReturn.Add("7 8");
            //4
            //4
            //4
            //5
            //2
            //3
            //4
            //2
        }
        else {
            string wkStr;
            while ((wkStr = Console.ReadLine()) != null) WillReturn.Add(wkStr);
        }
        return WillReturn;
    }

    struct ABPairInfoDef
    {
        internal int A;
        internal int B;
    }

    static void Main()
    {
        List<string> InputList = GetInputList();

        int[] wkArr = { };
        Action<string> SplitAct = pStr =>
            wkArr = pStr.Split(' ').Select(X => int.Parse(X)).ToArray();

        SplitAct(InputList[0]);
        int N = wkArr[0];

        var ABPairList  =new List<ABPairInfoDef>();
        foreach (string EachStr in InputList.Skip(1)) {
            SplitAct(EachStr);
            ABPairInfoDef WillAdd;
            WillAdd.A = wkArr[0];
            WillAdd.B = wkArr[1];
            ABPairList.Add(WillAdd);
        }

        //??????????
        int[,] CostArr = new int[N + 1, N + 1];

        for (int I = 1; I <= N; I++) {
            for (int J = 1; J <= N; J++) {
                if (I == J) CostArr[I, J] = 0;
                else CostArr[I, J] = int.MaxValue / 2;
            }
        }

        foreach (ABPairInfoDef EachABPair in ABPairList) {
            CostArr[EachABPair.A, EachABPair.B] = 1;
            CostArr[EachABPair.B, EachABPair.A] = 1;
        }

        for (int K = 1; K <= N; K++) {
            for (int I = 1; I <= N; I++) {
                for (int J = 1; J <= N; J++) {
                    int Cost1 = CostArr[I, J];
                    int Cost2 = CostArr[I, K];
                    int Cost3 = CostArr[K, J];

                    if (Cost1 > Cost2 + Cost3)
                        CostArr[I, J] = Cost2 + Cost3;
                }
            }
        }

        for (int I = 1; I <= N; I++) {
            int Cost2Cnt = 0;
            for (int J = 1; J <= N; J++) {
                if (CostArr[I, J] == 2) Cost2Cnt++;
            }
            Console.WriteLine(Cost2Cnt);
        }
    }
}