using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Equal_Sum
{
    class program
    {
        public static int[] Transfer(int num)
        {
            int[] bin =  new int[20];
            int wei = 0;
            while (num != 0)
            {
                int mod = num % 2;
                bin[wei] = mod;
                num = num / 2;
                wei++;
            }
            return bin;
        }

        public static void Main()
        {
            //string[] lines = funcs.getInputDocs(@"C.txt");
            string[] lines = funcs.getInputDocs(@"C-small-attempt0.in");
            //string[] lines = funcs.getInputDocs(@"A-large.in");
            int size = int.Parse(lines[0]);
            //int size = 20;
            List<string> newlines = new List<string>();

            for (int i = 0; i < size; i++)
            {
                
                string thisline = lines[i + 1];
                string[] words = thisline.Split();

                int N = int.Parse(words[0]);
                List<int> numbers = new List<int>();
                for (int j = 0; j < N; j++)
                    numbers.Add(int.Parse(words[j + 1]));
                
                int result = 0;
                newlines.Add("Case #" + (i + 1).ToString() + ":");

                for (int j = 0; j < 1048576; j++)
                {
                    int[] H2B = Transfer(j);
                    
                    int num = 0;
                    for (int k = 0; k < 20; k++)                                        
                        num = num + H2B[k];

                    int maximum = (int)Math.Pow(2, num) - 1;
                    for (int nn = 0; nn < maximum; nn++)
                    {
                        int[] HH = Transfer(nn);
                        int ct = 0, ct1 = 0, ct2 = 0;
                        int sum1 = 0, sum2 = 0;
                        List<int> set1 = new List<int>();
                        List<int> set2 = new List<int>();
                        for (int k = 0; k < 20; k++)
                        {
                            if ((H2B[k] == 1) && (HH[ct] == 0))
                            {
                                sum1 = sum1 + numbers[k];
                                ct++; ct1++; set1.Add(k);
                            }
                            else
                            {
                                if ((H2B[k] == 1) && (HH[ct] == 1))
                                {
                                    sum2 = sum2 + numbers[k];
                                    ct++; ct2++; set2.Add(k);
                                }
                            }
                        }
                        if ((ct1 != 0) && (ct2 != 0) && (sum1 == sum2))
                        {                            
                            result++;
                            string answer = "";
                            for (int k = 0; k < set1.Count; k++)
                            {
                                if (k != 0) answer = answer + " ";
                                answer = answer + numbers[set1[k]];
                            }
                            newlines.Add(answer);

                            answer = "";
                            for (int k = 0; k < set2.Count; k++)
                            {
                                if (k != 0) answer = answer + " ";
                                answer = answer + numbers[set2[k]];
                            }
                            newlines.Add(answer);
                            break;
                        }                            
                    }
                    if (result != 0)
                        break;
                }
                Console.WriteLine("Time " + i);
                Console.WriteLine("Result " + result);
            }
            funcs.WriteLines(@"C-small-attempt0.out", newlines);
        }
    }
}
