using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace km.gcj.gcj2013.qual
{
    class Program_A
    {
        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args)
        {
            //throw new NotImplementedException();
            Problem p = Problem.createProblem(args);
            if (p == null) {
                return;
            }

            // 事前計算を実行
            preCalc(50);
            Console.WriteLine(preCalcList.Count-1);

            // 試行回数を取得し、ループする。
            long repeat = p.getNextLineAsInt64Array()[0];
            for (int i = 0; i < repeat; i++)
            {

                // MainLoop
                String[] nm = p.getNextStrs().ToArray();
                BigInteger start;
                BigInteger end;
                if (!BigInteger.TryParse(nm[0],out start))
                {
                    throw new Exception();
                }
                if (!BigInteger.TryParse(nm[1], out end))
                {
                    throw new Exception();
                }

                int cnt = 0;
                foreach (var item in preCalcList)
                {
                    if (start <= item && item <= end)
                    {
                        cnt++;   
                    }
                }
                // ＼(・ω・＼)　　(／・ω・)／
                p.WriteAnswerFullLine(cnt.ToString());
            }
         }
        private static void preCalc(int maxOrder)
        {
            // 事前計算用のリストを初期化
            preCalcList = new List<BigInteger>(50000);
            preCalcList.Add(1*1);
            preCalcList.Add(2*2);
            preCalcList.Add(3*3);
            preCalcList.Add(11*11);
            preCalcList.Add(22*22);

            // 計算元の数値リストを初期化
            baseNumbersOdd     = new List<String>(50000);
            baseNumbersEven    = new List<String>(50000);
            baseNumbersOdd.Add("0");
            baseNumbersOdd.Add("1");
            baseNumbersOdd.Add("2");
            baseNumbersOdd.Add("3");
            baseNumbersEven.Add("00");
            baseNumbersEven.Add("11");
            baseNumbersEven.Add("22");

            for (int order = 3; order <= maxOrder; order++)
            {
                Console.WriteLine(order);
                if (order % 2 == 1)
                {
                    preCalcSub(baseNumbersOdd, order);
                }
                else
                {
                    preCalcSub(baseNumbersEven, order);
                }
                
            }
        }

        private static void preCalcSub(List<String> baseNumbers,int order){
            var preCalcList2 = new List<BigInteger>();
            var baseNumbers2 = new List<String>();
            foreach (String baseNum in new List<String>(baseNumbers))
            {
                String resultNum = baseNum;
                // 追加する桁数
                int addOrder = (order - baseNum.Length) / 2 - 1;
                for (int i = 0; i < addOrder; i++)
                {
                    resultNum = "0" + resultNum + "0";
                }
                BigInteger bi1 = check平方回文数("1" + resultNum + "1");
                if (bi1 > 0)
                {
                    preCalcList.Add(bi1);
                    baseNumbers.Add("1" + resultNum + "1");
                }
                BigInteger bi2 = check平方回文数("2" + resultNum + "2");
                if (bi2 > 0)
                {
                    preCalcList2.Add(bi2);
                    baseNumbers2.Add("2" + resultNum + "2");
                }
            }
            preCalcList.AddRange(preCalcList2);
            baseNumbers.AddRange(baseNumbers2);
            return;
        }

        /// <summary>
        /// 数字文字列に対し、平方数が回文数であるかをチェックする。
        /// </summary>
        /// <param name="num"></param>
        /// <returns></returns>
        private static BigInteger check平方回文数(String num)
        {
            BigInteger bi;
            if(!BigInteger.TryParse(num,out bi)){
                throw new Exception();
            }
            bi = bi * bi;
            String numRev = new String(bi.ToString().Reverse().ToArray());
//            Console.WriteLine("{0},{1}", bi.ToString(), numRev);
            if (bi.ToString() == numRev)
            {
                return bi;
            }
            else
            {
                return -1;
            }
        }

        /// <summary>
        /// 事前計算用のリスト
        /// </summary>
        private static List<BigInteger> preCalcList;

        /// <summary>
        /// 事前計算用のサブリスト（奇数）
        /// </summary>
        private static List<String> baseNumbersOdd;
        /// <summary>
        /// 事前計算用のサブリスト（偶数）
        /// </summary>
        private static List<String> baseNumbersEven;

    }
}
