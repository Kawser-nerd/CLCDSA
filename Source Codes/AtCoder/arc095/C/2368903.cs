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
		
		found = false;
		int[] ar = new int[H];
		for(int i=0;i<H;i++){
			ar[i] = -1;
		}
		dfs(ar);
//Console.WriteLine("ccc:{0}",ccc);		
		Console.WriteLine(found ? "YES" : "NO");
		
	}
	
	
	bool found;
//int ccc = 0;
	void dfs(int[] ar){
//Console.WriteLine(String.Join(" ",ar));
		if(found) return;
		
		int l = -1;
		int m = -1;
		int rest = H;
		for(int i=0;i<H;i++){
			m = Math.Max(ar[i], m);
			if(ar[i] == -1 && l == -1){
				l = i;
			} else if(ar[i] != -1){
				rest--;
			}
		}
		if(rest == 0){
//ccc++;
			checkCol(ar);
			return;
		}
		
		m++;
		int strt = l;
		if(rest % 2 == 0) strt++;
		for(int j=strt;j<H;j++){
			if(ar[j] == -1){
				ar[l] = m;
				ar[j] = m;
				dfs(ar);
				ar[j] = -1;
				ar[l] = -1;
			}
		}
		ar[l] = -1;
	}
	
	void checkCol(int[] ar){
		
		int[] cnt = new int[(H + 1)/2];
		for(int i=0;i<H;i++) cnt[ar[i]]++;
		List<int>[] gp = new List<int>[(H + 1)/2];
		for(int i=0;i<(H + 1)/2;i++) gp[i] = new List<int>(2);
		for(int i=0;i<H;i++) gp[ar[i]].Add(i);
		Array.Sort(gp, (l, r) => l.Count.CompareTo(r.Count));
		Array.Reverse(gp);
		
		String[] s = new String[H];
		for(int i=0;i<gp.Length;i++){
			s[i] = S[gp[i][0]];
			if(gp[i].Count > 1){
				s[H - 1 - i] = S[gp[i][1]];
			}
		}
		
		bool[] used = new bool[W];
		int sgl = W % 2;
		bool chk = true;
		
		for(int j0=0;j0<W;j0++){
			if(used[j0]) continue;
			bool chk1 = false;
			for(int j1=j0+1;j1<W;j1++){
				if(used[j1]) continue;
				bool chk2 = true;
				for(int i=0;i<H;i++){
					chk2 &= s[i][j0] == s[H - 1 - i][j1];
				}
				if(chk2){
					chk1 = true;
					used[j0] = used[j1] = true;
					break;
				}
			}
			if(chk1) continue;
			
			// palindromic
			if(sgl == 0){
				chk = false;
				break;
			}
			bool chk3 = true;
			for(int i=0;i<H;i++){
				chk3 &= s[i][j0] == s[H - 1 - i][j0];
			}
			if(chk3){
				sgl--;
				used[j0] = true;
				continue;
			}
			chk = false;
			break;
		}
		
		if(chk) found = true;
	}
	
	
	int H, W;
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