using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Myst_Sq_cs
{
	class Program
	{
		static void Main(string[] args)
		{
			//ifstream be("D-small-attempt1.in");
			var be = new System.IO.StreamReader("D-small-attempt2.in");
			//ofstream ki("ki.txt");
			var ki=new System.IO.StreamWriter("ki.txt");
			int T;
			//be>>T;
			T=Int32.Parse(be.ReadLine());
			//FOR(tt,T){
			for(int tt=0; tt<T; tt++){
				string s;
				//be>>s;
				s=be.ReadLine();
				ulong x=0;
				ulong pow=1;
				var qm = new List<int>();
				for(int i=s.Length-1; i>=0; i--){
					if(s[i]=='1')
						x+=pow;
					else
						if(s[i]=='?')
							qm.Add(s.Length-i-1);
					pow<<=1;
				}
				ulong ex=x;
				int mego=-1;
				int megoc = 0;
				for(int bm=0; bm< (1<<qm.Count); bm++){
					x=ex;
					//FOR(i,SZ(qm))
					for(int i=0; i<qm.Count; i++)
						if((bm & (1<<i)) != 0)
							x+= ((ulong)1)<<qm[i];
					/*double sq=sqrt((double)x);
					if(sq==floor(sq)){*/
					decimal sq=(decimal)Math.Sqrt((double)x);
					bool ok=false;
					for(decimal j=Math.Floor(sq-1); j<=Math.Floor(sq+1); j++)
						if(j*j==x){
							ok=true;
							break;
						}
					//if(sq==floor(sq)){
					if(ok){
						mego=bm;
						//break;
						megoc++;
					}
				}
				if (megoc != 1)
					throw new Exception("nem jó a megoldásszám");
				//FOR(i,SZ(qm))
				char[] kis=new char[s.Length];
				for (int i = 0; i < s.Length; i++)
					kis[i] = s[i];
				for(int i=0; i<qm.Count; i++)
					if(0!= (mego & (1<<i)))
						kis[s.Length-qm[i]-1]='1';
					else
						kis[s.Length-qm[i]-1]='0';
				//ki<<"Case #"<<tt+1<<": "<<s<<endl;
				string ski="";
				for(int i=0; i<s.Length; i++)
					ski+=kis[i];
				ki.WriteLine("Case #" + (tt + 1).ToString() + ": " + ski);
				ki.Flush();
			}
	

			//ki.close();
			ki.Close();
			//return 0;
		}
	}
}
