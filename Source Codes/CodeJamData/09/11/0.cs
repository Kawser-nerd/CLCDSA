using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class A {
	int[] b;
	public A() {
		string[] s=Console.ReadLine().Split();
		b=new int[s.Length];
		for (int i=0; i<s.Length; ++i) b[i]=int.Parse(s[i]);
	}
	int next(int n, int b) {
		int ans=0;
		while (n>0) {
			ans+=(n%b)*(n%b);
			n/=b;
		}
		return ans;
	}
	bool check(int n, int b) {
		HashSet<int> h=new HashSet<int>();
		while (!h.Contains(n)) {
			h.Add(n);
			n=next(n,b);
		}
		return n==1;
	}
	public string main() {
		int n=1;
		while (true) {
			++n;
			bool valid=true;
			for (int i=0; i<b.Length&&valid; ++i)
				valid=check(n,b[i]);
			if (valid) return n.ToString();
		}
	}
}