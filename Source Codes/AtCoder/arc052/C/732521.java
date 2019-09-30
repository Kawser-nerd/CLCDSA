import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {
	static class edge{
		int p;
		int type;
		
		public edge(int p, int type){
			this.p = p;
			this.type = type;
		}
	}
	static class state{
		int p;
		int cb;
		int time;
		
		public state(int p, int cb, int time){
			this.p = p;
			this.cb = cb;
			this.time = time;
		}
	}
	static int[] dis;
	static boolean[] flag;
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<edge>[] v = new ArrayList[n];
		dis = new int[n];
		flag = new boolean[n];
		Arrays.fill(dis, Integer.MAX_VALUE);
		for (int i = 0; i < n; i++){
			v[i] = new ArrayList<edge>();
		}
		for (int i = 0; i < m; i++){
			int c = in.nextInt();
			int a = in.nextInt();
			int b = in.nextInt();
			v[a].add(new edge(b,c));
			v[b].add(new edge(a,c));
		}
		in.close();
		PriorityQueue<state> pq = new PriorityQueue<>(new Comparator<state>() {
			@Override
			public int compare(state o1, state o2) {
				if (o1.cb == o2.cb) {
					return o1.time - o2.time;
				} else {
					return o1.cb - o2.cb;
				}
			}
		});
		pq.add(new state(0,0,0));
		while (!pq.isEmpty()) {
			state p = pq.poll();
			if (p.time > dis[p.p]) continue;
			dis[p.p] = p.time;
			for (edge e : v[p.p]){
				if (e.type == 1){
					if (p.time + p.cb + 1 < dis[e.p]){
						pq.add(new state(e.p,p.cb + 1,p.time + p.cb + 1));
					}
				} else {
					if (p.time + 1 < dis[e.p]){
						pq.add(new state(e.p, p.cb, p.time + 1));
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++){
			sb.append(dis[i] + "\n");
		}
		System.out.println(sb.toString());
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.