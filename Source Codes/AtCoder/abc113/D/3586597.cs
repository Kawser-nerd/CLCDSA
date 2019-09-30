using System;
using System.Linq;
using System.Collections.Generic;

class Dmondai
{
    static void Main()
    {
        const long Mod= 1000000007;
        var line=Console.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();
        var H = line[0];
        var W = line[1];
        var K = line[2];

        //????????????1
        if (W == 1) { Console.WriteLine(1); return; }

        //?????????????????
        var arrayH = new long[W-1];

        //?????
        //??????????????
        var bitList = new List<string>();
        for (int i=0;i<(1<<(W-1));++i)
        {
            //???????
            var value=Convert.ToString((i), 2);
            //???????0????
            var bit =value.PadLeft(W-1,'0');

            //???????????????????????????
            var isContinue = true;

            //??????????????????????
            for (int j=0;j<W-2;++j)
            {
                if (bit[j] == '1' && bit[j + 1] == '1')
                {
                    isContinue = false;
                    break;
                }
            }

            //???????????????????????
            if (isContinue)
            {
                bitList.Add(bit);
                for (int j=0;j<W-1;++j) if (bit[j] == '1') arrayH[j]++;
            }
        }

        //???????????????????????
        long bitCount = bitList.Count();

        //?????
        //??????????????????????????
        //????????????
        //????????
        //H????????????????0?H
        //W????????????????0?W-1
        var ansArray = new long[H+1,W];
        //?????
        for (int i=0;i<=H;++i)
        {
            //?????
            for (int j=0;j<W;++j)
            {
                if (i == 0)
                {
                    //0,0??????1
                    if (j == 0) ansArray[i, j] = 1;
                    else ansArray[i, j] = 0;
                }
                //??0???
                else if (j==0)
                {   
                    //??
                    var temp = (ansArray[i - 1, j] * (bitCount-arrayH[0])) % Mod;
                    //?
                    temp = (temp + (ansArray[i - 1, j + 1] * arrayH[0])) % Mod;
                    ansArray[i, j] = temp;

                }
                //??W-1?????????
                else if (j == W - 1)
                {
                    //??
                    var temp = (ansArray[i - 1, j] * (bitCount - arrayH[W-2])) % Mod;
                    //?
                    temp = (temp + (ansArray[i - 1, j - 1] * arrayH[W-2])) % Mod;
                    ansArray[i, j] = temp;
                }
                //????
                else
                {
                    //??
                    var temp = (ansArray[i - 1, j] * (bitCount - ( arrayH[j-1] + arrayH[j]) )) % Mod;
                    //?
                    temp = (temp + (ansArray[i - 1, j - 1] * arrayH[j - 1] )) % Mod;
                    //?
                    temp = (temp + (ansArray[i - 1, j + 1] * arrayH[j])) % Mod;
                    ansArray[i, j] = temp;
                }
            }
        }
        Console.WriteLine(ansArray[H,K-1]);

    }
}