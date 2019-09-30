import java.io.*;
import java.util.*;
/*
 * Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid...
 */
public class Main
{
	static class segtree
	{ 
		int n;
		int[][] tr;
		void build()
		{
			for(int i=n-1;i>0;i--)
				if(tr[0][i<<1]>tr[0][(i<<1)|1]) {
					tr[0][i]=tr[0][i<<1];
					tr[1][i]=tr[1][i<<1];
				}
				else {
					tr[0][i]=tr[0][(i<<1)|1];
					tr[1][i]=tr[1][(i<<1)|1];	
				}
		}
		int[] query(int l,int r)
		{
			r++; // both are inclusive
			int[] res=new int[2];
			for(l+=n,r+=n;l<r;l>>=1,r>>=1)
			{
				if(l%2!=0) 
				{
					if(tr[0][l]>res[0])
					{
						res[0]=tr[0][l];
						res[1]=tr[1][l];
					}
					l++;
				}
				if(r%2!=0)
				{
					r--;
					if(tr[0][r]>res[0])
					{
						res[0]=tr[0][r];
						res[1]=tr[1][r];
					}
				}
			}
			return res;
		}
	}
	public static void main(String[]args) throws Exception
	{
		int n=ni(),m=ni();
		long[]d=new long[n];
		for(int i=1; i<n; i++)
			d[i]=d[i-1]+ni();
		int[][]b=new int[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				b[i][j]=ni();
		long[][]grid=new long[n+1][];
		for(int i=0; i<=n; i++)
			grid[i]=new long[i+2];
		segtree a=new segtree();
		a.tr=new int[2][2*n];
		a.n=n;
		deque hol=new deque();
		deque hor=new deque();
		int l,r;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++) {
				a.tr[0][j+n]=b[j][i];
				a.tr[1][j+n]=j;
			}
			a.build();
			hol.add(0);
			hor.add(n-1);
			while(hol.notempty())
			{
				l=hol.poll();
				r=hor.poll();
				if(l==r)
				{
					grid[l][l]+=b[l][i];
					grid[l+1][l+1]+=b[l][i];
					grid[l+1][l]-=b[l][i];
					grid[l][l+1]-=b[l][i];
				}
				else if(l<r)
				{
					int[]te=a.query(l,r);
					grid[te[1]][l]+=te[0];
					grid[r+1][te[1]+1]+=te[0];
					grid[r+1][l]-=te[0];
					grid[te[1]][te[1]+1]-=te[0];
					hol.add(l);
					hol.add(te[1]+1);
					hor.add(te[1]-1);
					hor.add(r);
				}
			}
		}
		for(int j=1; j<n; j++)
			for(int i=0; i<=j; i++)
				grid[j][i]+=grid[j-1][i];
		for(int j=0; j<n; j++)
			for(int i=1; i<=j; i++)
				grid[j][i]+=grid[j][i-1];
		long ans=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<=i; j++)
				ans=Math.max(ans,grid[i][j]+d[j]-d[i]);
		System.out.println(ans);
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
//	static final int mod=998_244_353;
	static final int mod=1000_000_007;
	static final double eps=1e-7;
	static final long inf=1000_000_000_000_000_000L;
	static class pair
	{
		int a,b;
		pair(){}
		pair(int c,int d){a=c;b=d;}
		@Override
		public int hashCode()
		{
			return (a+" "+b).hashCode();
		}
		public boolean equals(Object c)
		{
			return (a==(((pair)c).a)&&b==(((pair)c).b));
		}
	}
	public static void sort(int[][]a)
	{
		Arrays.sort(a, new Comparator<int[]>()
				{
			public int compare(int[]a,int[]b)
			{
				if(a[0]>b[0])
					return 1;
				if(a[0]<b[0])
					return -1;
				return 0;
			}
				});
	}
	static interface combiner
	{
		public int combine(int a, int b);
	}
	static void pr(Object a){output.append(a+"\n");}
	static void pr(){output.append("\n");}
	static void p(Object a){output.append(a);}
	static void pra(int[]a){for(int i:a)output.append(i+" ");output.append("\n");}
	static void pra(long[]a){for(long i:a)output.append(i+" ");output.append("\n");}
	static void pra(String[]a){for(String i:a)output.append(i+" ");output.append("\n");}
	static void pra(double[]a){for(double i:a)output.append(i+" ");output.append("\n");}
	static void sop(Object a){System.out.println(a);}
	static void flush(){System.out.print(output);output=new StringBuilder();}
	static int ni(){return Integer.parseInt(in.next());}
	static long nl(){return Long.parseLong(in.next());}
	static String ns(){return in.next();}
	static double nd(){return Double.parseDouble(in.next());}
	static int[] nia(int n){int a[]=new int[n];for(int i=0; i<n; i++)a[i]=ni();return a;}
	static int[] pnia(int n){int a[]=new int[n+1];for(int i=1; i<=n; i++)a[i]=ni();return a;}
	static long[] nla(int n){long a[]=new long[n];for(int i=0; i<n; i++)a[i]=nl();return a;}
	static String[] nsa(int n){String a[]=new String[n];for(int i=0; i<n; i++)a[i]=ns();return a;}
	static double[] nda(int n){double a[]=new double[n];for(int i=0; i<n; i++)a[i]=nd();return a;}
	static Reader in=new Reader();
	static StringBuilder output=new StringBuilder();
	static Random rn=new Random();
	static void reverse(int[]a){for(int i=0; i<a.length/2; i++){a[i]^=a[a.length-i-1];a[a.length-i-1]^=a[i];a[i]^=a[a.length-i-1];}}
	static int log2n(long a)
	{
		int te=0;
		while(a>0)
		{
			a>>=1;
			++te;
		}
		return te;
	}
	static class vectorl implements Iterable<Long>
	{
		long a[];
		int size;
		vectorl(){a=new long[10];size=0;}
		vectorl(int n){a=new long[n];size=0;}
		public void add(long b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
		@Override
		public Iterator<Long> iterator() {
			Iterator<Long> hola=new Iterator<Long>()
					{
				int cur=0;
						@Override
						public boolean hasNext() {
							return cur<size;
						}
						@Override
						public Long next() {
							return a[cur++];
						}				
					};
			return hola;
		}
	}
	static class vector implements Iterable<Integer>
	{
		int a[],size;
		vector(){a=new int[10];}
		vector(int n){a=new int[n];}
		public void add(int b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
		@Override
		public Iterator<Integer> iterator() {
			Iterator<Integer> hola=new Iterator<Integer>()
					{
				int cur=0;
						@Override
						public boolean hasNext() {
							return cur<size;
						}
						@Override
						public Integer next() {
							return a[cur++];
						}				
					};
			return hola;
		}
	}
	static class deque {
		int a[];
		int head,tail;
		deque(){a=new int[8];}
		void clear()
		{
			head=0;tail=0;
		}
		void add(int i)
		{	
			head=(head+1)&(a.length-1);
			if(tail==head)
			{
				int[]b=new int[2*a.length];
				System.arraycopy(a, tail, b, 0, a.length-tail);
				System.arraycopy(a, 0, b, a.length-tail, head);
				tail=0;
				a=b;
				head=(a.length>>>1);
			}
			a[(head-1)&(a.length-1)]=i;
		}
		int poll()
		{
			tail=(tail+1)&(a.length-1);
			return a[(tail-1)&(a.length-1)];
		}
		boolean notempty()
		{
			return head!=tail;
		}
	}
	static void exit(){System.out.print(output);System.exit(0);}
	static int min(int... a){int min=a[0];for(int i:a)min=Math.min(min, i);return min;}
	static int max(int... a){int max=a[0];for(int i:a)max=Math.max(max, i);return max;}	
	static int gcd(int... a){int gcd=a[0];for(int i:a)gcd=gcd(gcd, i);return gcd;}	
	static long min(long... a){long min=a[0];for(long i:a)min=Math.min(min, i);return min;}
	static long max(long... a){long max=a[0];for(long i:a)max=Math.max(max, i);return max;}	
	static long gcd(long... a){long gcd=a[0];for(long i:a)gcd=gcd(gcd, i);return gcd;}	
	static String pr(String a, long b){String c="";while(b>0){if(b%2==1)c=c.concat(a);a=a.concat(a);b>>=1;}return c;}
	static long powm(long a, long b, long mod2){long an=1;long c=a%mod2;while(b>0){if(b%2==1)an=(an*c)%mod2;c=(c*c)%mod2;b>>=1;}return an;}
	static long pow(long a, long b){long an=1;long c=a;while(b>0){if(b%2==1)an*=c;c*=c;b>>=1;}return an;}
	static int gcd(int a, int b){if(b==0)return a;return gcd(b, a%b);}
	static long gcd(long a, long b){if(b==0)return a;return gcd(b, a%b);}
	static class Reader{
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
    }
}