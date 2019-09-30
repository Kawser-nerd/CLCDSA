import java.util.*;
public class Main {
	
	public static class unionfind{
		int[] parent;
		int[] number;
		public unionfind(int n){
			this.parent = new int[n+1];
			this.number = new int[n+1];
			for(int i = 1; i <= n; i++) set(i);
		}
		public void set(int i) {
			parent[i] = i;
			number[i] = 1;
		}
		public int find(int i) {
			if (i == parent[i])
				return parent[i];
			else
				return parent[i] = find(parent[i]);
			
		}
		public boolean same(int x, int y){
			return find(x) == find(y);
		}
		public void unite(int x, int y) {
			int xroot = find(x);
			int yroot = find(y);
			if(xroot == yroot)
				return;
			else {
				parent[yroot] = xroot;
				number[xroot] += number[yroot];
			}
		}
		public int getnumber(int i) {
			return number[find(i)];
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] A = new int[m];
		int[] B = new int[m];
		for(int i = 0; i < m; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		unionfind u = new unionfind(n);
		long[] ans = new long[m+1];
		ans[m] = (long)n*(n-1)/2;
		if(m != 1) {
			for(int i = m-1; i >= 0; i--) {
				if(u.same(A[i], B[i])) {
					ans[i] = ans[i+1];
				}
				else{
					ans[i] = ans[i+1] - u.getnumber(A[i])*u.getnumber(B[i]);
					u.unite(A[i], B[i]);
				}
			}
		}
		for(int i = 1; i <= m; i++) {
			System.out.println(ans[i]);
		}
	}
}