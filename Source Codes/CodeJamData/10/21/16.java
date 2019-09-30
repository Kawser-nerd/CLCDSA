import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;
public class A  extends AbstractCodeJamSolver {
	
	
	Set<String> dirs;
	int n;
	int m;
	
	void putdir(String dir) {
		for(int i=1;i<=dir.length();i++)
			if(i==dir.length() || dir.charAt(i) == '/')
				dirs.insert(dir.substring(0, i));
	}	
		
	public void solve() {
		int casen = in.nextInt();
		for(int casei=1;casei<=casen;casei++) {
			
			n = in.nextInt();
			m = in.nextInt();

			dirs = new RedBlackTreeSet<String>();
			
			for(int i=0;i<n;i++)
				putdir(in.next());
			int presize = dirs.size();
			
			for(int i=0;i<m;i++)
				putdir(in.next());	
			
			out.println("Case #" + casei + ": " + (dirs.size() - presize));
		}		
	}
	
	
	
	static public void main(String[] args) throws IOException {
		new A().launch("A.txt");
	}
}
abstract class AbstractCodeJamSolver {
	
	protected Scanner in;
	protected PrintStream out = System.out;

	abstract public void solve(); 
	
	protected void print(Object o) {
		out.print(o);
	}
	
	protected void println() {
		out.println();
	}
	
	protected void println(Object o) {
		out.println(o);
	}
	
	protected void printf(String f, Object... o) {
		out.format(f, o);
	}


	final public void launch(String inputFileName) throws FileNotFoundException {
		in = new Scanner(new File(inputFileName));
		solve();
	}
}

interface Set<T> extends Container<T> {
	
	void clear();
	void insert(T v);
	void insertAll(Iterable<T> a);
	boolean contains(T v);
	void remove(T v);
}
interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}
class RedBlackTreeSet<T> extends AbstractBinarySearchTreeSet<T, RedBlackTreeNode<T>, RedBlackTree<T>> {

	public RedBlackTreeSet(Comparator<T> comp) {
		super(comp);
	}
	
	public RedBlackTreeSet() {
		super(new DefaultComparator<T>());
	}
	
	protected RedBlackTree<T> createTree(Comparator<T> comp) {
		return new RedBlackTree<T>(comp);
	}
}
class DefaultComparator<T> implements Comparator<T> {

	@SuppressWarnings("unchecked")
	public int compare(T arg0, T arg1) {
		return ((Comparable<T>)arg0).compareTo(arg1);
	}

}
abstract class AbstractBinarySearchTreeSet<Key, Node extends AbstractBinarySearchTreeNode<Key, Node>, Tree extends AbstractBinarySearchTree<Key, Node>> extends AbstractSet<Key> implements ImprovedSet<Key> {
	
	protected Tree tree;
	private int size = 0;
	
	public AbstractBinarySearchTreeSet(Comparator<Key> comp) {
		tree = createTree(comp);
	}
	
	public int size() {
		return size;
	}

	public boolean isEmpty() {
		return size == 0;
	}
	
	public boolean contains(Key v) {
		return tree.search(tree.root, v) != tree.nullNode;
	}

	public Iterator<Key> iterator() {
		return new AbstractIterator<Key>() {
			Iterator<Node> subi = tree.iterator();
			public boolean hasNext() {
				return subi.hasNext();
			}			
			public Key next() {
				return subi.next().key;
			}
		};
	}

	public void insert(Key v) {
		if(tree.insert(v))
			size++;
	}
	
	public Key find(Key k) {
		Node n = tree.search(k);
		if(n == tree.nullNode)
			return null;
		else
			return n.key;
	}
	
	public void remove(Key v) {
		Node n = tree.search(tree.root, v);
		if(n != tree.nullNode) {
			tree.delete(n);
			size--;
		} 
	}

	public void clear() {
		size = 0;
		tree.root = tree.nullNode;
	}
	
	protected abstract Tree createTree(Comparator<Key> comp); 
	
}
abstract class AbstractIterator<T> implements Iterator<T> {

	final public void remove() {
		throw new UnsupportedOperationException();
	}

}
abstract class AbstractSet<T> implements Set<T> {

	public void insertAll(Iterable<T> a) {
		for(T v : a)
			insert(v);
	}

}
interface ImprovedSet<T> extends Set<T> {
	T find(T v);
}
abstract class AbstractBinarySearchTree<Key, Node extends AbstractBinarySearchTreeNode<Key,Node>> implements Iterable<Node> {

	protected Node root;
	protected Node nullNode;
	private final Comparator<Key> comp;
	
	public AbstractBinarySearchTree(Comparator<Key> comp) {
		this.comp = comp;
		this.root = this.nullNode = createNullNode();
	}
	
	public abstract boolean insert(Key v);
	public abstract void delete(Node z);
	
	public Node search(Key k) {
		return search(root, k);
	}
	
