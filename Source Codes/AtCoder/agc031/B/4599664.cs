using System;
class Program
    {
    	static void Main(string[] args)
    	{
    		// ?????
    		int a = int.Parse(Console.ReadLine());
    		// ?????
            int[] arr = new int[a];
    		for (int i = 0; i < a; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
            }
    		//??
            int[] ans = new int[a];
            //colorIndex[i]---??????i?????
            int[] colorIndex = new int[200001];
            for (int i = 0; i <= 200000; i++)
            {
                colorIndex[i] = -1;
            }

            ans[a - 1] = 1;
            colorIndex[arr[a - 1]] = a - 1;
            for (int i = a - 2; i >= 0; i--)
            {
                if (colorIndex[arr[i]] == -1)
                {
                    colorIndex[arr[i]] = i;
                    ans[i] = ans[i + 1];
                    //Console.Error.WriteLine("+0");
                }
                else if (colorIndex[arr[i]] == i + 1)
                {
                    colorIndex[arr[i]] = i;
                    ans[i] = ans[i + 1];
                    //Console.Error.WriteLine("+0");
                }
                else
                {
                    ans[i] = (ans[i + 1] + ans[colorIndex[arr[i]]]) % 1000000007;
                    colorIndex[arr[i]] = i;
                    //Console.Error.WriteLine("+ans[]");
                }
                //Console.Error.WriteLine(colorIndex[2] + " " + colorIndex[4] + " " + colorIndex[5]);
                //Console.Error.WriteLine(ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3] + " " + ans[4] + " " + ans[5]);
                
                
            }
            Console.WriteLine(ans[0] % 1000000007);
        }
    }
    //mcs Main.cs
    //mono Main.exe