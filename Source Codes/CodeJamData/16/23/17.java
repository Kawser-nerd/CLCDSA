package round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;

import round1B.PushRelabelNodeEdge.Node;

public class ProblemC {

	public static void solve(Scanner sc) {
		int n = sc.nextInt();
		HashMap<String, Node> map1 = new HashMap<>();
		HashMap<String, Node> map2 = new HashMap<>();
		Node start = new Node("start");
		Node end = new Node("end");
		for (int i = 0; i < n; i++) {
			String firstWord = sc.next();
			String secondWord = sc.next();
			if (!map1.containsKey(firstWord)) {
				Node node = new Node(firstWord);
				map1.put(firstWord, node);
				PushRelabelNodeEdge.addDirectedEdge(start, node, 1);
			}
			if (!map2.containsKey(secondWord)) {
				Node node = new Node(secondWord);
				map2.put(secondWord, node);
				PushRelabelNodeEdge.addDirectedEdge(node, end, 1);
			}
			PushRelabelNodeEdge.addDirectedEdge(map1.get(firstWord),map2.get(secondWord), 1);
		}
		ArrayList<Node> nodes = new ArrayList<>();
		nodes.add(start);
		nodes.add(end);
		nodes.addAll(map1.values());
		nodes.addAll(map2.values());
		int flow = PushRelabelNodeEdge.getMaxFlow(nodes,start, end);
		int greedy = nodes.size() - 2 - 2*flow;
		System.out.println(n - flow  - greedy);
	}

	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("C-practice.in"));
//		 Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		 Scanner sc = new Scanner(new File("C-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
