import java.util.ArrayList;
import java.util.Scanner;

public class A {
	static Scanner sc = new Scanner(System.in);
	static int N, D;
	static Node[] nodes;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			int ans = solve();
			System.out.printf("Case #%d: %s\n", i, ans);
		}
	}

	static int solve() {
		N = sc.nextInt();
		D = sc.nextInt();
		int S = sc.nextInt();
		int AS = sc.nextInt();
		int CS = sc.nextInt();
		int RS = sc.nextInt();
		int M = sc.nextInt();
		int AM = sc.nextInt();
		int CM = sc.nextInt();
		int RM = sc.nextInt();
		nodes = new Node[N];
		for (int i = 0; i < N; ++i) {
			nodes[i] = new Node(S);
			if (i != 0) {
				nodes[M % i].children.add(nodes[i]);
			}
			S = (int) ((long) S * AS + CS) % RS;
			M = (int) ((long) M * AM + CM) % RM;
		}
		nodes[0].calc();

		int ans = Integer.MAX_VALUE;
		for (int i = 0; i <= RS; ++i) {
			ans = Math.min(ans, nodes[0].dp[i]);
		}

		return N - ans;
	}

	static class Node {
		ArrayList<Node> children = new ArrayList<>();
		int salary;
		int size;
		int[] dp;

		Node(int s) {
			this.salary = s;
			dp = new int[1001];
		}

		void calc() {
			this.size = 1;
			for (Node c : children) {
				c.calc();
				this.size += c.size;
			}
			for (int i = 0; i <= 1000; ++i) {
				if (this.salary < i || i + D < this.salary) {
					dp[i] = this.size;
				} else {
					for (Node c : children) {
						dp[i] += c.dp[i];
					}
				}
			}

		}
	}

}
