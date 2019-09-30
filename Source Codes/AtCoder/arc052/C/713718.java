import java.io.PrintWriter;
import java.util.*;

public class Main {
	static class Node {
		ArrayList<Integer> e = new ArrayList<>();
		ArrayList<Integer> c = new ArrayList<>();
	}
	static int N,M;
	static Node[] node;
	static int[] minB;
	static long dist[][];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		N = sc.nextInt();
		M = sc.nextInt();
		node = new Node[N];
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
		
//		dist = new long[N][150];
//		for(int i=0; i<N; i++)
//			Arrays.fill(dist[i], Long.MAX_VALUE);
//		func1();
		long[] ans = new long[N];
		Arrays.fill(ans, Long.MAX_VALUE);
		ans[0] = 0;
		ArrayList<PriorityQueue<Long>> q = new ArrayList<>();
		for(int i=0; i<N; i++)
			q.add(new PriorityQueue<Long>());
		q.get(0).add(0l);
		for(int i=0; i<N; i++) {
			while(q.get(i).size()>0) {
				Long cur = q.get(i).poll();
				long cost = cur>>14;
				int town = (int)(cur&((1<<14)-1));
				if(ans[town]<cost)
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
	
	static void func1() {
		PriorityQueue<Long> q = new PriorityQueue<>();
		boolean[] visited = new boolean[N];
		minB = new int[N];
		q.add(0l);
		
		while(q.size()>0) {
			Long cur = q.poll();
			long cost = cur/N;
			int town = (int)(cur%N);
			
			if(visited[town])
				continue;
			visited[town] = true;
			minB[town] = (int)cost;
			
			for(int i=0; i<node[town].e.size(); i++) {
				int next = node[town].e.get(i);
				int c = node[town].c.get(i);
				if(!visited[next])
					q.add((cost + c)*N + next);
			}
		}
	}
	
	static long[] func2() {
		PriorityQueue<Long> q = new PriorityQueue<>();
		boolean[][] visited = new boolean[N][150];
		q.add(0l);
		int L1 = 8, L2 = 14;
		long mask1 = (1l<<L1)-1;
		long mask2 = ((1l<<L2)-1)<<L1;
		
		long[] ans = new long[N];
		Arrays.fill(ans, Long.MAX_VALUE);
		int solved = 0;
		
		while(q.size()>0) {
			Long cur = q.poll();
			long cost = cur>>(L1+L2);
			int town = (int)((cur&mask2)>>L1);
			int bi = (int)(cur&mask1);
			if(visited[town][bi])
				continue;
			visited[town][bi] = true;
			
			dist[town][bi] = cost;
			if(ans[town]==Long.MAX_VALUE)
				solved++;
			ans[town] = Math.min(ans[town], cost);
			if(solved==N)
				break;
			
			for(int i=0; i<node[town].e.size(); i++) {
				int next = node[town].e.get(i);
				int c = node[town].c.get(i);

				int used = bi + minB[town] + c;
				if(used-minB[next] >= 150 || visited[next][used-minB[next]])
					continue;
				
				q.add(((cost + (c==0 ? 1 : used))<<(L1+L2)) + (next<<L1) + used-minB[next]);
			}
		}
		
		return ans;
	}
}