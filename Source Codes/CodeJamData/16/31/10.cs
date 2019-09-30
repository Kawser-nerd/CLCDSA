using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		
		N=ri();
		A=ria();
		
		List<String> L=new List<String>();
		
		bool chk=true;
		while(chk){
			chk=false;
			int idx0=-1;
			int max=0;
			for(int i=0;i<N;i++){
				if(A[i]>max){
					chk=true;
					max=A[i];
					idx0=i;
				}
			}
			if(!chk)break;
			String s="";
			if(idx0!=-1){
				s+=((char)('A'+idx0)).ToString();
				A[idx0]--;
			}
			
			int idx1=-1;
			max=0;
			for(int i=0;i<N;i++){
				if(A[i]>max){
					max=A[i];
					idx1=i;
				}
			}
			A[idx1]--;
			
			int idx2=-1;
			max=0;
			for(int i=0;i<N;i++){
				if(A[i]>max){
					max=A[i];
					idx2=i;
				}
			}
			int sum=A.Sum();
			if(max>sum/2){
				A[idx1]++;
			}else{
				s+=((char)('A'+idx1)).ToString();
			}
			L.Add(s);
		}
		
		
		Console.WriteLine(String.Join(" ",L.ToArray()));
		
		
		
		
	}
	
	int N;
	int[] A;
	
	
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
	}




	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}

}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}