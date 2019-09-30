import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
	public static void main(String[] args) {
		IO io = new IO();
		int q = io.nextInt();
		TreapSet<Integer> ts = new TreapSet<>(Integer::compare);
		for(int qq=0;qq<q;qq++) {
			int t = io.nextInt();
			int x = io.nextInt();
			if (t == 1) {
				ts.add(x);
			}else{
				Integer y = ts.kthLowest(x - 1);
				ts.remove(y);
				io.println(y);
			}
//			System.out.println(ts);
		}
		io.flush();
	}
}
class TreapSet<E> {
	private Node<E> root = null;
	private final Comparator<E> comparator;
	private int rnd = new Random().nextInt();
	private int modCount = 0;
	
	public TreapSet(Comparator<E> comparator) {
		this.comparator = comparator;
	}
	
	private int nextRnd() {
		rnd = rnd ^ rnd << 13;
		rnd = rnd ^ rnd >> 17;
		return rnd = rnd ^ rnd << 5;
	}
	
	private Node<E> rotateLeft(Node<E> x) {
		Node<E> y = x.right;
		x.right = y.left;
		y.left = x;
		Node.update(x);
		Node.update(y);
		return y;
	}
	
	private Node<E> rotateRight(Node<E> x) {
		Node<E> y = x.left;
		x.left = y.right;
		y.right = x;
		Node.update(x);
		Node.update(y);
		return y;
	}
	
	private Node<E> insert(Node<E> x, E value, int pri) {
		if (x == null) {
			modCount++;
			Node<E> y = new Node<>(value, pri);
			Node.update(y);
			return y;
		}
		int cmp = comparator.compare(value, x.value);
		if (cmp < 0) {
			x.left = insert(x.left, value, pri);
			Node.update(x);
			if (x.priority < x.left.priority) {
				return rotateRight(x);
			}
			return x;
		}else if(cmp > 0) {
			x.right = insert(x.right, value, pri);
			Node.update(x);
			if (x.priority < x.right.priority) {
				return rotateLeft(x);
			}
			return x;
		}else{
			return x;
		}
	}
	
	private Node<E> erase(Node<E> x, E value) {
		if (x == null) {
			return x;
		}
		int cmp = comparator.compare(value, x.value);
		if (cmp < 0) {
			x.left = erase(x.left, value);
			Node.update(x);
			return x;
		}else if(cmp > 0) {
			x.right = erase(x.right, value);
			Node.update(x);
			return x;
		}else{
			if (x.left == null || x.right == null) {
				modCount++;
				if (x.left == null) {
					return x.right;
				}else{
					return x.left;
				}
			}else{
				if (x.left.priority < x.right.priority) {
					x = rotateRight(x);
					x.right = erase(x.right, value);
					Node.update(x);
					return x;
				}else{
					x = rotateLeft(x);
					x.left = erase(x.left, value);
					Node.update(x);
					return x;
				}
			}
		}
	}
	
