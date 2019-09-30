using System;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ??
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int A = int.Parse(input[1]);
        int B = int.Parse(input[2]);
        int C = int.Parse(input[3]);

        int ret = -1;
        List<int> bumboo = new List<int>();
        for (int i = 0; i < N; i++ )
        {
            int a = int.Parse(Console.ReadLine());
            bumboo.Add(a);
        }
    
        // ???????A/B/C/???? ????????
        int pow = (int)Math.Pow(4, N);
        //Console.WriteLine(pow);
        for (int i = 0; i < pow; i++ )
        {
            //bool isDone = false; // ABC???????
            List<int> abc = new List<int>() { A, B, C };
            int bumboo_choice = i;
            int mp = 0; // ??MP
            string str = "";
            //if (bumboo_choice == 937) Console.WriteLine(bumboo_choice);
            for(int j = 0; j<N; j++)
            {
                // j??????????
                str += bumboo_choice % 4 + " ";
                switch(bumboo_choice%4)
                {
                    case 0:
                        // ????
                        break;
                    case 1:
                        // A
                        if (abc[0] != A) mp += 10;
                        abc[0] -= bumboo[j];
                        break;
                    case 2:
                        // B
                        if (abc[1] != B) mp += 10;
                        abc[1] -= bumboo[j];
                        break;
                    case 3:
                        // C
                        if (abc[2] != C) mp += 10;
                        abc[2] -= bumboo[j];
                        break;
                }
                bumboo_choice /= 4;
            }

            if (abc[0] == A || abc[1] == B || abc[2] == C)
            {
                //Console.WriteLine(" false");
                continue;
            }

            mp += Math.Abs(abc[0]) + Math.Abs(abc[1]) + Math.Abs(abc[2]);

            

            if (ret == -1 || mp < ret)
            {
                //Console.WriteLine(str + mp + " abc:" + abc[0] + " " + abc[1] + " " + abc[2]);
                ret = mp;
            }
        }
        Console.WriteLine(ret);
    }

}