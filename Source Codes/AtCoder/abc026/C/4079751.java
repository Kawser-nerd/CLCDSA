import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	static int[] salary;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		Tree kyuryo=new Tree(N);
		kyuryo.makeroot(0);
		for(int i=1; i<N; i++) {
			int id=sc.nextInt()-1;
			kyuryo.addTreeNode(i,id);
		}
		salary=new int[N];
		Arrays.fill(salary, 0);

		for(int i=0; i<N; i++) {
			if(kyuryo.numChild(i)==0) {
				salary[i]=1;
			}
		}
		for(int i=0; i<N; i++) {
			if(salary[i]!=1) {
				dfs(kyuryo.parent(i),kyuryo);
			}
		}
		for(int h=0; h<20; h++) {
			for(int i=0; i<N; i++) {
				dfs(kyuryo.parent(i),kyuryo);
			}
		}
		dfs(0,kyuryo);
		pl(salary[0]);
	}
	public static void dfs(int id,Tree ki) {
		if(id!=-1) {
			salary[id]=ki.maxsala(id)+ki.minsala(id)+1;
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
	static class Tree{
		Node[] tree;
		public Tree(int volume) {
			tree=new Node[volume];
			for(int i = 0; i < volume; i++){
				tree[i] = new Node(i);
			}
		}
		public void makeroot(int root_node_id) {
			tree[root_node_id].parent=-1;
			tree[root_node_id].depth=0;
		}
		public void addTreeNode(int id,int parent_id) {
			tree[id].parent=parent_id;
			tree[id].depth=tree[parent_id].depth+1;
			tree[parent_id].addChild(id);
		}
		public int numChild(int id) {
			return tree[id].children.size();
		}
		public int parent(int id) {
			return tree[id].parent;
		}
		public int maxsala(int id) {//id????????????
			int max=0;
			if(tree[id].children.size()==0) {
				return 0;
			}
			else {
				for(int i=0; i<tree[id].children.size(); i++) {
					int tmp=tree[id].children.get(i);
					max=Math.max(max, salary[tmp]);
				}
				return max;
			}
		}
		public int minsala(int id) {//id????????????
			int min=Integer.MAX_VALUE/2;
			if(tree[id].children.size()==0) {
				return 0;
			}
			else {
				for(int i=0; i<tree[id].children.size(); i++) {
					int tmp=tree[id].children.get(i);
					min=Math.min(min, salary[tmp]);
				}
				return min;
			}
		}
	}
	static class Node {
		int parent = -1;
		int id = -1;
		ArrayList<Integer> children = new ArrayList<Integer>();
		int depth = 0;
		public Node (int id){
			this.id = id;
		}
		public void addChild(int n){
			children.add(n);
		}
	}
}