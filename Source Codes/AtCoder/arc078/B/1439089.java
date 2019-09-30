import java.util.*;

public class Main {

	static List<Integer> adj[];
	public static void addEdge(int u,int v)
	{
		adj[u].add(v);
		adj[v].add(u);
	}
	static class pair
	{
		int i,j;
		public pair(int i,int j)
		{
			this.i=i;
			this.j=j;
		}
	}
	public static String VertexColoring(int N)
	{
		Queue<pair> q=new LinkedList<>();
		q.offer(new pair(0, 0));
		q.offer(new pair(N-1, 1));
		
		int color[]=new int[N];
		Arrays.fill(color, -1);
		
		while(!q.isEmpty())
		{
			pair p=q.poll();
			
			if(color[p.i]==-1)
			{
				color[p.i]=p.j;
				
				Iterator<Integer> itr=adj[p.i].iterator();
				while(itr.hasNext())
				{
					q.offer(new pair(itr.next(), p.j));
				}
			}
			
		}
		
		int s[]=new int[2];
		for (int i = 0; i < N; i++) {
			s[color[i]]++;
		}
		return s[0]>s[1]?"Fennec":"Snuke";
		
	}
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int V=sc.nextInt();
		adj=new LinkedList[V];
		for (int i = 0; i < V; i++) {
			adj[i]=new LinkedList<>();
		}
		for (int i = 0; i < V-1; i++) {
			int u=sc.nextInt();
			int v=sc.nextInt();
			u--;
			v--;
			addEdge(u, v);
		}
		
		System.out.println(VertexColoring(V));
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.