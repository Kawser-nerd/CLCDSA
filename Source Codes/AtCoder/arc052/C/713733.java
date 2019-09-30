import java.io.PrintWriter;
import java.util.*;

public class Main {
	static class Node {
		ArrayList<Integer> e = new ArrayList<>();
		ArrayList<Integer> c = new ArrayList<>();
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		Node[] node = new Node[N];
		for(int i=0; i<N; i++)
			node[i] = new Node();
		
		for(int i=0; i<M; i++) {
			int c = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			node[a].e.add(b);
			node[a].c.add(c);
			node[b].e.add(a);
			node[b].c.add(c);
		}
		
		long[] ans = new long[N];
		Arrays.fill(ans, Long.MAX_VALUE);
		ArrayList<PriorityQueue<Long>> q = new ArrayList<>();
		for(int i=0; i<N; i++)
			q.add(new PriorityQueue<Long>());
		q.get(0).add(0l);
		for(int i=0; i<N; i++) {
			while(q.get(i).size()>0) {
				Long cur = q.get(i).poll();
				long cost = cur>>14;
				int town = (int)(cur&((1<<14)-1));
				if(ans[town]<=cost)
					continue;
				ans[town] = cost;
				for(int j=0; j<node[town].e.size(); j++) {
					int next = node[town].e.get(j);
					long d = cost + (node[town].c.get(j)==0 ? 1 : i+1);
					int t = i + node[town].c.get(j);
					if(ans[next]>d)
						q.get(t).add((d<<14)|next);
				}
			}
		}
		
		for(int i=0; i<N; i++) {
			pw.println(ans[i]);
		}
		
		sc.close();
		pw.close();
	}
	
}