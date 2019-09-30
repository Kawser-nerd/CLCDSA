using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		long K = long.Parse(str);
		long kt = 0;
		double[] AN = new double[100001];
		long[] ANa = new long[100001];
		long a = 1;
		long ct = 1;
		long at = 1;
		while(ct<=100000){
			AN[ct] = a / (double)sn(a);
			ANa[ct] = a;
			a += at;
			ct += 1;
			if(a==9){
				at = 10;
			} else if(a==99){
				at = 100;
			} else if(a==9999){
				at = 1000;
			} else if(a==99999){
				at = 10000;
			} else if(a==999999){
				at = 100000;
			} else if(a==9999999){
				at = 1000000;
			} else if(a==99999999){
				at = 10000000;
			} else if(a==999999999){
				at = 100000000;
			} else if(a==9999999999){
				at = 1000000000;
			} else if(a==99999999999){
				at = 10000000000;
			} else if(a==999999999999){
				at = 100000000000;
			} else if(a==99999999999999){
				at = 1000000000000;
			}
		}
		for(var i=1;i<=100000;i++){
			bool flag = true;
			for(var j=i+1;j<=100000;j++){
				if(AN[j] < AN[i]){
					flag = false;
					break;
				}
			}
			if(flag){
				if(i>=0){
					Console.WriteLine(ANa[i]);
				}
				kt += 1;
			}
			if(kt >= K){
				break;
			}
		}
	}
	public static long sn(long x){
		long ans = 0;
		while(x > 0){
			ans += x % 10;
			x /= 10;
		}
		return ans;
	}
}