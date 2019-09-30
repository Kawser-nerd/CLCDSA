using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace Round1B
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream file = new FileStream("B-small-attempt0.in", FileMode.OpenOrCreate, FileAccess.Read);
            StreamReader sr = new StreamReader(file);

            FileStream file2 = new FileStream("out.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(file2);

            String tempStr;
            Int32 numProb;

            tempStr = sr.ReadLine();
            numProb = Int32.Parse(tempStr);

            for (int i = 1; i <= numProb; i++)
            {
                int ans = FindAnswer(sr);
                sw.WriteLine("Case #" + i + ": " + ans);
            }

            sw.Close();
            sr.Close();
            file.Close();
            file2.Close();
        }

        static int FindAnswer(StreamReader sr)
        {
            String tempStr;
            char[] seps = { ' ' };

            tempStr = sr.ReadLine();
            String[] sArr = tempStr.Split(seps);

            int A, B, P;
            A = Int32.Parse(sArr[0]);
            B = Int32.Parse(sArr[1]);
            P = Int32.Parse(sArr[2]);

            bool[] used = new bool[B+1];
            int[] primes = getPrimes(P, B);
            int count = 0;
            for(int i = A; i<=B; i++)
            {
                if(!used[i])
                {
                    used[i] = true;

                    ArrayList myAL = new ArrayList();
                    myAL.Add(i);
                    while(myAL.Count > 0)
                    {
                        int num = (Int32)myAL[0];
                        myAL.Remove(num);
                        for(int j = i+1; j<=B; j++)
                        {
                            if(!used[j] && sharePrime(primes, num, j))
                            {
                                used[j] = true;
                                myAL.Add(j);
                                count++;
                            }
                        }
                    }
                }
            }

            return B-A+1-count;
        }

        static bool sharePrime(int[] primes, int a, int b)
        {
            for(int i = 0; i<primes.Length; i++)
            {
                if(a%primes[i] == 0 && b%primes[i] == 0)
                    return true;
            }

            return false;
        }

        static int[] getPrimes(int p, int b)
        {
            int[] arr = {
      2,      3,      5,      7,     11,     13,     17,     19,     23,     29, 
     31,     37,     41,     43,     47,     53,     59,     61,     67,     71, 
     73,     79,     83,     89,     97,    101,    103,    107,    109,    113, 
    127,    131,    137,    139,    149,    151,    157,    163,    167,    173, 
    179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
    233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
    283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
    353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
    419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
    467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
    547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
    607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
    661,    673,    677,    683,    691,    701,    709,    719,    727,    733, 
    739,    743,    751,    757,    761,    769,    773,    787,    797,    809, 
    811,    821,    823,    827,    829,    839,    853,    857,    859,    863, 
    877,    881,    883,    887,    907,    911,    919,    929,    937,    941, 
    947,    953,    967,    971,    977,    983,    991,    997 };

            int count = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] >= p & arr[i] <= b)
                    count++;
            }

            int[] ret = new int[count];
            count = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] >= p & arr[i] <= b)
                {
                    ret[count] = arr[i];
                    count++;
                }
            }
            return ret;
        }
    }
}
