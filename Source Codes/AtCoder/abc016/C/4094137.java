import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		HashSet<Integer>[] sets = new HashSet[n + 1];
		for (int i = 1; i <= n; i++) {
			sets[i] = new HashSet<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			sets[a].add(b);
			sets[b].add(a);
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) {
			HashSet<Integer> set = new HashSet<>();
			for (int x : sets[i]) {
				for (int t : sets[x]) {
					if (t != i && !sets[i].contains(t)) {
						set.add(t);
					}
				}
			}
			sb.append(set.size()).append("\n");
		}
		System.out.print(sb);
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.