	public Node search(Node x, Key k) {
		int c;
		while(x != nullNode) {
			c = compare(k, x.key);
			if(c == 0)
				break;
			else if(c < 0)
				x = x.left;
			else
				x = x.right;
		}
		return x;
	}
	
	public Node minimum(Node x) {
		while(x.left != nullNode)
			x = x.left;
		return x;
	}
	
	public Node maximum(Node x) {
		while(x.right != nullNode)
			x = x.right;
		return x;
	}
	
	public Node successor(Node x) {
		if(x.right == nullNode) {
			Node y = x.parent;
			while(y != nullNode && x == y.right) {
				x = y;
				y = y.parent;
			}
			return y;
		} else {
			return minimum(x.right);
		}
	}
	
	public Node predecessor(Node x) {
		if(x.left == nullNode) {
			Node y = x.parent;
			while(y != nullNode && x == y.left) {
				x = y;
				y = y.parent;
			}
			return y;
		} else {
			return maximum(x.left);
		}
	}
	
	protected int compare(Key v1, Key v2) {
		return comp.compare(v1, v2);	
	}
	
	public Iterator<Node> iterator() {
		return new Iterator<Node>() {
			Node node = (root==nullNode)?nullNode: minimum(root);
			public boolean hasNext() {
				return node != nullNode;
			}
			public Node next() {
				Node r = node;
				node = successor(node);
				return r;
			}
			public void remove() {
				throw new UnsupportedOperationException();
			}
		};
	}
	
	public boolean isNull(Node node) {
		return node == nullNode;		
	}
	
	protected abstract Node createNullNode();
	
}
class AbstractBinarySearchTreeNode<Key, Node extends AbstractBinarySearchTreeNode<Key,Node>> {
	
	public Node left, right, parent;
	public Key key;
	
	public AbstractBinarySearchTreeNode(Key key, Node parent, Node left, Node right) {
		this.key = key;
		this.parent = parent;
		this.left = left;
		this.right = right;
	}
}
class RedBlackTree<T> extends AbstractRedBlackTree<T, RedBlackTreeNode<T>> {
	
	public RedBlackTree(Comparator<T> comp) {
		super(comp);
	}
	
	protected RedBlackTreeNode<T> createNullRedBlackTreeNode(T k, RedBlackTreeNode<T> p, RedBlackTreeNode<T> l, RedBlackTreeNode<T> r, RedBlackTreeNodeColor c) {
		return new RedBlackTreeNode<T>(k, p, l, r, black);
	}
	
	protected RedBlackTreeNode<T> createRedBlackTreeNode(T k, RedBlackTreeNode<T> p, RedBlackTreeNode<T> l, RedBlackTreeNode<T> r, RedBlackTreeNodeColor c) {
		return new RedBlackTreeNode<T>(k, p, l, r, c);
	}
	
	protected void afterRotateLeft(RedBlackTreeNode<T> x, RedBlackTreeNode<T> y) {}
	protected void afterRotateRight(RedBlackTreeNode<T> x, RedBlackTreeNode<T> y) {}
	protected void deleteWalked(RedBlackTreeNode<T> node) {}
	protected void insertWalked(T k, RedBlackTreeNode<T> x) {}
}
abstract class AbstractRedBlackTree<Key, Node extends AbstractRedBlackTreeNode<Key, Node>> extends AbstractBinarySearchTree<Key, Node> {
	
	public AbstractRedBlackTree(Comparator<Key> comp) {
		super(comp);
	}
	
	public boolean insert(Key v) {
		if(search(v) != nullNode)
			return false;
		
		Node y = nullNode;
		Node x = root;
		while(x != nullNode) {
			y = x;
			insertWalked(v, x);
			if(compare(v, x.key) < 0)
				x = x.left;
			else
				x = x.right;
		}
	
		Node z = createRedBlackTreeNode(v, y, nullNode, nullNode, red);
		if(y == nullNode)
			root = z;
		else	 if(compare(z.key, y.key) < 0)
			y.left = z;
		else
			y.right = z;
		insertFix(z);
		return true;
	}
	
	public void delete (Node z) {
		Node y;
		if(z.left == nullNode || z.right == nullNode)
			y = z;
		else
			y = successor(z);
		
		Node x;
		if(y.left == nullNode)
			x = y.right;
		else
			x = y.left;

		x.parent = y.parent;
		if(y.parent == nullNode)
			root = x;
		else 	{
			if(y == y.parent.left)
				y.parent.left = x;
			else
				y.parent.right = x;
		}
		if(y != z) 
			z.key = y.key;
		
		Node n = y.parent;
		while(n != nullNode) {
			deleteWalked(n);
            n = n.parent;
		}
		
		if(y.color == black)
			deleteFix(x);
	}
	
