using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class A {
	int l, d;
	string[] dict, input;
	public A() {
		l=Program.l; d=Program.d;
		dict=Program.dict;
		string s=Console.ReadLine();
		List<string> pat=new List<string>();
		bool inside=false;
		string cur="";
		foreach (char c in s) {
			if (c=='(') {
				inside=true;
				cur="";
			} else if (c==')') {
				pat.Add(cur);
				inside=false;
			} else if (inside) {
				cur+=c;
			} else pat.Add(c.ToString());
		}
		input=pat.ToArray();
	}
	bool match(int fromLoc, int dictId) {
		for (int i=0; i<l; ++i) {
			bool found=false;
			for (int j=0; j<input[i+fromLoc].Length; ++j)
				if (input[i+fromLoc][j]==dict[dictId][i])
					found=true;
			if (!found) return false;
		}
		return true;
	}
	public string main() {
		int n=input.Length;
		int[] dp=new int[n+1];
		dp[0]=1;
		for (int i=0; i<=n-l; ++i)
			if (dp[i]>0)
		for (int j=0; j<d; ++j)
			if (match(i, j))
				dp[i+l]+=dp[i];
		return dp[n].ToString();
	}
}