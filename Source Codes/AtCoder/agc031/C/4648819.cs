using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int A = int.Parse(str[1]);
		int B = int.Parse(str[2]);
		int c = 1;
		int ct0 = 0;
		int ct1 = 0;
		int ct1i = -1;
		int[] LNa = new int[N];
		int[] LNb = new int[N];
		int[] D = new int[N];
		int[] ctL = new int[N];
		for(var i=0;i<N;i++){
			D[i] = c;
			int a1 = (A/c)%2;
			int b1 = (B/c)%2;
			LNa[i] = a1;
			LNb[i] = b1;
			if(Math.Abs(a1-b1)%2==1){
				ct1++;
				ctL[i]=1;
				ct1i = i;
			} else {
				ct0++;
			}
			c *= 2;
		}
		if(ct1%2==0){
			Console.WriteLine("NO");
		} else {
			Console.WriteLine("YES");
			List<int> ans = Ar(N,A,B);
			Console.Write(ans[0]);
			for(var i=1;i<ans.Count;i++){
				Console.Write(" "+ans[i]);
			}
		}
	}
	static List<int> Ar(int n,int a,int b){
		int L = (int)Math.Pow(2,n);		
		List<int> A = new List<int>();
		if(n==1){
			A.Add(a);
			A.Add(b);
		} else {
			int c = 1;
			for(var i=0;i<n;i++){
				int a1 = a/c%2;
				int b1 = b/c%2;
				if(a1!=b1){
					int a2 = a%c+a/(c*2)*c;
					int b2 = b%c+b/(c*2)*c;
					int a3 = a2/2*2+(a2%2+1)%2;
					A.AddRange(Ar(n-1,a2,a3));
					for(var j=0;j<L/2;j++){
						int a4 = A[j]/c;
						A[j] = a4*2*c+a1*c+A[j]%c;
					}
					A.AddRange(Ar(n-1,a3,b2));
					for(var j=L/2;j<L;j++){
						int a4 = A[j]/c;
						A[j] = a4*2*c+b1*c+A[j]%c;
					}
					break;
				} else {
					c *= 2;
				}
			}
		}
		return A;
	}
}