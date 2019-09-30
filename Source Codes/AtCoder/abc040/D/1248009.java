import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int N; //????
	static int M; //????
	static int[]a;
	static int[]b;
	static int[]y; //???????
	static int Q; //???
	static int[]v; //???????
	static int[]w; //?w????????
	static int[]count;
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();

		Road route[]=new Road[M];
		y=new int[M];
		a=new int[M];
		b=new int[M];
		
		for(int i=0;i<M;i++){
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
			y[i]=sc.nextInt();
			route[i]=new Road(a[i],b[i],y[i]);
		}
		
		Arrays.sort(route);
		
		Q=sc.nextInt();
		People[] p=new People[Q];
		v=new int[Q+1];
		w=new int[Q+1];
		
		for(int i=0;i<Q;i++){
			v[i]=sc.nextInt();
			w[i]=sc.nextInt();
			p[i]=new People(v[i],w[i],i);
		}
		Arrays.sort(p);
		
		UnionFind unionfind=new UnionFind(N);
		
		count=new int[Q];
		int j=0;
		for(int i=0;i<Q;i++){
			while(route[j].year>p[i].year){
				unionfind.unite(route[j].a, route[j].b);
				if(j<M-1)j++;
				if(j==M-1)break;
			}
			count[p[i].id]=unionfind.s[unionfind.root(p[i].town)];
		}
		
		for(int i=0;i<Q;i++)System.out.println(count[i]);
		
	}
	static class Road implements Comparable<Road>{
		int a;
		int b;
		int year;
		public Road(int town1,int town2,int year){
			a=town1;
			b=town2;
			this.year=year;
		}
		@Override
		public int compareTo(Road d){
			return -(this.year-d.year);
		}
	}
	static class People implements Comparable<People>{
		int id;
		int town;
		int year;
		public People(int town,int year,int id){
			this.town=town;
			this.year=year;
			this.id=id;
		}
		@Override
		public int compareTo(People p){
			return -(this.year-p.year);
		}
	}
	static class UnionFind {
		int MAX_N=1000000; //??????
		int par[]=new int[MAX_N]; //????
		int rank[]=new int[MAX_N]; //????
		int s[] =new int[MAX_N]; //???????????
		
		//n??????
		UnionFind(int n){
			for(int i=0;i<n;i++){
				par[i]=i;
				rank[i]=0;
				s[i]=1;
			}
		}
		//???????
		int root(int x){
			if(par[x]==x){
				return x; //?
			}
			else {
				return par[x]=root(par[x]); //????
			}
		}
		//x?y????????????
		boolean isSame(int x,int y){
			return root(x)==root(y);
		}
		//x?y?????????
		void unite(int x,int y){
			x=root(x);
			y=root(y);
			if(x==y)return;
			
			if(rank[x]<rank[y]){
				par[x]=y;
				s[x]+=s[y];
				s[y]=s[x];
			}else{
				par[y]=x;
				s[x]+=s[y];
				s[y]=s[x];
				if(rank[x]==rank[y])rank[x]++;
			}
		}
		
	}
}