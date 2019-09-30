using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class C {
	string pat="welcome to code jam", s;
	public C() {
		s=Console.ReadLine();
	}
	public string main() {
		int n=s.Length;
		int[] ans=new int[n];
		for (int i=0; i<n; ++i) if (s[i]==pat[0]) ans[i]=1;
		pat=pat.Substring(1);
		foreach (char c in pat) {
			int[] bak=ans;
			ans=new int[n];
			for (int i=0; i<n; ++i)
				if (s[i]==c)
					for (int j=0; j<i; ++j)
						ans[i]=(ans[i]+bak[j])%10000;
		}
		int res=0;
		for (int i=0; i<n; ++i) res=(res+ans[i])%10000;
		return string.Format("{0:D4}", res);
	}
}