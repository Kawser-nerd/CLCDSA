using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		int N = int.Parse(str);
		int [] S = new int[N];
		S[0] = 2;
		int t = 1;
		for(var i=19;i<=55555;i+=10){
			if(IsPrime(i)){
				S[t] = i;
				t += 1;
				if(t >= N){
					break;
				}
			}
		}
		string a = S[0].ToString();
		for(var i=1;i<N;i++){
			a += " " + S[i];
		}
		Console.WriteLine(a);
	}
	
public static bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = Math.Sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
}