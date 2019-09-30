import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		long X=sc.nextLong();
		int[] a=new int[m],b=new int[m];
		long[] v=new long[m];
		for(int i=0;i<m;i++){
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
			v[i]=sc.nextLong();
		}
		
		int[] stack=new int[n-1];
		int size=0;
		
		long cost=0;
		UF uf=new UF(n+1);
		PriorityQueue<Integer> queue=new PriorityQueue<>((x,y) -> Long.signum(v[x]-v[y]));
		for(int i=0;i<m;i++) queue.add(i);
		while(queue.size()>0){
			int cur=queue.poll();
			if(uf.connected(a[cur],b[cur])) continue;
			cost+=v[cur];
			uf.union(a[cur],b[cur]);
			stack[size++]=cur;
		}
		
		int[] aa=new int[n-1],bb=new int[n-1];
		long[] vv=new long[n-1];
		for(int i=0;i<n-1;i++){
			int ind=stack[i];
			aa[i]=a[ind];
			bb[i]=b[ind];
			vv[i]=v[ind];
		}
		Object[] obj=get(n,aa,bb,vv);
		int[][] ad=(int[][]) obj[0];
		long[][] vad=(long[][]) obj[1];
		
		int a0=0,a1=0,a2=0;
		long[] table=new long[n+1];
		int[] ss=new int[m*2];
		for(int i=0;i<m;i++){
			int ssize=0;
			ss[ssize++]=a[i];
			Arrays.fill(table,0);
			while(ssize>0){
				int cur=ss[--ssize];
				for(int j=0;j<ad[cur].length;j++){
					int ch=ad[cur][j];
					if(table[ch]!=0) continue;
					table[ch]=Math.max(table[cur],vad[cur][j]);
					ss[ssize++]=ch;
				}
				if(table[b[i]]>0) break;
			}
			
			long sa=v[i]-table[b[i]];
			if(sa==(X-cost)) a1++;
			if(sa<(X-cost)) a0++;
			if(sa>(X-cost)) a2++;
		}
		//System.out.println(a0+" "+a1+" "+a2);
		
		long mod=1000000007;
		if(X<cost){
			System.out.println(0);
			return;
		}
		if(X==cost){
			a1-=n-1;
			long res=(modPow(2,n-1,mod)-2+mod)%mod * modPow(2,m-n+1,mod)%mod;
			res=(res+2*(modPow(2,a1,mod)-1+mod)%mod * modPow(2,a2,mod)%mod)%mod;
			System.out.println(res);
		}else{
			long res=2*(modPow(2,a1,mod)-1+mod)%mod * modPow(2,a2,mod)%mod;
			System.out.println(res);
		}
	}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1) res=(res*c)%mod;
			c=(c*c)%mod;
			b/=2;
		}
		return res;
	}
	static Object[] get(int n,int[] a,int[] b,long[] v){
		int[][] res=new int[n+1][];
		int[] c=new int[n+1];
		long[][] cres=new long[n+1][];
		for(int i=0;i<a.length;i++){
			c[a[i]]++;
			c[b[i]]++;
		}
		for(int i=0;i<=n;i++){
			res[i]=new int[c[i]];
			cres[i]=new long[c[i]];
		}
		for(int i=0;i<a.length;i++){
			res[a[i]][--c[a[i]]]=b[i];
			cres[a[i]][c[a[i]]]=v[i];
			res[b[i]][--c[b[i]]]=a[i];
			cres[b[i]][c[b[i]]]=v[i];
		}
		return new Object[]{res,cres};
	}
}
class UF {
	private int[] par;
	private byte[] rank;
	private int[] size;
	private int count;
	
	public UF(int n) {
		count = n;
		par = new int[n];
		rank = new byte[n];
		size = new int[n];
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
			size[i] = 1;
		}
	}
	
	public int find(int x) {
		if(x==par[x])return x;
		par[x]=find(par[x]);
		return par[x];
	}
	
	public int count() {
		return count;
	}
	
	public boolean connected(int x, int y) {
		return find(x) == find(y);
	}
	
	public void union(int x, int y) {
		x = find(x);
		y = find(y);
		if(rank[x] > rank[y]){
			int z = x;
			x = y;
			y = z;
		}
		
		if(rank[x]==rank[y]) rank[y]++;
		par[x]=y;
		size[y]+=size[x];
		count--;
	}
	public int size(int x){
		x=find(x);
		return size[x];
	}
}