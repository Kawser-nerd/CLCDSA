using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder.Grand016
{
    public class AGC016B_ColorfulHats
    {
        public static void Main(string[] args)
        {

            // ?????
            int catNum = int.Parse( Console.ReadLine() );

            // ?????????????
            string[] hatNumText = Console.ReadLine().Split( ' ' );

            int[] hatNum = new int[catNum];
            for ( int i = 0; i < catNum; i++ )
            {
                hatNum[i] = int.Parse( hatNumText[i] );
            }


            Array.Sort( hatNum );
            
            int minHatTypeNum = hatNum[0];
            int maxHatTypeNum = hatNum[hatNum.Length - 1];

            int minCatCnt = hatNum.Count( val => val == minHatTypeNum);
            int maxCatCnt = hatNum.Count( val => val == maxHatTypeNum );
            

            string result = "Yes";

            // ???2???????????????
            if ( maxHatTypeNum - minHatTypeNum > 1 )
            {
                result = "No";
            }

            if ( minHatTypeNum == maxHatTypeNum )
            {
                // ??????
                // ???1?????????????

                // ???????(x!=N-1)?????????N/2?????????
                if ( minHatTypeNum != catNum - 1 && minHatTypeNum > catNum / 2  )
                {
                    result = "No";
                }

            }
            else
            {
                // x?x-1???
                // ?????????1?x-1??????????????
                // ????????x-?????????????????(x-???)*2??????

                // ???????????x-1?????1?x-1????????????
                if ( minCatCnt > minHatTypeNum )
                {
                    result = "No";
                }

                // ?????????????(x-???)*2???????????
                if ( maxCatCnt < (maxHatTypeNum - minCatCnt) * 2 )
                {
                    result = "No";
                }

            }
            
            // ????
            Console.WriteLine( result );
            
        }
        
    }
}