import java.util.*;

public class Main {
	static class TriTree {
		Node root = new Node();
		
		class Node {
			ArrayList<Node> child = new ArrayList<>();
			char c;
			long depth;
			public void add(Node node) {
				child.add(node);
			}
			public Node() {
				
			}
			public Node(char c, long depth) {
				this.c = c;
				this.depth = depth;
			}
			public long xorGrundy() {
				long xor=0;
				for(Node node : child)
					xor ^= node.xorGrundy();
				if(child.size()==1)
					xor ^= grundy(L - depth);
				return xor;
			}
		}
		
		public void addLeaf(String s) {
			Node cur = root;
			for(int i=0; i<s.length(); i++) {
				boolean found = false;
				for(Node child : cur.child) {
					if(child.c==s.charAt(i)) {
						cur = child;
						found = true;
						break;
					}
				}
				if(!found) {
					Node next = new Node(s.charAt(i), i+1);
					cur.add(next);
					cur = next;
				}
			}
		}
		
		public long xorGrundy() {
			return root.xorGrundy();
		}
	}
	
	static long L;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		L = sc.nextLong();
		TriTree tree = new TriTree();
		for(int i=0; i<N; i++)
			tree.addLeaf(sc.next());

		System.out.println(tree.xorGrundy()==0 ? "Bob" : "Alice");
		sc.close();
	}
	
	static long grundy(long n) {
		long ans=1;
		while(n%ans==0)
			ans<<=1;
		return ans;
	}
	
}