	public int size() {
		return Node.size(root);
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public boolean add(E value) {
		int priority = nextRnd();
		int mc = modCount;
		root = insert(root, value, priority);
		return mc + 1 == modCount;
	}
	
	public boolean addAll(Collection<? extends E> c) {
		boolean change = false;
		for(E e: c) {
			change |= add(e);
		}
		return change;
	}
	
	public void clear() {
		root = null;
	}
	
	public boolean remove(E value) {
		int mc = modCount;
		root = erase(root, value);
		return mc + 1 == modCount;
	}
	
	public E lowest() {
		if (root == null) return null;
		Node<E> x = root;
		while(x.left != null) {
			x = x.left;
		}
		return x.value;
	}
	
	public E highest() {
		if (root == null) return null;
		Node<E> x = root;
		while(x.right != null) {
			x = x.right;
		}
		return x.value;
	}
	
	public E lower(E value) {
		Node<E> x = root;
		E res = null;
		while(x != null) {
			int cmp = comparator.compare(value, x.value);
			if (cmp <= 0) {
				x = x.left;
			}else{
				res = x.value;
				x = x.right;
			}
		}
		return res;
	}
	
	public E floor(E value) {
		Node<E> x = root;
		E res = null;
		while(x != null) {
			int cmp = comparator.compare(value, x.value);
			if (cmp < 0) {
				x = x.left;
			}else if(cmp > 0) {
				res = x.value;
				x = x.right;
			}else{
				return x.value;
			}
		}
		return res;
	}
	
	public E find(E value) {
		Node<E> x = root;
		while(x != null) {
			int cmp = comparator.compare(value, x.value);
			if (cmp < 0) {
				x = x.left;
			}else if(cmp > 0) {
				x = x.right;
			}else{
				return x.value;
			}
		}
		return null;
	}
	
	public boolean contains(E value) {
		return find(value) != null;
	}
	
	public E ceil(E value) {
		Node<E> x = root;
		E res = null;
		while(x != null) {
			int cmp = comparator.compare(value, x.value);
			if (cmp < 0) {
				res = x.value;
				x = x.left;
			}else if(cmp > 0) {
				x = x.right;
			}else{
				return x.value;
			}
		}
		return res;
	}
	
	public E higher(E value) {
		Node<E> x = root;
		E res = null;
		while(x != null) {
			int cmp = comparator.compare(value, x.value);
			if (cmp >= 0) {
				x = x.right;
			}else{
				res = x.value;
				x = x.left;
			}
		}
		return res;
	}
	
	public E pollLowest() {
		if (root == null) return null;
		Node<E> x = root;
		Node<E> y = null;
		while(x.left != null) {
			y = x;
			x = x.left;
		}
		E res = x.value;
		if (x == root) {
			root = erase(root, res);
		}else{
			y.left = erase(y.left, res);
		}
		return res;
	}
	
	public E pollHighest() {
		if (root == null) return null;
		Node<E> x = root;
		Node<E> y = null;
		while(x.right != null) {
			y = x;
			x = x.right;
		}
		E res = x.value;
		if (x == root) {
			root = erase(root, res);
		}else{
			y.right = erase(y.right, res);
		}
		return res;
	}
	
	//0-indexed
	public E kthLowest(int k) {
		if (k < 0 || Node.size(root) <= k) {
			return null;
		}
		Node<E> x = root;
		while(x != null) {
			int sizeLeft = Node.size(x.left);
			if (sizeLeft < k) {
				k -= sizeLeft + 1;
				x = x.right;
			}else if(sizeLeft > k) {
				x = x.left;
			}else{
				return x.value;
			}
		}
		throw new RuntimeException("?????");
	}
	
	public E kthHighest(int k) {
		if (k < 0 || Node.size(root) <= k) {
			return null;
		}
		Node<E> x = root;
		while(x != null) {
			int sizeRight = Node.size(x.right);
			if (sizeRight < k) {
				k -= sizeRight + 1;
				x = x.left;
			}else if(sizeRight > k) {
				x = x.right;
			}else{
				return x.value;
			}
		}
		return null;
	}
	
	private void toListDFS(Node<E> x, ArrayList<E> al) {
		if (x == null) return;
		toListDFS(x.left, al);
		al.add(x.value);
		toListDFS(x.right, al);
	}
	
	public ArrayList<E> toList() {
		ArrayList<E> res = new ArrayList<>();
		toListDFS(root, res);
		return res;
	}
	
	public String toString() {
		return toList().toString();
	}
	
	static class Node<E> {
		E value;
		Node<E> left,right;
		int priority;
		int size;
		
		public Node(E value, int priority) {
			this.value = value;
			this.priority = priority;
			this.size = 1;
		}

		private static <E> int size(Node<E> node) {
			return node == null ? 0 : node.size;
		}
		
		private static <E> Node<E> update(Node<E> node) {
			if (node == null) return null;
			node.size = size(node.left) + size(node.right) + 1;
			return node;
		}
	}
}
class IO extends PrintWriter {
	private final InputStream in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;
	
	public IO() { this(System.in);}
	public IO(InputStream source) { super(System.out); this.in = source;}
	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		}else{
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
	private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
	private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
	private static boolean isNewLine(int c) { return c == '\n' || c == '\r';}
	public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
	public boolean hasNextLine() { while(hasNextByte() && isNewLine(buffer[ptr])) ptr++; return hasNextByte();}
	public String next() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public char[] nextCharArray(int len) {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		char[] s = new char[len];
		int i = 0;
		int b = readByte();
		while(isPrintableChar(b)) {
			if (i == len) {
				throw new InputMismatchException();
			}
			s[i++] = (char) b;
			b = readByte();
		}
		return s;
	}
	public String nextLine() {
		if (!hasNextLine()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(!isNewLine(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public long nextLong() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
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
		while(true){
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			}else if(b == -1 || !isPrintableChar(b)){
				return minus ? -n : n;
			}else{
				throw new NumberFormatException();
			}
			b = readByte();
		}
	}
	public int nextInt() {
		long nl = nextLong();
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
			throw new NumberFormatException();
		}
		return (int) nl;
	}
	public char nextChar() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		return (char) readByte();
	}
	public double nextDouble() { return Double.parseDouble(next());}
	public int[] nextIntArray(int n) { int[] a = new int[n]; for(int i=0;i<n;i++) a[i] = nextInt(); return a;}
	public long[] nextLongArray(int n) { long[] a = new long[n]; for(int i=0;i<n;i++) a[i] = nextLong(); return a;}
	public double[] nextDoubleArray(int n) { double[] a = new double[n]; for(int i=0;i<n;i++) a[i] = nextDouble(); return a;}
	public void nextIntArrays(int[]... a) { for(int i=0;i<a[0].length;i++) for(int j=0;j<a.length;j++) a[j][i] = nextInt();}
	public int[][] nextIntMatrix(int n,int m) { int[][] a = new int[n][]; for(int i=0;i<n;i++) a[i] = nextIntArray(m); return a;}
	public char[][] nextCharMap(int n,int m) { char[][] a = new char[n][]; for(int i=0;i<n;i++) a[i] = nextCharArray(m); return a;}
	public void close() { super.close(); try {in.close();} catch (IOException e) {}}
}