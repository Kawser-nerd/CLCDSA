import java.util.*;

public class Main {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<Integer>[] graph = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			graph[a].add(b);
			graph[b].add(a);
		}
		HashSet<Integer> set = new HashSet<>();
		ArrayList<Integer> list = new ArrayList<>();
		int idx = 1;
		boolean flag = false;
		list.add(idx);
		set.add(idx);
		while (!flag) {
			flag = true;
			for (int x : graph[idx]) {
				if (!set.contains(x)) {
					flag = false;
					idx = x;
					list.add(idx);
					set.add(idx);
					break;
				}
			}
		}
		flag = false;
		idx = 1;
		while (!flag) {
			flag = true;
			for (int x : graph[idx]) {
				if (!set.contains(x)) {
					flag = false;
					idx = x;
					list.add(0, idx);
					set.add(idx);
					break;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(list.size()).append("\n");
		for (int i = 0; i < list.size(); i++) {
			if (i != 0) {
				sb.append(" ");
			}
			sb.append(list.get(i));
		}
		System.out.println(sb);
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.