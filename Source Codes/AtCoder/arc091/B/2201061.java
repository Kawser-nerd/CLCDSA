import java.io.*;
import java.util.*;
/**
 *
 * @author prabhat
 */
 class Main {

 
    //static int[] a;
    static int[] S;
    static long[] sum;
   public static int mod=1000000007;
   static int[][] dp;
   static boolean[][] isPalin;
   static int max1=5000+10;
   static int[][] g;
   static int ver;
   static int n,k,m;
   static boolean[] visit;
   static LinkedList<Pair> l[];
   static int ans=0;
   static int[] color,log,st[],a[],prefixSum[];
  
  public static void main(String[] args) throws Exception
   {
   	InputReader in = new InputReader(System.in);
   	PrintWriter pw=new PrintWriter(System.out);
       n=in.ii();
       int k=in.ii();
       long ans=0;
       for(int b=k+1;b<=n;b++)
       {
           long temp=b-k;
           temp*=n/b;
           if(n%b>=k && n%b!=0)
           {
               if(k==0)
                   temp+=n%b;
               else temp+=n%b-k+1;
           }
           ans+=temp;
       }
       pw.println(ans);
   	 pw.close();
   }
  	static long binaryToDecimal(int[] x){
		long dec_value=0;
		long base = 1;
		int len = x.length;
		for(int i = len-1;i>=0;i--){
			if(x[i]==0){
				dec_value = dec_value+0*base;
				base =base*2;
			}
			else{
				dec_value = dec_value+1*base;
				base = base*2;
			}
			
		}
		return dec_value;
	}
  static int getSum(int x1,int y1,int x2,int y2)
  {
      int total=prefixSum[x2][y2];
      int n=y1>0?prefixSum[x2][y1-1]:0;
      int w=x1>0?prefixSum[x1-1][y2]:0;
      int nw=x1>0&&y1>0?prefixSum[x1-1][y1-1]:0;
      return total-n-w+nw;
  }
   static class SparseTable2D  
   {
	int sparse[][][][];
	int log[];
	int R,C;
 
	int getMax(int x1,int y1,int x2,int y2, boolean build){
	    int x_sz = x2 - x1 + 1;
	    int y_sz = y2 - y1 + 1;
	    int k1 = (x_sz == 1) ? 0 :log[build ? (x_sz - 1) : x_sz];
	    int k2 = (y_sz == 1) ? 0 :log[build ? (y_sz - 1) : y_sz];
	    int NW = sparse[k1][k2][x1][y1]; 					   //North-West
	    int NE = sparse[k1][k2][x1][y2 - (1 << k2) + 1];    		   //North-East
	    int SW = sparse[k1][k2][x2 - (1 << k1) + 1][y1]; 		           //South-West
	    int SE = sparse[k1][k2][x2 - (1 << k1) + 1][y2 - (1 << k2) + 1];       //South-East
	    return (int) Math.max(Math.max(NW,NE),Math.max(SW,SE));
	}
 
	SparseTable2D(int arr[][],int R,int C)
	{
	    this.R = R;
	    this.C = C;
	    
	    log = new int[Math.max(R,C) + 1000];
	    for(int i=2;i<log.length;i++)		
		log[i] = ((i & (i-1)) == 0) ? log[i-1] + 1 : log[i-1];
	    
	    int k1 = log[R] + 1;
	    int k2 = log[C] + 1;
	    sparse = new int[k1][k2][R][C];
	    for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		    sparse[0][0][i][j] = arr[i][j];
 
	    for(int h=0;h<k1;h++)
	    {
		for(int v=0;v<k2;v++)
		{
		    if(!(h == 0 && v == 0))
		    {
			for(int i=0;i+(1<<h) <= R;i++)
			{
			    for(int j=0;j+(1<<v) <= C;j++)
			    {
				sparse[h][v][i][j] = getMax(i, j, i + (1<<h) - 1, j + (1<<v) - 1, true);
			    }
			}
		    }
		}
	    }
 
	}
    }
 static class SparseTable1D
    {
	int sparse[][];
	int len;
	int log[];
	SparseTable1D(int arr[])
	{
	    len = arr.length;
	    log = new int[len + 1000];
	    for(int i=2;i<log.length;i++)		
		log[i] = ((i & (i-1)) == 0) ? log[i-1] + 1 : log[i-1];
	    
	    int k = log[len] + 1;	    
	    sparse = new int[len][k];
	    for(int i=0;i<len;i++)
		sparse[i][0] = arr[i];
 
	    for(int j=1;j<k;j++)
	    {
		for(int i=0;i+(1<<j) <= len;i++)
		{
		    sparse[i][j] = Math.max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
		}
	    }
	}
 
	int getMaxInRange(int L,int R)
	{
	    int sz = R - L + 1;
	    int k  = log[sz];
	    int v1 = sparse[L][k];
	    int v2 = sparse[R-(1<<k)+1][k];
	    return Math.max(v1,v2);
	}
 
    }
  private static class DSU{
		int[] parent;
		int[] rank;
		int cnt;
		public DSU(int n){
			parent=new int[n];
			rank=new int[n];
			for(int i=0;i<n;i++){
				parent[i]=i;
				rank[i]=1;
			}
			cnt=n;
		}
		int find(int i){
	        while(parent[i] !=i){
	        	parent[i]=parent[parent[i]];
	        	i=parent[i];
	        }
	        return i;
	    }
		int Union(int x, int y){
	        int xset = find(x);
	        int yset = find(y);
	        if(xset!=yset)
	        	cnt--;
	        if(rank[xset]<rank[yset]){
	        	parent[xset] = yset;
		        rank[yset]+=rank[xset];
		        rank[xset]=0;
		        return yset;
	        }else{
	        	parent[yset]=xset;
	        	rank[xset]+=rank[yset];
	        	rank[yset]=0;
	        	return xset;
	        }
	    }
	}
  public static int[][] packU(int n, int[] from, int[] to, int max) {
	    
	    int[][] g = new int[n][];
	    int[] p = new int[n];
	    for (int i = 0; i < max; i++) p[from[i]]++;
	    for (int i = 0; i < max; i++) p[to[i]]++;
	    for (int i = 0; i < n; i++) g[i] = new int[p[i]];
	    for (int i = 0; i < max; i++) {
	        g[from[i]][--p[from[i]]] = to[i];
	        g[to[i]][--p[to[i]]] = from[i];
	    }
	    return g;
	}
	public static int[][] parents3(int[][] g, int root) {
	    int n = g.length;
	    int[] par = new int[n];
	    Arrays.fill(par, -1);
 
	    int[] depth = new int[n];
	    depth[0] = 0;
 
	    int[] q = new int[n];
	    q[0] = root;
	    for (int p = 0, r = 1; p < r; p++) {
	        int cur = q[p];
	        for (int nex : g[cur]) {
	            if (par[cur] != nex) {
	                q[r++] = nex;
	                par[nex] = cur;
	                depth[nex] = depth[cur] + 1;
	            }
	        }
	    }
	    return new int[][]{par, q, depth};
	}
	public static int lower_bound(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low] == target ? low : -1;
    }
 
    public static int upper_bound(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high + 1 - low) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid;
        }
        return nums[low] == target ? low : -1;
    }
  public static boolean palin(String s)
	{
	   int i=0;
	   int j=s.length()-1;
	   while(i<j)
	   {
		   if(s.charAt(i)==s.charAt(j))
		   {
			   i++;
			   j--;
		   }
		   else return false;     
	   }
	   return true;
	}
	
    static boolean CountPs(String s,int n)
       {
    	boolean b=false;
    	     char[] S=s.toCharArray();
	       int[][] dp=new int[n][n];
	       boolean[][] p=new boolean[n][n];
	       for(int i=0;i<n;i++)p[i][i]=true;
	     
	       for(int i=0;i<n-1;i++)
	       {
	    	   if(S[i]==S[i+1])
	    	   {
	    		p[i][i+1]=true;
	    		dp[i][i+1]=1;
	    		b=true;
	    	   }
	       }
	    
	       for(int gap=2;gap<n;gap++)
	       {
	    	   for(int i=0;i<n-gap;i++)
	    	   {
	    		   int j=gap+i;
	    		   if(S[i]==S[j]&&p[i+1][j-1]){p[i][j]=true;}
	    		  
	    		  if(p[i][j])
	    			   dp[i][j]=dp[i][j-1]+dp[i+1][j]+1-dp[i+1][j-1];
	    		   
	    		   else  dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
	    		  
	    		   if(dp[i][j]>=1){b=true;}
	    	   }
	       }
	      
	    return b; 
   // return dp[0][n-1];
	       
    }
  
  
  
 
 
