import java.util.*;

public class Main {
	static ArrayList<HashMap<Integer, Long>> list = new ArrayList<HashMap<Integer, Long>>();
	static long maze_cnt[];
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int a[] = new int[N];
		int b[] = new int[N];
		long c[] = new long[N];
		
		for(int i = 0; i < N; i++) {
			HashMap<Integer, Long> map = new HashMap<Integer, Long>();
			list.add(map);
		}
		
		for(int i = 0; i < N - 1; i++) {
			a[i] = sc.nextInt() - 1;
			b[i] = sc.nextInt() - 1;
			c[i] = (long)sc.nextInt();
			list.get(a[i]).put(b[i], c[i]);
			list.get(b[i]).put(a[i], c[i]);
		}
		
		int Q = sc.nextInt();
		int K = sc.nextInt() - 1;
		int x[] = new int[Q];
		int y[] = new int[Q];
		for(int i = 0; i < Q; i++) {
			x[i] = sc.nextInt() - 1;
			y[i] = sc.nextInt() - 1;
		}
		
		DFS(list, K);
		
		for(int i = 0; i < Q; i++) {
			System.out.println(maze_cnt[x[i]] + maze_cnt[y[i]]);
		}
	}
	
public static void DFS(ArrayList<HashMap<Integer, Long>> list, int now) {
		
		Deque<Integer> stack = new ArrayDeque<Integer>();
		stack.push(now);
		
		maze_cnt = new long[list.size()];
		boolean flag[] = new boolean[list.size()];
		
		for(int i = 0; i < list.size(); i++) {
			maze_cnt[i] = Long.MAX_VALUE;
			flag[i] = false;
		}
		flag[now] = true;
		
		maze_cnt[now] = 0;
		
		while(stack.size() != 0) {
			now = stack.poll();
			for(int key : list.get(now).keySet()) {
				if(maze_cnt[key] > maze_cnt[now] + list.get(now).get(key) && !flag[key]) {
					stack.push(key);
					maze_cnt[key] = maze_cnt[now] + list.get(now).get(key);
					flag[key] = true;
				}
			}
		}
	}
}