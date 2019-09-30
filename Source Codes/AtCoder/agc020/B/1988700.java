import java.io.*;
import java.math.BigInteger;
import java.util.*;
/**
 *
 * @author prabhat
 */
public class  Main {

   static int[] a;
   static int[] S;
   static long[] sum;
   public static int mod=1000000007;
   static int[][] dp;
   static boolean[][] isPalin;
   static int max1=5000+10;
   static int[][] g;
   static int ver;
   static int n,m,k;
   static boolean[][] visit;
   static LinkedList<Pair> l[];
   static ArrayList<Integer> adj[];
   static boolean ans;
   static int[] color,parent,size,label,redD,dist[];
   static char[][] s;
   static int[] dx={1,0,-1,0};
   static int[] dy={0,-1,0,1};
   static int flag;
  static InputReader in;
  static  PrintWriter pw;
  public static void main(String[] args) throws Exception
   {
   	in = new InputReader(System.in);
        pw=new PrintWriter(System.out);
      
         n=in.ii();
          long a[]=new long[n+1];
        for(int i=1;i<=n;i++) a[i]=in.ii();
        long l=2,r=2;
        boolean b=true;
        for(int i=n;i>=1;i--){
            long x=(long)(Math.ceil(l/(1.0*a[i]))*a[i]);
            long y=(r/a[i])*a[i];
            if(x<l || y<l || x>r || y>r)  
            {
              b=false ;break;    
            }
            l=x;
            r=a[i]-1+y;
        }
        if(b)
        pw.println(l+" "+r);
        else pw.println(-1);
   	pw.close();
   }
     static  void update(int v) /* we are coloring v by red color and computing distance from this red node  to every ancestor of this red node*/
     {
       int u=v;
       int lb=label[v];
         while(u!=-1)
         {
           redD[u]=Math.min(redD[u],dist[lb][v]);
           u=parent[u];
           --lb;
         }
     
     }
  static int query(int v)
  {
    int ans=(int)(1e9);
    int u=v,lb=label[v];
    while(u!=-1)
    {
      ans=Math.min(ans,redD[u]+dist[lb][v]);
      u=parent[u];
      --lb;
    }
  return ans;
  }
  
  
       /*
	 * Distance Preprocessing
	 */
  static void computeDist(int s,int lb,int u,int p,int d)
  {
    dist[lb][u]=d;
    for(int next:adj[u])
    {
      if(next!=p&&label[next]>=lb)
          computeDist(s,lb,next,u,d+1);
    }
  }
 static int size(int u,int p)
 {
    int s=1;
    for(int next:adj[u])
    {
      if(next!=p&&parent[next]==-2)
          s+= size(next,u);
     
    }
     return size[u]=s;
 }
 static int decompose(int u,int p,int n,int lb)
 {
   if(p==-1)
       n=size(u,p);
   int idx=-1;
     for(int next:adj[u])
     {
        if(next!=p&&parent[next]==-2&&size[next]>n/2)
        {
          idx=next;
          break;
        }
     }
   if(idx!=-1)
    return   decompose(idx,u,n,lb);
     parent[u]=-1;    //u is centroid, decompose forest
     for(int next:adj[u])
     {
       if(parent[next]==-2)
           parent[decompose(next,-1,n,lb+1)]=u;
     }
   label[u]=lb;
   return u;
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
 
	public int compareTo(Pair o) {
		// TODO Auto-generated method stub
		if(this.a!=o.a)
		return -Integer.compare(this.a,o.a);
		else
			return -Integer.compare(this.b, o.b);
		//return 0;
	}
	public boolean equals(Object o) {
       if (o instanceof Pair) {
           Pair p = (Pair)o;
           return p.a == a && p.b == b;
       }
       return false;
   }
   public int hashCode() {
       return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
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