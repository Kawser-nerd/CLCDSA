/*
 * Created by SharpDevelop.
 * User: cheapwine
 * Date: 2013/5/4
 * Time: 23:58
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.IO;
using System.Collections.Generic;


namespace B1
{
	static class Tool{
		public static string[] NextStringArray(this TextReader cin){
			string str=cin.ReadLine();
			//Console.Error.WriteLine(str);
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
	
	class Program
	{
		
		int solve(int v,int[] a){
			if(v==1)return a.Length;
			int ret=a.Length;
			
			int pos=0,basea=0;
			
			while(pos<a.Length){
			
				while(pos<a.Length && v>a[pos]){
					v+=a[pos];
					++pos;
				}
				int reta=a.Length-pos+basea;
				if(reta<ret)ret=reta;
				
				v=v*2-1;
				basea++;
			}
			
			return ret;
		}
		
		int solvecase(int caseno){			
			int[] arr=cin.NextStringArray().ToIntArray();
			int A=arr[0],N=arr[1];
			int[] data=cin.NextStringArray().ToIntArray();
			Array.Sort(data);
			return solve(A,data);
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
			bool UseCin=false;
			string InputFileName;
			if(args.Length==0){
				InputFileName="../../in.txt";
			}else{
				InputFileName=args[0];
			}
			try{
				new Program().solve(UseCin ? Console.In : new StreamReader(InputFileName));
			}catch(Exception ex){
				Console.WriteLine(ex.StackTrace);
				Console.Read();
			}		
		}
	}
}