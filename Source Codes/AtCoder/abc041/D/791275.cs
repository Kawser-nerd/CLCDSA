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
            WillReturn.Add("3 2");
            WillReturn.Add("2 1");
            WillReturn.Add("2 3");
            //2
        }
        else if (InputPattern == "Input2") {
            WillReturn.Add("5 5");
            WillReturn.Add("1 2");
            WillReturn.Add("2 3");
            WillReturn.Add("3 5");
            WillReturn.Add("1 4");
            WillReturn.Add("4 5");
            //3
        }
        else if (InputPattern == "Input3") {
            WillReturn.Add("16 1");
            WillReturn.Add("1 2");
            //10461394944000
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

        int[] wkArr = { };
        Action<string> SplitAct = pStr =>
            wkArr = pStr.Split(' ').Select(X => int.Parse(X)).ToArray();

        SplitAct(InputList[0]);
        int N = wkArr[0];

        var SenkouListDict = new Dictionary<int, List<int>>();
        foreach (string EachStr in InputList.Skip(1)) {
            SplitAct(EachStr);
            int SakiUsagi = wkArr[0];
            int AtoUsagi = wkArr[1];

            if (SenkouListDict.ContainsKey(AtoUsagi) == false) {
                SenkouListDict.Add(AtoUsagi, new List<int>());
            }
            SenkouListDict[AtoUsagi].Add(SakiUsagi);
        }

        //????[????????Bit??]?DP?
        int UB = (2 << (N - 1)) - 1;
        long[] PrevDP = new long[UB + 1];
        PrevDP[0] = 1;

        for (int I = 1; I <= N; I++) {
            long[] CurrDP = new long[UB + 1];
            for (int J = 0; J <= UB; J++) {
                //?????0???
                if (PrevDP[J] == 0) continue;

                for (int K = 1; K <= N; K++) {
                    //?????????Continue
                    if ((J & DeriveBitPos(K)) > 0)
                        continue;

                    //????????????????????????Continue
                    if (SenkouListDict.ContainsKey(K)) {
                        List<int> SenkouList = SenkouListDict[K];
                        if (SenkouList.Exists(A => (J & DeriveBitPos(A)) == 0)) {
                            continue;
                        }
                    }

                    int NewJ = (J | DeriveBitPos(K));
                    CurrDP[NewJ] += PrevDP[J];
                }
            }
            PrevDP = CurrDP;
        }
        Console.WriteLine(PrevDP[UB]);
    }

    //????????????????????????
    static int DeriveBitPos(int pUsagiNo)
    {
        return 1 << (pUsagiNo - 1);
    }
}