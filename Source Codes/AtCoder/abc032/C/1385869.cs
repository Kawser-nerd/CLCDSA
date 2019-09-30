using System;
using System.Collections;
using System.Linq;

public class MainApp
{
    static public int Main(string[] args)
    {
        var temp = Console.ReadLine().Split(' ');
        int N = int.Parse(temp[0]);
        long K = long.Parse(temp[1]);
        long[] s = new long[N];
        int one_check = 0;
        for (int c = 0; c < N; c++)
        {
            s[c] = long.Parse(Console.ReadLine());
            if (s[c] == 0) one_check = 1;
        }//????

        long product = s[0];
        int output = 0;
        int score = 1;
        int top = 0;
        int bottom = 0;
        if (one_check == 1)
        {
            Console.WriteLine(s.Length);
            return 0;
        }

        while(true)
        {
            if (top > N) break;
            if (product > K)
            {
                score--;
                if (score > 0)
                {
                    if (output < score) output = score;
                    product /= s[bottom];
                    bottom++;
                }
                else
                {
                    top++;
                    bottom = top;
                    if (top >= N) break;
                    product = s[top];

                }
                //??????????????
            }
            else
            {
                top++;
                if (top >= N)
                {
                    if (output < score) output = score;
                    break;
                }
                product *= s[top];
                score++;
                //???????????????
            }
                


        }

        Console.WriteLine(output);
        return 0;
    }

}