	protected abstract Node createRedBlackTreeNode (Key k, Node p, Node l, Node r, RedBlackTreeNodeColor c);
	protected abstract Node createNullRedBlackTreeNode (Key k, Node p, Node l, Node r, RedBlackTreeNodeColor c);
	
	protected abstract void insertWalked(Key k, Node x);
	protected abstract void deleteWalked(Node node);
	protected abstract void afterRotateLeft(Node x, Node y);
	protected abstract void afterRotateRight(Node x, Node y);
	
	protected Node createNullNode() {
		return createNullRedBlackTreeNode(null, null, null, null, black);
	}
	
	private void insertFix(Node z) {
		while(z.parent.color == red) 
			if(z.parent == z.parent.parent.left) {
				Node y = z.parent.parent.right;
				if(y.color == red) {
					z.parent.color = black;
					y.color = black;
					z.parent.parent.color = red;
					z = z.parent.parent;
				} else {
					if(z.parent.right == z) {
						z = z.parent;
						rotateLeft(z);                            
					}
					z.parent.color = black;
					z.parent.parent.color = red;                    
					rotateRight(z.parent.parent);
				}
			} else {
				Node y = z.parent.parent.left;
				if(y.color == red) {
					z.parent.color = black;
					y.color = black;
					z.parent.parent.color = red;
					z = z.parent.parent;
				} else {
					if(z.parent.left == z) {
						z = z.parent;
						rotateRight(z);                            
					}
					z.parent.color = black;
					z.parent.parent.color = red;                    
					rotateLeft(z.parent.parent);
				}
			}
		root.color = black;
	}
	
	private void deleteFix(Node x) 	{
		while(x != root && x.color == black) 
			if(x == x.parent.left) {
				Node w = x.parent.right;
				if(w.color == red) {
					w.color = black;
					x.parent.color = red;
					rotateLeft(x.parent);
					w = x.parent.right;
				}
				if(w.left.color == black && w.right.color == black) {
					w.color = red;
					x = x.parent;
				} else 	{
					if(w.right.color == black) {
						w.left.color = black;
						w.color = red;
						rotateRight(w);
						w = x.parent.right;
					}
					w.color = x.parent.color;
					x.parent.color = black;
					w.right.color = black;
					rotateLeft(x.parent);
					x = root;
				}
			} else {
				Node w = x.parent.left;
				if(w.color == red) {
					w.color = black;
					x.parent.color = red;
					rotateRight(x.parent);
					w = x.parent.left;
				}
				if(w.right.color == black && w.left.color == black) {
					w.color = red;
					x = x.parent;
				} else 	{
					if(w.left.color == black) {
						w.right.color = black;
						w.color = red;
						rotateLeft(w);
						w = x.parent.left;
					}
					w.color = x.parent.color;
					x.parent.color = black;
					w.left.color = black;
					rotateRight(x.parent);
					x = root;
				}
			}
		x.color = black;
	}

	private void rotateLeft(Node x) {
		Node y = x.right;
		x.right = y.left;
		if(y.left != nullNode)
			y.left.parent = x;
		y.parent = x.parent;
		if(x.parent == nullNode)
			root = y;
		else {
			if(x == x.parent.left)
				x.parent.left = y;
			else
				x.parent.right = y;
		}
		y.left = x;
		x.parent = y;
		afterRotateLeft(x, y);
	}

	private void rotateRight(Node x) {
		Node y = x.left;
		x.left = y.right;
		if(y.right != nullNode)
			y.right.parent = x;
		y.parent = x.parent;
		if(x.parent == nullNode)
			root = y;
		else {
			if(x == x.parent.left)
				x.parent.left = y;
			else
				x.parent.right = y;
		}
		y.right = x;
		x.parent = y;
		afterRotateRight(x,y);
	}
	
	static final protected RedBlackTreeNodeColor red = RedBlackTreeNodeColor.Red;
	static final protected RedBlackTreeNodeColor black = RedBlackTreeNodeColor.Black;
	
}
class AbstractRedBlackTreeNode<Key, Node extends AbstractRedBlackTreeNode<Key,Node>> extends AbstractBinarySearchTreeNode<Key,Node> {
	public RedBlackTreeNodeColor color;
	
	public RedBlackTreeNodeColor getColor() {
		return color;
	}
	
	public AbstractRedBlackTreeNode(Key v, Node p, Node l, Node r,RedBlackTreeNodeColor color) {
		super(v, p, l, r);
		this.color = color;
	}
}
enum RedBlackTreeNodeColor {
	Red, Black
}
class RedBlackTreeNode<T> extends AbstractRedBlackTreeNode<T, RedBlackTreeNode<T>> {
	public RedBlackTreeNode(T key, RedBlackTreeNode<T> parent, RedBlackTreeNode<T> left, RedBlackTreeNode<T> right, RedBlackTreeNodeColor color) {
		super(key, parent, left, right, color);
	}	
}
