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


namespace B2
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

		
		double solve(int N,int X,int Y){
			X=Math.Abs(X);
			int curlevel=0,curcnt=1;
			while(N>=curcnt){
				curlevel++;
				N-=curcnt;
				curcnt+=4;
			}
			
			int tarlevel=(X+Y)/2;
			if(curlevel>tarlevel)return 1;
			if(curlevel<tarlevel)return 0;
			if(N==0)return 0;
			if(X==0)return 0;
			
		
			double[] prob={1};
			int limit=curcnt/2;
			for(int i=0;i<N;++i){				
				double[] nprob=new double[prob.Length+1];
				
				for(int j=0;j<prob.Length;++j){
					if(j<limit && i-j<limit){
						nprob[j]+=prob[j]/2;
						nprob[j+1]+=prob[j]/2;
						continue;
					}
					if(j==limit){
						nprob[j]+=prob[j];
						continue;
					}
					if(i-j==limit){
						nprob[j+1]+=prob[j];
					}
				}
				prob=nprob;
			}
			
			//cerr.WriteLine("curcnt={2} N={0} K={1}",N,Y+1,curcnt);
			
			double ret=0;
			for(int i=0;i<=Y;++i){
				if(i<prob.Length)
					ret+=prob[i];
			}
			
			return 1-ret;
		}
		
		double solvecase(int caseno){			
			int[] arr=cin.NextStringArray().ToIntArray();
			return solve(arr[0],arr[1],arr[2]);
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