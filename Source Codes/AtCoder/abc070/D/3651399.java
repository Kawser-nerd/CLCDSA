import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		Map<Integer,List<int[]>> tree = new HashMap<>();
		for(int i=0;i<n-1;i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();
			int[] tmp1 = {b,c};
			int[] tmp2 = {a,c};
			if(tree.containsKey(a)) {
				tree.get(a).add(tmp1);
			}else {
				List<int[]> list = new ArrayList<>();
				list.add(tmp1);
				tree.put(a, list);
			}
			if(tree.containsKey(b)) {
				tree.get(b).add(tmp2);
			}else {
				List<int[]> list = new ArrayList<>();
				list.add(tmp2);
				tree.put(b, list);
			}
		}
		int Q = in.nextInt();
		int K = in.nextInt();
		long[] cost = new long[n+1];
		Queue<Integer> que = new ArrayDeque<>();
		que.add(K);
		while(!que.isEmpty()) {
			int node = que.poll();
			for(int[] tmp:tree.get(node)) {
				if(cost[tmp[0]]==0) {
					cost[tmp[0]] = cost[node] + tmp[1];
					que.add(tmp[0]);
				}
			}
			if(cost[K]==0) cost[K] = -1;
		}
		StringBuilder sb = new StringBuilder();
		String ls = System.lineSeparator();
		for(int i=0;i<Q;i++) {
			sb.append(cost[in.nextInt()]+cost[in.nextInt()]);
			sb.append(ls);
		}
		System.out.println(sb.toString());
		in.close();

	}

}