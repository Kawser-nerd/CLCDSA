import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

class Main {

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		L = sc.nextLong();
		String[] s = new String[n];
		Tree tree = new Tree();
		for (int i = 0; i < n; ++i) {
			s[i] = sc.next();
			tree.set(s[i]);
		}
		tree.dfs(tree.root);
		if (grundy == 0) {
			System.out.println("Bob");
		} else {
			System.out.println("Alice");
		}
	}

	long grundy = 0;
	long L;

	class Tree {
		Node root = new Node();

		void set(String s) {
			Node cur = root;
			for (int i = 0; i < s.length(); ++i) {
				if (s.charAt(i) == '0') {
					cur.appendLeft();
					cur = cur.left;
				} else if (s.charAt(i) == '1') {
					cur.appendRight();
					cur = cur.right;
				}
			}
			cur.hit();
		}

		void dfs(Node cur) {
			if (cur.hit > 0)
				return;
			if (cur.left != null)
				dfs(cur.left);
			else {
				grundy ^= (L - cur.depth) & -(L - cur.depth);
			}
			if (cur.right != null) {
				dfs(cur.right);
			} else {
				grundy ^= (L - cur.depth) & -(L - cur.depth);
			}
		}

		class Node {
			Node right = null;
			Node left = null;
			int hit = 0;
			int depth = 0;

			void appendLeft() {
				if (left == null) {
					left = new Node();
					left.depth = depth + 1;
				}
			}

			void appendRight() {
				if (right == null) {
					right = new Node();
					right.depth = depth + 1;
				}
			}

			void hit() {
				++hit;
			}
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
}