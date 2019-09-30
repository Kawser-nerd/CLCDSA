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
		
		var d=ria();
		R=d[0];C=d[1];N=d[2];
		dx=new int[]{0,1,0,-1};
		dy=new int[]{1,0,-1,0};
		
		
		int min=99999999;
		for(int s=0;s<(1<<R*C);s++){
			if(bitCnt(s)!=N)continue;
			min=Math.Min(min,chk(s));
		}
		
		Console.WriteLine(min);
		
	}
	int N,R,C;
	
	int bitCnt(int x){
		int ret=0;
		for(int i=0;i<20;i++){
			ret+=((x>>i)&1);
		}
		return ret;
	}
	int[] dx,dy;
	
	int chk(int s){
		int[][] Map=new int[R][];
		for(int i=0;i<R;i++)Map[i]=new int[C];
		for(int i=0;i<R*C;i++){
			if(((s>>i)&1)>0)Map[i/C][i%C]=1;
		}
		int cnt=0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(Map[i][j]==0)continue;
				for(int k=0;k<4;k++){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(nx>=C||nx<0||ny>=R||ny<0)continue;
					if(Map[ny][nx]==1)cnt++;
				}
			
			}
		}
		return cnt/2;
	}
	

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