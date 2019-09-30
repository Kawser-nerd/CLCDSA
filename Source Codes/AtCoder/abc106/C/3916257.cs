using System;

namespace ABC106C
{
    class MainClass
    {
        public static void Main(string[] args)
        {

            // N M ??????
            string Sinput = Console.ReadLine();
            char[] S = Sinput.ToCharArray();

            // N M ??????
            string input2 = Console.ReadLine();
            long K = long.Parse(input2);


            char ans = '1';
            //ans
            for(int i = 0; i < K; i++)
            {
                if(S[i] != '1')
                {
                    ans = S[i];
                    break;
                }
            }



            //??
            Console.WriteLine(ans);
        }
    }
}