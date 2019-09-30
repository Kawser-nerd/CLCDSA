import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
 
public class Main {
	static ArrayList<Integer>[] g;
	static int n;
	static int[] deg;
 
	public static void main(String[] args) {
 
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		g = new ArrayList[n];
		deg = new int[n];
		for (int i = 0; i < n; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; ++i) {
			int a = sc.nextInt() - 1;
			g[a].add(i);
			g[i].add(a);
		}
		dfs(0, -1);
		System.out.println(deg[0]);
	}
 
	static void dfs(int cur, int par) {
		if(cur!=0&&g[cur].size()==1){
			deg[cur]=0;
			return;
		}else if(g[cur].size()==0){
			deg[cur]=0;
			return;
		}
		ArrayList<Integer> v = new ArrayList<>();
		for (int dst : g[cur]) {
			if (dst == par)
				continue;
			dfs(dst, cur);
			v.add(deg[dst]);
		}
		Collections.sort(v, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return -Integer.compare(o1, o2);
			}
		});
		int max = 0;
		for (int i = 0; i < v.size(); ++i) {
			max = Math.max(max, i + v.get(i));
		}
		deg[cur] = max + 1;
	}
 
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.