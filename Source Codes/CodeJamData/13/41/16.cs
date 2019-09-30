/*
 * Created by SharpDevelop.
 * User: cheapwine
 * Date: 2013/5/4
 * Time: 23:59
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.IO;
using System.Collections.Generic;



	static class Tool{
		public static string[] NextStringArray(this TextReader cin){
			string str=cin.ReadLine();
			return str.Trim().Split(new char[]{},StringSplitOptions.RemoveEmptyEntries);
		}
		public static int[] ToIntArray(this string[] strarr){
			int[] ret=new int[strarr.Length];
			for(int i=0;i<strarr.Length;++i)
				ret[i]=int.Parse(strarr[i]);
			return ret;
		}
		public static long[] ToLongArray(this string[] strarr){
			long[] ret=new long[strarr.Length];
			for(int i=0;i<strarr.Length;++i)
				ret[i]=long.Parse(strarr[i]);
			return ret;
		}

	}
	
	
struct T:IComparable<T>{
	public int o,e,p;
	public int CompareTo(T r){
		if(o!=r.o)return o-r.o;
		if(e!=r.e)return e-r.e;
		return p-r.p;
	}
}

struct Qu{
	public int pos;
	public long delta;
	public Qu(int pos,long delta){
		this.pos=pos;
		this.delta=delta;
	}
}

	class Program
	{
		const int MODU=1000002013;
		
		object solvecase(int caseno){
			object ret=null;
			int[] v=cin.NextStringArray().ToIntArray();
			int N=v[0],M=v[1];
			T[] t=new T[M];
			for(int i=0;i<M;++i){
				v=cin.NextStringArray().ToIntArray();
				t[i].o=v[0];
				t[i].e=v[1];
				t[i].p=v[2];
			}
			Array.Sort(t);
			
			SortedDictionary<int,long> a=new SortedDictionary<int, long>();
			
			long origcost=0;
			
			for(int i=0;i<M;++i){
				if(!a.ContainsKey(t[i].o))a.Add(t[i].o,0);
				if(!a.ContainsKey(t[i].e))a.Add(t[i].e,0);
				
				a[t[i].o]+=t[i].p;
				a[t[i].e]-=t[i].p;
				
				long dist=t[i].e-t[i].o;
				long cost=cost=dist*(N+N-dist+1)/2;
				origcost+=cost%MODU*t[i].p;
				origcost%=MODU;
			}
			
			int lastpos=-1;
			long totalcost=0;
			List<Qu> lst=new List<Qu>();
			foreach(var va in a){
				int pos=va.Key;
				long delta=va.Value;
				
				if(delta>0){
					lst.Add(new Qu(pos,delta));
				}
				
				while(delta<0){
					int pp=lst[lst.Count-1].pos;
					long dd=lst[lst.Count-1].delta;
					long amount=Math.Min(dd,-delta);
					
					long dist=pos-pp;
					long cost=dist*(N+N-dist+1)/2;
					totalcost+=cost%MODU*(amount%MODU);
					totalcost%=MODU;
					
					if(amount==dd){
						lst.RemoveAt(lst.Count-1);						
					}else{
						lst[lst.Count-1]=new Qu(pp,dd-amount);
					}
					delta+=amount;
				}
				
				lastpos=pos;
			}
			
			
			long diff=origcost-totalcost;
			if(diff<0)diff+=MODU;
			
			
			return diff%MODU;
		}
		
		void solve(){
			cases=int.Parse(cin.ReadLine());
			for(int i=1;i<=cases;++i){
				cout.Write("Case #{0}: ",i);				
				cout.WriteLine(solvecase(i));
			}
		}
		
		int cases;
		TextReader cin;
		TextWriter cout,cerr;
		Random rand=new Random();
		void solve(TextReader cin){
			this.cin=cin;
			this.cout=Console.Out;
			this.cerr=Console.Error;
			solve();
		}
		public static void Main(string[] args)
		{
			
			string InputFileName;
			if(args.Length==0){
				InputFileName="../../in.txt";
			}else{
				InputFileName=args[0];
			}
			
				new Program().solve(!File.Exists(InputFileName) ? 
				                    Console.In : new StreamReader(InputFileName));

		}
	}