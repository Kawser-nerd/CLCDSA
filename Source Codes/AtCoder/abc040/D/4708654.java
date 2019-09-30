import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		UnionFindTree uft = new UnionFindTree(n);
		Bridge[] bridges = new Bridge[m];
		for (int i = 0; i < m; i++) {
			bridges[i] = new Bridge(sc.nextInt(), sc.nextInt(), sc.nextInt());
		}
		// ??????????
		Arrays.sort(bridges, new Comparator<Bridge>() {
		public int compare(Bridge b1, Bridge b2) {
			return b2.y - b1.y;
		}
		});
		int q = sc.nextInt();
		int[] ans = new int[q];
		Question[] questions = new Question[q];
		for (int i = 0; i < q; i++) {
			questions[i] = new Question(sc.nextInt(), sc.nextInt(), i);
		}
		// ??????????
		Arrays.sort(questions, new Comparator<Question>() {
		public int compare(Question q1, Question q2) {
			return q2.y - q1.y;
		}
		});
		int idx = 0;
		for (int i = 0; i < q; i++) {
			for (int j = idx; j < m && bridges[j].y > questions[i].y; j++) {
				idx = j;
				uft.union(bridges[idx].a - 1, bridges[idx].b - 1);
			}
			ans[questions[i].idx] = uft.count(questions[i].v - 1);
		}
		StringBuilder sb = new StringBuilder();
		for (int x : ans) {
			sb.append(x).append("\n");
		}
		System.out.print(sb);
	}
	
	static class Bridge {
		int a;
		int b;
		int y;
		public Bridge(int a, int b, int y) {
			this.a = a;
			this.b = b;
			this.y = y;
		}
	}
	
	static class Question {
		int v;
		int y;
		int idx;
		public Question(int v, int y, int idx) {
			this.v = v;
			this.y = y;
			this.idx = idx;
		}
	}

	static class UnionFindTree {
		int[] parent;
		int[] count;
		
		public UnionFindTree(int size) {
			parent = new int[size];
			count = new int[size];
			for (int i = 0; i < size; i++) {
				parent[i] = i;
				count[i] = 1;
			}
		}
		
		public int find(int x) {
			if (parent[x] == x) {
				return x;
			} else {
				int v = find(parent[x]);
				parent[x] = v;
				return v;
			}
		}
		
		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
		
		public void union(int x, int y) {
			int rootX = find(x);
			int rootY = find(y);
			if (rootX == rootY) {
				return;
			}
			parent[rootX] = rootY;
			parent[x] = rootY;
			count[rootY] += count[rootX];
		}
		
		public int count(int x) {
			return count[find(x)];
		}
	}

}