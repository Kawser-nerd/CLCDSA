import java.util.Arrays;
import java.util.Scanner;

/**
 * https://abc040.contest.atcoder.jp/tasks/abc040_d
 */
public class Main {

	static Node[] nodes;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		nodes = new Node[N];
		for(int i=0; i<N; i++) nodes[i] = new Node(i);
		Edge[] edges = new Edge[M];
;		for(int i=0; i<M; i++){
			Node a = nodes[Integer.parseInt(sc.next())-1];
			Node b = nodes[Integer.parseInt(sc.next())-1];
			int year = Integer.parseInt(sc.next());
			edges[i] = new Edge(year, a, b);
		}
		int Q = sc.nextInt();
		Query[] queries = new Query[Q];
		for(int i=0; i<Q; i++){
			int v = Integer.parseInt(sc.next())-1;
			int w = Integer.parseInt(sc.next());
			queries[i] = new Query(i,v,w);
		}
		sc.close();
		
		Arrays.sort(edges, (e1, e2) -> e2.year - e1.year);
		Arrays.sort(queries, (q1, q2) -> q2.w - q1.w);
		int current = 0;
		int[] ans = new int[Q];
		for(Query q: queries){
			while(current<M && edges[current].year > q.w){
				unite(edges[current].node1.id, edges[current].node2.id);
				current++;
			}
			ans[q.id] = findRoot(q.v).size;
		}
		
		for(int a:ans){
			System.out.println(a);
		}

	}
	
	static class Node{
		int id;
		Node parent;
		Node left;
		Node right;
		int height = 0;
		int size = 1;
		Node(int id){
			this.id = id;
			this.parent = this;
		}
	}
	
	static class Edge{
		Node node1;
		Node node2;
		int year;
		Edge(int year, Node node1, Node node2){
			this.node1 = node1;
			this.node2 = node2;
			this.year = year;
		}
	}
	
	static class Query{
		int id;
		int v;
		int w;
		int ans;
		Query(int id, int v, int w){
			this.id = id;
			this.v = v;
			this.w = w;
		}
	}
	
	static void unite(int id1, int id2){
		Node node1 = findRoot(id1);
		Node node2 = findRoot(id2);
		if(node1==node2) return;
		if(node1.height==node2.height){
			node2.parent = node1;
			node1.height++;
			node1.size = node1.size+node2.size;
		}else if(node1.height>node2.height){
			node2.parent = node1;
			node1.size = node1.size+node2.size;
		}else{
			node1.parent = node2;
			node2.size = node1.size+node2.size;
		}
	}
	
	static Node findRoot(int id){
		Node node = nodes[id];
		while(node.parent != node){
			node = node.parent;
		}
		return node;
	}

}