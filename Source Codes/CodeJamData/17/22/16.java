package r1b2017;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int n = in.nextInt();
			int a = in.nextInt(); // R
			int d = in.nextInt(); // O
			int b = in.nextInt(); // Y
			int e = in.nextInt(); // G
			int c = in.nextInt(); // B
			int f = in.nextInt(); // V
			
			if (a + e == n) {
				if (a != e) {
					out.println("IMPOSSIBLE");
					continue;
				}
				for (int i = 0; i < a; i++) {
					out.print("RG");
				}
				out.println();
				continue;
			}
			
			if (b + f == n) {
				if (b != f) {
					out.println("IMPOSSIBLE");
					continue;
				}
				for (int i = 0; i < b; i++) {
					out.print("YV");
				}
				out.println();
				continue;
			}
			
			if (c + d == n) {
				if (c != d) {
					out.println("IMPOSSIBLE");
					continue;
				}
				for (int i = 0; i < c; i++) {
					out.print("BO");
				}
				out.println();
				continue;
			}
			
			if (d > 0) {
				if (c < d+1) {
					out.println("IMPOSSIBLE");
					continue;
				}
				c -= d;
			}
			
			if (e > 0) {
				if (a < e+1) {
					out.println("IMPOSSIBLE");
					continue;
				}
				a -= e;
			}
			
			if (f > 0) {
				if (b < f+1) {
					out.println("IMPOSSIBLE");
					continue;
				}
				b -= f;
			}
			
			n = a + b + c;
			if (a > n/2 || b > n/2 || c > n/2) {
				out.println("IMPOSSIBLE");
				continue;
			}
			
			Node[] nodes = new Node[3];
			nodes[0] = new Node(a, 'R');
			nodes[1] = new Node(b, 'Y');
			nodes[2] = new Node(c, 'B');
			Arrays.sort(nodes, new Comparator<Node>() {
				public int compare(Node a, Node b) {
					return b.cnt - a.cnt;
				}
			});
			
			char[] ans = new char[n];
			char prev = (char)0;
			for (int i = 0; i < n; i++) {
				int max = 0;
				int maxI = -1;
				for (int j = 0; j < nodes.length; j++) {
					if (nodes[j].cnt > max && nodes[j].c != prev) {
						max = nodes[j].cnt;
						maxI = j;
					}
				}
				ans[i] = nodes[maxI].c;
				nodes[maxI].cnt--;
				prev = ans[i];
			}
			
			for (char aa : ans) {
				if (d > 0 && aa == 'B') {
					for (int i = 0; i < d; i++) {
						out.print("BO");
					}
					d = 0;
				}
				if (e > 0 && aa == 'R') {
					for (int i = 0; i < e; i++) {
						out.print("RG");
					}
					e = 0;
				}
				if (f > 0 && aa == 'Y') {
					for (int i = 0; i < f; i++) {
						out.print("YV");
					}
					f = 0;
				}
				out.print(aa);
			}
			out.println();
		}

		out.flush();
	}

	static class Node {
		int cnt;
		char c;
		
		Node(int cnt, char c) {
			this.cnt = cnt;
			this.c = c;
		}
	}
}
