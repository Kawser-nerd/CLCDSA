import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] p = new int[n][2];
		int[][] q = new int[m][2];
		for (int i = 0; i < n; ++i) {
			p[i][0] = sc.nextInt();
			p[i][1] = sc.nextInt();
		}
		Arrays.sort(p, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if (o1[0] != o2[0]) {
					return Integer.compare(o1[0], o2[0]);
				} else {
					return -Integer.compare(o1[1], o2[1]);
				}
			}
		});
		for (int i = 0; i < m; ++i) {
			q[i][1] = sc.nextInt();
			q[i][0] = sc.nextInt();
		}
		Arrays.sort(q, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if (o1[0] != o2[0]) {
					return Integer.compare(o1[0], o2[0]);
				} else {
					return -Integer.compare(o1[1], o2[1]);
				}
			}
		});

		int ans = 0;

		AVLTree tree = new AVLTree();
		HashMap<Integer, Integer> map = new HashMap<>();
		int j = 0;
		for (int i = 0; i < n; ++i) {
			while (j < m && p[i][0] >= q[j][0]) {
				int c = 1;
				while (j + 1 < m && q[j][0] == q[j + 1][0] && q[j][1] == q[j + 1][1]) {
					++j;
					++c;
				}
				if (map.containsKey(q[j][1])) {
					c += map.get(q[j][1]);
				}
				map.put(q[j][1], c);
				tree.insert(q[j][1]);
				++j;
			}

			AVLTree.Node node = tree.ceiling(p[i][1]);
			if (node == null)
				continue;
			int c = map.get((int) node.key);
			++ans;
			--c;
			if (c > 0)
				map.put((int) node.key, c);
			else {
				map.remove((int) node.key);
				tree.delete(node.key);
			}
		}
		System.out.println(ans);
	}

	public static class AVLTree {
		Node root = null;

		Node ceiling(long v) {
			Node node = root;
			while (node != null) {
				if (max(node.left) >= v) {
					node = node.left;
				} else if (node.key >= v)
					return node;
				else
					node = node.right;
			}
			return node;
		}

		class Node {
			long key;
			long max;
			int height;
			int balance;
			int sz = 1;
			Node left = null;
			Node right = null;
			Node parent = null;

			public Node(long key_, Node parent_) {
				key = key_;
				parent = parent_;
				max = key_;
			}
		}

		Node kth(int k) {
			Node node = root;
			int sum = 0;
			while (node != null) {
				if (sum + node.sz < k) {
					return null;
				}
				if (sum + sz(node.left) + 1 == k) {
					return node;
				}
				if (sum + sz(node.left) + 1 < k) {
					sum = sum + 1 + sz(node.left);
					node = node.right;
				} else {
					node = node.left;
				}
			}
			return null;
		}

		boolean contain(int delKey) {
			if (root == null)
				return false;
			Node node = root;
			while (node != null) {
				if (delKey == node.key) {
					return true;
				}
				node = delKey >= node.key ? node.right : node.left;
			}
			return false;
		}

		boolean delete(long key) {
			if (root == null)
				return false;
			Node node = root;
			while (node != null) {
				if (key == node.key) {
					delete(node);
					return true;
				}
				node = key >= node.key ? node.right : node.left;
			}
			return false;
		}

		void delete(Node node) {
			if (node.left == null && node.right == null) {
				if (node.parent == null) {
					root = null;
					return;
				}
				Node parent = node.parent;
				if (parent.left == node)
					parent.left = null;
				else
					parent.right = null;
				rebalance(parent);
			}
			if (node.left != null) {
				Node child = node.left;
				while (child.right != null) {
					child = child.right;
				}
				node.key = child.key;
				delete(child);
			} else if (node.right != null) {
				Node child = node.right;
				while (child.left != null) {
					child = child.left;
				}
				node.key = child.key;
				delete(child);
			}
		}

		boolean insert(long key) {
			if (root == null) {
				root = new Node(key, null);
				return true;
			}
			Node cur = root;
			Node parent = null;
			while (true) {
				if (cur.key == key) {
					return false;
				}
				parent = cur;
				boolean goLeft = key < cur.key;
				cur = goLeft ? cur.left : cur.right;
				if (cur == null) {
					if (goLeft) {
						parent.left = new Node(key, parent);
					} else {
						parent.right = new Node(key, parent);
					}
					rebalance(parent);
					break;
				}

			}
			return true;
		}

		void rebalance(Node n) {
			setBalance(n);
			if (n.balance == -2) {
				if (height(n.left.left) >= height(n.left.right)) {
					n = rotateRight(n);
				} else {
					n = rotateLeftThenRight(n);
				}
			} else if (n.balance == 2) {
				if (height(n.right.right) >= height(n.right.left)) {
					n = rotateLeft(n);
				} else {
					n = rotateRightThenLeft(n);
				}
			}
			if (n.parent != null) {
				rebalance(n.parent);
			} else {
				root = n;
			}
		}

		void setBalance(Node... nodes) {
			for (Node n : nodes) {
				// reheight(n);
				n.height = 1 + Math.max(height(n.right), height(n.left));
				n.balance = height(n.right) - height(n.left);
				n.sz = 1 + sz(n.left) + sz(n.right);
				n.max = Math.max(n != null ? n.key : -Integer.MAX_VALUE, Math.max(max(n.left), max(n.right)));
			}
		}

		int sz(Node node) {
			return node != null ? node.sz : 0;
		}

		int height(Node node) {
			return node != null ? node.height : -1;
		}

		long max(Node node) {
			return node != null ? node.max : -Long.MAX_VALUE;
		}

		// void reheight(Node node) {
		// if (node != null) {
		// node.height = 1 + Math.max(height(node.right), height(node.left));
		// }
		// }

		Node rotateRight(Node a) {
			Node b = a.left;
			if (a.parent != null) {
				if (a.parent.left == a) {
					a.parent.left = b;
				} else {
					a.parent.right = b;
				}
			}
			b.parent = a.parent;
			a.parent = b;
			a.left = b.right;
			b.right = a;
			if (a.left != null)
				a.left.parent = a;
			setBalance(a, b);
			return b;
		}

		Node rotateLeft(Node a) {
			Node b = a.right;
			if (a.parent != null) {
				if (a.parent.right == a) {
					a.parent.right = b;
				} else {
					a.parent.left = b;
				}
			}
			b.parent = a.parent;
			a.parent = b;
			a.right = b.left;
			b.left = a;
			if (a.right != null)
				a.right.parent = a;
			setBalance(a, b);
			return b;
		}

		Node rotateLeftThenRight(Node n) {
			n.left = rotateLeft(n.left);
			return rotateRight(n);
		}

		Node rotateRightThenLeft(Node n) {
			n.right = rotateRight(n.right);
			return rotateLeft(n);
		}

		void inOrder(Node cur) {
			if (cur == null)
				return;
			inOrder(cur.left);
			System.out.println(cur.key);
			inOrder(cur.right);
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}