public static int gcd(int a,int b)
{
	int res=1;
	while(a>0)
	{
		res=a;
		a=b%a;
		b=res;
	}
	return res;
}
 
 
public static long pow(long n,long p,long m)
{
	 long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    if(result>=m)
	    result%=m;
	    p >>=1;
	    n*=n;
	    if(n>=m)
	    n%=m;
	}
	return result;
}
public static long pow(long n,long p)
{
	long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    p >>=1;
	    n*=n;
	}
	return result;
 
}
 
 
 
 
static class Edge implements Comparator<Edge> {
	private int u;
	private int v;
	private int w;
	public Edge() {
	}
	public Edge(int u, int v, int w) {
		this.u=u;
		this.v=v;
		this.w=w;
	}
	public int getU() {
		return u;
	}
	public void setU(int u) {
		this.u = u;
	}
	public int getV() {
		return v;
	}
	public void setV(int v) {
		this.v = v;
	}
	public int getW() {
		return w;
	}
	public void setW(int w) {
		this.w = w;
	      }
	public int compareTo(Edge e)
	  {
		return this.getW() - e.getW();
	}
	@Override
	public String toString() {
		return "Edge [u=" + u + ", v=" + v + ", w=" + w + "]";
	}
	@Override
	public int compare(Edge arg0, Edge arg1) {
		// TODO Auto-generated method stub
		return 0;
	}
}
 
 
 
