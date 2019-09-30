using System;
using System.Collections;
using System.IO;
public class G1 {



    public static void Main()
    {
       // G1 ___test = new G1();
        StreamReader SR;
        string S;
        SR = File.OpenText("A-large.in");
        S=SR.ReadLine();
        string[] a = S.Split();
        int L = int.Parse(a[0]);
        int D = int.Parse(a[1]);
        int N = int.Parse(a[2]);
      //  Console.WriteLine(L);
      //  Console.WriteLine(D);
      //  Console.WriteLine(N);
        string[] words = new string[D];
        for(int i=0;i<D;i++)
        {
            //Console.WriteLine(S);
            words[i]=SR.ReadLine();
       //     Console.WriteLine(words[i]);
        }

        StreamWriter SW;
        SW = File.CreateText("A-large.out");

        for (int i = 1; i <= N; i++)
        {
            S = SR.ReadLine();
            int res = 0;
            for (int j = 0; j < D; j++)
            {
                string T = words[j];

                int index = 0;
                bool good = true;
                for (int k = 0; k < L; k++)
                {
                    if (S[index] == '(')
                    {
                        int next = S.IndexOf(')', index)+1;
                        string tmp = S.Substring(index + 1, next - index - 2);
                        if(tmp.IndexOf(T[k])==-1)
                        {
                            good = false;
                            break;
                        }
                        index = next;
                    }
                    else{
                        if(S[index] != T[k])
                        {
                            good = false;
                            break;
                        }
                        index++;
                    }

                }

                if(good)
                    res++;

            }


            //Case #1: 2

            SW.WriteLine("Case #"+i+": "+res);
            Console.WriteLine("Case #" + i + ": " + res);
        }




        SR.Close();
        


        
       // SW.WriteLine("God is greatest of them all");
       // SW.WriteLine("This is second line");
        SW.Close();

     
    }
  
}