import java.io.*;
import java.util.*;
public class a {
	public static void main(String[] args) throws Exception
	{
		P4 p=new P4();
		p.solve();
	}
}
class P1
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		sc.nextLine();
		this.precompute();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private int step(int n,int base)
	{
		int r=0;
		while(n>0)
		{
			r+=((n%base)*(n%base));
			n/=base;
		}
		return r;
	}
	private boolean isHappy(int n,int base)
	{
		HashSet<Integer> s=new HashSet<Integer>();
		while(true)
		{
			if(n==1)
			{
				return true;
			}
			if(s.contains(n))
			{
				return false;
			}
			s.add(n);
			n=step(n,base);
		}
	}
	private int[] sieve(int[] a,int base)
	{
		int N=a.length;
		int[] b=new int[N];
		int j=0;
		for(int i=0;i<N;i++)
		{
			if(this.isHappy(a[i], base))
			{
				b[j]=a[i];
				j++;
			}
		}
		int[] c=new int[j];
		for(int i=0;i<j;i++)
		{
			c[i]=b[i];
		}
		return c;
	}
	private int[] test(int N,int[] b)
	{
		int[] a=new int[N];
		for(int i=0;i<N;i++)
		{
			a[i]=i+2;
		}
		for(int i=0;i<b.length;i++)
		{
			a=this.sieve(a, b[i]);
		}
		//System.out.println(a.length);
		//if(a.length>1)
		//{
		//	System.out.println(a[1]);
		//}
		return a;
	}
	private int[] test10(int N,int[] b)
	{
		int j=0;
		int[] a=new int[N];
		for(int i=0;i<N;i++)
		{
			a[i]=pre[i];
		}
		for(int i=0;i<b.length;i++)
		{
			a=this.sieve(a, b[i]);
		}
		//System.out.println(a.length);
		//if(a.length>1)
		//{
		//	System.out.println(a[1]);
		//}
		return a;
	}
	int[] pre;
	private void precompute()
	{
		int N=5000000;
		int j=0;
		int[] a=new int[N];
		for(int i=2;;i++)
		{
			if(this.isHappy(i, 10))
			{
				a[j]=i;
				j++;
			}
			if(j==N)
			{
				break;
			}
		}
		pre=a;
		//System.out.println("pre completed");
	}
	private void solve1() throws Exception
	{
		String s=sc.nextLine();
		String[] ss=s.split(" ");
		int n=ss.length;
		int[] b=new int[n];
		for(int i=0;i<n;i++)
		{
			b[i]=Integer.parseInt(ss[i]);
		}
		Arrays.sort(b);
		//System.out.println(b[b.length-1]);
		if(b[n-1]==10)
		{
			for(int m=50;;m*=10)
			{
				int[] a=this.test10(m,b);
				if(a.length>0)
				{
					System.out.println(a[0]);
					break;
				}
			}
		}
		else
		{
			for(int m=50;;m*=10)
			{
				int[] a=this.test(m,b);
				if(a.length>0)
				{
					System.out.println(a[0]);
					break;
				}
			}
		}
	}

}
class Graph
{
	HashSet<Integer> nodes;
	HashMap<Integer,HashSet<Integer>> adj;
	HashMap<Integer,HashMap<Integer,Edge>> edges;
	public Graph()
	{
		nodes=new HashSet<Integer>();
		adj=new HashMap<Integer,HashSet<Integer>>();
		edges=new HashMap<Integer,HashMap<Integer,Edge>>();
	}
	public void addNode(int node)
	{
		nodes.add(node);
		adj.put(node,new HashSet<Integer>());
		edges.put(node, new HashMap<Integer,Edge>());
	}
	public void addEdge(int node1,int node2,int distance)
	{
		adj.get(node1).add(node2);
		adj.get(node2).add(node1);
		Edge edge=new Edge(distance);
		edges.get(node1).put(node2,edge);
		edges.get(node2).put(node1,edge);
	}
	public void addCrossingEdge(int node1,int node2,int distance,long green,long red,long T)
	{
		adj.get(node1).add(node2);
		adj.get(node2).add(node1);
		Edge edge=new CrossingEdge(green,red,T,distance);
		edges.get(node1).put(node2,edge);
		edges.get(node2).put(node1,edge);
	}
}
class Edge
{
	public long distance;
	public Edge(long distance)
	{
		this.distance=distance;
	}
	public long cross(long t)
	{
		return t+this.distance;
	}
}
class CrossingEdge extends Edge
{
	long green;
	long red;
	long T;
	long cycle;
	public CrossingEdge(long green,long red,long T,long distance)
	{
		super(distance);
		this.green=green;
		this.red=red;
		this.T=T;
		this.cycle=green+red;
		//System.out.println(green);
		//System.out.println(red);
		//System.out.println(cycle);
	}
	public long cross(long t)
	{
		long n=(t-T)%cycle;
		n=(n+cycle)%cycle;
		if(n<=green-1)
		{
			return t+distance;
		}
		else
		{
			return t+(cycle-n)+distance;
		}
	}
}
class BellmanFord
{
	Graph g;
	Hashtable<Integer,Long> d;
	public BellmanFord(Graph g)
	{
		this.g=g;
	}
	public Hashtable<Integer,Long> solve(Integer start)
	{
		d=new Hashtable<Integer,Long>();
		for(Integer node:g.nodes)
		{
			d.put(node, 100000000000000L);
		}
		d.put(start, 0L);
		for(int i=0;i<g.nodes.size();i++)
		{
			for(int node:g.nodes)
			{
				for(int node2:g.adj.get(node))
				{
					relax(node,node2);
				}
			}
		}
		return d;
	}
	public void relax(int node1,int node2)
	{
		Edge e=g.edges.get(node1).get(node2);
		if(e.cross(d.get(node1))<d.get(node2))
		{
			d.put(node2,e.cross(d.get(node1)));
		}
	}
}
class P2
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private void solve1() throws Exception
	{
		
	}

}
class P3
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private double factorial(int n)
	{
		double r=1;
		for(int i=1;i<=n;i++)
		{
			r*=i;
		}
		return r;
	}
	private double choose(int n,int k)
	{
		if(k<0)
		{
			return 0;
		}
		if(n<k)
		{
			return 0;
		}
		if(k==0)
		{
			return 1;
		}
		if(n==k)
		{
			return 1;
		}
		return factorial(n)/(factorial(k)*factorial(n-k));
	}
	private double f(int n,int m,int c,int i)
	{
		return choose(n-m,i)*choose(m,c-i)/choose(n,c);
	}
	private void solve1() throws Exception
	{
		int n=sc.nextInt();
		int c=sc.nextInt();
		double[] p=new double[n+1];
		//System.out.println(f(3,2,2,0));
		//System.out.println(choose(1,0));
		//System.out.println(choose(2,2));
		//System.out.println(choose(3,2));
		//System.out.println(factorial(3));
		//System.out.println(factorial(2));
		p[n]=0;
		for(int m=n-1;m>=0;m--)
		{
			double denominator=1-f(n,m,c,0);
			double numerator=1;
			for(int i=1;i<=c;i++)
			{
				if(m+i<=n)
				{
					numerator+=(f(n,m,c,i)*p[m+i]);
				}
			}
			p[m]=numerator/denominator;
			//System.out.println(" "+m+" "+p[m]+" "+numerator+" "+denominator);
		}
		System.out.println(p[0]);
	}

}
class P4
{
	public static Scanner sc=new Scanner(System.in);
	public void solve() throws Exception
	{
		int N=sc.nextInt();
		for(int i=0;i<N;i++)
		{
			System.out.print("Case #"+(i+1)+": ");
			solve1();
		}
	}
	private int node(int x,int y,int i,int j)
	{
		return x*100000+y*1000+i*10+j;
	}
	private void solve1() throws Exception
	{
		int N=sc.nextInt();
		int M=sc.nextInt();
		Graph g=new Graph();
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				g.addNode(node(j,i,0,0));
				g.addNode(node(j,i,0,1));
				g.addNode(node(j,i,1,0));
				g.addNode(node(j,i,1,1));
			}
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M-1;j++)
			{
				g.addEdge(node(j,i,1,0),node(j+1,i,0,0), 2);
				g.addEdge(node(j,i,1,1),node(j+1,i,0,1), 2);
			}
		}
		for(int i=0;i<N-1;i++)
		{
			for(int j=0;j<M;j++)
			{
				g.addEdge(node(j,i,0,1),node(j,i+1,0,0), 2);
				g.addEdge(node(j,i,1,1),node(j,i+1,1,0), 2);
			}
		}
		//System.out.println("df");
		sc.nextLine();
		for(int i=0;i<N;i++)
		{
			String s=sc.nextLine();
			String[] ss=s.split(" ");
			int[] a=new int[3*M];
			for(int j=0;j<3*M;j++)
			{
				a[j]=Integer.parseInt(ss[j]);
			}
			for(int j=0;j<M;j++)
			{
				long S=a[3*j];
				long W=a[3*j+1];
				long T=a[3*j+2];
				g.addCrossingEdge(node(j,i,0,0),node(j,i,0,1),1, S, W, T);
				g.addCrossingEdge(node(j,i,1,0),node(j,i,1,1),1, S, W, T);
				g.addCrossingEdge(node(j,i,0,0),node(j,i,1,0),1, W, S, T+S);
				g.addCrossingEdge(node(j,i,0,1),node(j,i,1,1),1, W, S, T+S);
			}
		}
		BellmanFord bf=new BellmanFord(g);
		//System.out.println("df");
		System.out.println(bf.solve(node(0,N-1,0,1)).get(node(M-1,0,1,0)));
	}
}