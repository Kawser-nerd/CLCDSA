using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace B
{
    class ProgramB
    {
        // Since I've spoiled by accident large test - only dumb solution
        static void Main(string[] args)
        {
            StreamReader re = File.OpenText("input.txt");
            FileInfo t = new FileInfo("output.txt");
            StreamWriter Tex = t.CreateText();

            int CAS = int.Parse(re.ReadLine());
            for (int cs = 0; cs < CAS; cs++)
            {
                // Turnaround time                
                // Read the longegers n, A, B, C, D, x0, y0 and M separated by exactly one space
                string line = re.ReadLine();

                
                int N = line.Length;
                long[] digits = new long[N];

                for (int i = 0; i < N; i++) digits[i] = int.Parse(line.Substring(i,1));

                long count = 0;
                // is the number of expressions that evaluate to an ugly number

                

                long[] numbers = new long[N];
                Console.WriteLine(line);
                
                for (long glue = 0; glue < 1 << (N - 1); glue++)
                {
                    int num = 0;
                    numbers[0] = digits[0];
                    for (int i = 1; i < N; i++)
                    {
                        if (((glue >> (i - 1)) & 1) == 1)
                            numbers[num] = numbers[num] * 10 + digits[i];
                        else
                        {
                            num++;
                            numbers[num] = digits[i];
                        }
                    }
                    // here wi have numubers of length num + 1
                    // two options for each gap (+ or -)
                    for (long plus = 0; plus < 1 << (num ); plus++)
                    {
                        long result = numbers[0];
                        for (int i = 1; i <= num; i++)
                        {

                            if (((plus >> (i - 1))& 1 ) == 1)
                            {
                                result += numbers[i];
                            }
                            else
                            {
                                result -= numbers[i];
                            }
                        }
                        //Test and count
                        if (result < 0) result = -result;
                        if ((result == 0) ||
                           (result % 2 == 0) ||
                            (result % 3 == 0) ||
                        (result % 5 == 0) ||
                        (result % 7 == 0)
                            )
                        {
                            count++;
                        }

                    }
                }


                    Tex.WriteLine("Case #{0}: {1}", cs + 1, count);
            }

            re.Close();
            Tex.Close();
        }
    }
}