static class Pair implements Comparable<Pair>
{
	int a,b;
	Pair (int a,int b)
	{
		this.a=a;
		this.b=b;
	}
 
        @Override
        public int compareTo(Pair o) {
            //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
          
           return this.b-o.b;
        }
 
}
 
static  class InputReader
{
   private InputStream stream;
   private byte[] buf = new byte[1024];
 
   private SpaceCharFilter filter;
    byte inbuffer[] = new byte[1024];
   int lenbuffer = 0, ptrbuffer = 0;
    final int M = (int) 1e9 + 7;
   int md=(int)(1e7+1);
    int[] SMP=new int[md];
   final double eps = 1e-6;
   final double pi = Math.PI;
 
	PrintWriter out;
   String check = "";
 InputStream   obj = check.isEmpty() ? System.in : new ByteArrayInputStream(check.getBytes());
   public InputReader(InputStream stream)
   {
       this.stream = stream;
   }
 
    int readByte() {
	        if (lenbuffer == -1) throw new InputMismatchException();
	        if (ptrbuffer >= lenbuffer) {
	            ptrbuffer = 0;
	            try {
	                lenbuffer = obj.read(inbuffer);
	            } catch (IOException e) {
	                throw new InputMismatchException();
	            }
	        }
	        if (lenbuffer <= 0) return -1;
	        return inbuffer[ptrbuffer++];
   }
 
   public  int read()
   {
       int c = read();
       while (isSpaceChar(c))
           c = read();
       int sgn = 1;
       if (c == '-')
       {
           sgn = -1;
           c = read();
       }
       int res = 0;
       do
       {
           if (c < '0' || c > '9')
               throw new InputMismatchException();
           res *= 10;
           res += c - '0';
           c = read();
       } while (!isSpaceChar(c));
       return res * sgn;
   }
 
   String is() {
	        int b = skip();
	        StringBuilder sb = new StringBuilder();
	        while (!(isSpaceChar(b))) // when nextLine, (isSpaceChar(b) && b!=' ')
	        {
	            sb.appendCodePoint(b);
	            b = readByte();
	        }
	        return sb.toString();
   }
   public   int ii() {
	        int num = 0, b;
	        boolean minus = false;
	        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	        if (b == '-') {
	            minus = true;
	            b = readByte();
	        }
	        while (true) {
	            if (b >= '0' && b <= '9') {
	                num = num * 10 + (b - '0');
	            } else {
	                return minus ? -num : num;
	            }
	            b = readByte();
	        }
   }
 public   long il() {
	        long num = 0;
	        int b;
	        boolean minus = false;
	        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	        if (b == '-') {
	            minus = true;
	            b = readByte();
	        }
	        while (true) {
	            if (b >= '0' && b <= '9') {
	                num = num * 10 + (b - '0');
	            } else {
	                return minus ? -num : num;
	            }
	            b = readByte();
	        }
   }
   
	    boolean isSpaceChar(int c) {
	        return (!(c >= 33 && c <= 126));
	       }
 
	      int skip()
	        {
	        int b;
	        while ((b = readByte()) != -1 && isSpaceChar(b)) ;
	        return b;
	        }
 
	    float nf() {
	        return Float.parseFloat(is());
	    }
 
	    double id() {
	        return Double.parseDouble(is());
	    }
 
	    char ic() {
	        return (char) skip();
	    }
 
	    int[] iia(int n) {
	        int a[] = new int[n];
	        for (int i = 0; i<n; i++) a[i] = ii();
	        return a;
	    }
 
	    long[] ila(int n) {
	        long a[] = new long[n];
	        for (int i = 0; i <n; i++) a[i] = il();
	        return a;
	    }
 
	    String[] isa(int n) {
	        String a[] = new String[n];
	        for (int i = 0; i < n; i++) a[i] = is();
	        return a;
	    }
 
 
		 long mul(long a, long b) { return a * b % M; }
 
			long div(long a, long b)
				 {
					return mul(a, pow(b, M - 2));
 
		           }
 
 
 
	    double[][] idm(int n, int m) {
	        double a[][] = new double[n][m];
	        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = id();
	        return a;
	        }
 
	    int[][] iim(int n, int m) {
	        int a[][] = new int[n][m];
	        for (int i = 0; i < n; i++) for (int j = 0; j <m; j++) a[i][j] = ii();
	        return a;
          }
 
 
   public String readLine() {
       int c = read();
       while (isSpaceChar(c))
           c = read();
       StringBuilder res = new StringBuilder();
       do {
           res.appendCodePoint(c);
           c = read();
       } while (!isEndOfLine(c));
       return res.toString();
   }
 
   public interface SpaceCharFilter
   {
       public boolean isSpaceChar(int ch);
   }
   public boolean isEndOfLine(int c) {
       return c == '\n' || c == '\r' || c == -1;
   }
}
 
}