using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		var UF = new UnionFind(H*W);
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(S[i][j] == '.') continue;
				for(int dy=-1;dy<=1;dy++){
					if(!InRange(i+dy,0,H)) continue;
					for(int dx=-1;dx<=1;dx++){
						if(!InRange(j+dx,0,W)) continue;
						if(S[i+dy][j+dx] == 'o') UF.Unite(i*W+j,(i+dy)*W+(j+dx));
					}
				}
			}
		}
		
		int[] ans = new int[3];
		var dic = new Dictionary<int,int>(){
			{12,0}, {16,1}, {11,2}
		};
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(S[i][j] == 'o' && UF.IsRoot(i*W+j)){
					int vol = UF.MemCnt(i*W+j);
					//Console.WriteLine(vol);
					for(int r=1;r*r<vol;r++){
						if(vol % (r*r) == 0 && vol / (r*r) != 0){
							if(dic.ContainsKey(vol / (r*r))) ans[dic[vol / (r*r)]]++;
						}
					}
				}
			}
		}
		
		Console.WriteLine(String.Join(" ",ans));
	}
	
	bool InRange(int t,int l, int r){ return l <= t && t < r;}
	
	int H,W;
	String[] S;
	public Sol(){
		var d = ria();
		H = d[0]; W = d[1];
		S = new String[H];
		for(int i=0;i<H;i++) S[i] = rs();
	}

	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(char sep=' '){return Console.ReadLine().Split(sep);}
	static int[] ria(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>int.Parse(e));}
	static long[] rla(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>long.Parse(e));}
	static double[] rda(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>double.Parse(e));}
}
class UnionFind{
	
	int[] parent;
	int[] mem;
	int compo;
	int N;
	public UnionFind(int n_){
		Initialize(n_);
	}
	
	public void Initialize(int n_){
		N=n_;
		parent=new int[N];
		mem=new int[N];
		for(int i=0;i<N;i++){
			parent[i]=i;
			mem[i]=1;
		}
		compo=N;
	}
	
	public int Parent(int a){
		if(parent[a]==a)return a;
		return parent[a]=Parent(parent[a]);
	}
	
	public bool IsUnited(int a,int b){
		return Parent(a)==Parent(b);
	}
	
	public void Unite(int a,int b){
		a=Parent(a);b=Parent(b);//Parent()??????a?????????parent?root???
		if(a==b)return;
		parent[a]=b;
		mem[b]+=mem[a];
		compo-=1;
	}
	
	public bool IsRoot(int x){
		return x==parent[x];
	}
	public int MemCnt(int x){
		return mem[Parent(x)];
	}
	
	public void Dump(){
		for(int i=0;i<parent.Length;i++){
			Console.Write(i==0?"{0}":" {0}",parent[i]);
		}
		Console.WriteLine("");
	}
	
	public int Compo{
		get{
			return compo;
		}
	}
	
}