using System;
class Program
    {
    	static void Main(string[] args)
    	{
    		// ?????
    		int a = int.Parse(Console.ReadLine());
    		// ?????
            string[] s = new string[a];
    		for (int i = 0; i < a; i++)
            {
                s[i] = Console.ReadLine();
            }
    		//??
            int ans = 0;
            for (int i = 0; i < a; i++)
            {
                bool goodPattern = true;
                for (int j = 0; j < a; j++)
                {
                    for (int k = 0; k < a; k++)
                    {
                        if (s[(j + i) % a][k] != s[(k + i) % a][j])
                        {
                            goodPattern = false;
                            break;
                        }
                    }
                    if (goodPattern == false) break;
                }
                if (goodPattern) ans += a;
            }
            Console.WriteLine(ans);
        }
    }
    //mcs Main.cs
    //mono Main.exe