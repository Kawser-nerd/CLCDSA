import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner();
		TreeSet<Integer> ts = new TreeSet<>();
		AVLTree avl = new AVLTree();
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] x = new int[n];
		int[] ref = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextInt();
			--x[i];
			ref[x[i]] = i;
		}
		AVLTree.Node node;
		for (int i = 0; i < n; ++i) {
			avl.insert(x[i]);
			if (i < k - 1)
				continue;
			node = avl.kth(k);
			pw.println(ref[(int) node.key] + 1);
		}
		pw.close();
	}

	/*
	 * ????????????
	 */
	public static class AVLTree {
		Node root = null;

		class Node {
			long key;
			int height;
			int balance;
			int sz = 1;
			Node left = null;
			Node right = null;
			Node parent = null;

			public Node(long key_, Node parent_) {
				key = key_;
				parent = parent_;
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

		boolean delete(int delKey) {
			if (root == null)
				return false;
			Node node = root;
			while (node != null) {
				if (delKey == node.key) {
					delete(node);
					return true;
				}
				node = delKey >= node.key ? node.right : node.left;
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
				reheight(n);
				n.balance = height(n.right) - height(n.left);
				n.sz = 1 + sz(n.left) + sz(n.right);
			}
		}

		int sz(Node node) {
			return node != null ? node.sz : 0;
		}

		int height(Node node) {
			return node != null ? node.height : -1;
		}

		void reheight(Node node) {
			if (node != null) {
				node.height = 1 + Math.max(height(node.right), height(node.left));
			}
		}

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

	class Scanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[ptr++];
			else
				return -1;
		}

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		private void skipUnprintable() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr]))
				ptr++;
		}

		public boolean hasNext() {
			skipUnprintable();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while (true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}

		public int nextInt() {
			return (int) nextLong();
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}