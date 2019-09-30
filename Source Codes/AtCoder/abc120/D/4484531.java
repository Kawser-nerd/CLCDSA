import java.util.Scanner;
import java.awt.Point;
public class Main{
	static boolean r;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Point[] g=new Point[m];
		long[] ans=new long[m];
		ans[m-1]=(long)n*(n-1)/2;
		for(int i = 0; i<m; i++){
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			g[i]=new Point(a,b);
		}
		Unionfind uf=new Unionfind(n);
		for(int i=m-1; i>=0; i--){
			if(i!=m-1){
				if(!r){
					ans[i]=ans[i+1]-uf.size(g[i+1].x);
				}else{
					ans[i]=ans[i+1];
				}
			}
			r=false;
			uf.unite(g[i].x,g[i].y);
		}
		for(int i = 0; i<m; i++){
			System.out.println(ans[i]);
		}
	}
	static class Unionfind{
		int[] parent;
		long[] ans;
		long[] size;
		public Unionfind(int n){
			this.parent=new int[n];
			this.size=new long[n];
			this.ans=new long[n];
			for(int i = 0; i<n; i++){
				parent[i]=i;
				size[i]=1;
			}
		}
		public int root(int t){
			if(parent[t]==t){
				return t;
			}else{
				return parent[t]=root(parent[t]);
			}
		}
		public void unite(int x,int y){
			if(same(x,y)){
				r=true;
				return;
			}
			int xroot = root(x);
			int yroot = root(y);
			parent[yroot]=xroot;
			ans[xroot]=size[yroot]*size[xroot];
			size[xroot]+=size[yroot];
		}
		public boolean same(int x,int y){
			return root(x)==root(y);
		}
		public long size(int x){
			return ans[root(x)];
		}
	}
}