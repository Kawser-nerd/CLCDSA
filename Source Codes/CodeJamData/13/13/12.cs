/*
 * Created by SharpDevelop.
 * User: cheapwine
 * Date: 2013/4/27
 * Time: 8:45
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.IO;
using System.Collections.Generic;

	
namespace A3
{

	static class Tool{
		public static string[] NextStringArray(this TextReader cin){
			return cin.ReadLine().Trim().Split(new char[]{},StringSplitOptions.RemoveEmptyEntries);
		}
		public static int[] ToIntArray(this string[] strarr){
			int[] ret=new int[strarr.Length];
			for(int i=0;i<strarr.Length;++i)
				ret[i]=int.Parse(strarr[i]);
			return ret;
		}
	}

	class Program
	{
		
		Random rand=new Random();
		
		void solve(int N,int M,int[] data){
			List<int> ret=new List<int>();
			if(N==3){
				for(int a=2;a<=M;++a)
					for(int b=2;b<=M;++b)
						for(int c=2;c<=M;++c){
					
					int[] pos={1,a,b,c,a*b,a*c,b*c,a*b*c};
					
					bool ok=true;
					foreach(int v in data){
						if(Array.IndexOf(pos,v)==-1){
							ok=false;
							break;
						}
					}
					if(ok){
						ret.Add(a*100+b*10+c);
					}						
				}
				if(ret.Count>0){
					cout.WriteLine(ret[rand.Next()%ret.Count]);				
				}else{
					cout.WriteLine("222");
				}
				return;	
			}
		}
		
		string solvecase(int casenumber){
			cout.WriteLine();
			
			int[] ia=cin.NextStringArray().ToIntArray();
			int R=ia[0],N=ia[1],M=ia[2],K=ia[3];
			for(int i=0;i<R;++i){
				int[] d=cin.NextStringArray().ToIntArray();
				solve(N,M,d);
			}
						
			return "";			
		}
		
		void solve(){
			cases=int.Parse(cin.ReadLine());
			for(int i=1;i<=cases;++i){
				cout.Write("Case #{0}: ",i);				
				object ret=solvecase(i);
				cout.WriteLine(ret);
			}
		}
		int cases;
		TextReader cin;
		TextWriter cout,cerr;
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