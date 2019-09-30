import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

/**
 * https://beta.atcoder.jp/contests/abc036/tasks/abc036_d
 */
public class Main {

	final static int B = 0;
	final static int W = 1;
	final static int MOD = (int) Math.pow(10, 9) + 7;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Node[] nodeList = new Node[N];
		for(int i=0; i<N; i++){
			nodeList[i] = new Node(i);
		}
		for(int i=0; i<N-1; i++){
			Node a = nodeList[sc.nextInt()-1];
			Node b = nodeList[sc.nextInt()-1];
			a.neighbors.add(b);
			b.neighbors.add(a);
		}
		sc.close();

		Node root = createTree(nodeList);
		
		long ans = compute(root)[0];
		System.out.println(ans);
		
	}
	
	private static long[] compute(Node node) {
		long w = 1;
		long b = 1;
		for(Node n:node.children){
			long[] count = compute(n);
			w = (w*count[0])%MOD;
			b = (b*count[1])%MOD;			
		}
		long[] count = new long[2];
		count[0] = (w+b)%MOD;
		count[1] = w;
		//System.out.println(node.id+":"+Arrays.toString(count));
		return count;
	}

	private static Node createTree(Node[] nodeList) {
		Queue<Node> que = new ArrayDeque<Node>();
		que.add(nodeList[0]);
		nodeList[0].visited = true;
		while(!que.isEmpty()){
			Node node = que.remove();
			for(Node n: node.neighbors){
				if(!n.visited){
					node.children.add(n);
					n.parent = node;
					n.visited = true;
					que.add(n);
				}
			}
		}
		return nodeList[0];
	}
	
	static class Node{
		int id;
		Node parent;
		Set<Node> children = new HashSet<Node>();
		Set<Node> neighbors = new HashSet<Node>();
		boolean visited = false;
		Node(int id){
			this.id = id;
		}
	}
	
}