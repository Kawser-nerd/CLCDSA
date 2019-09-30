package round1a;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int N = sc.nextInt();
			adj = new ArrayList<List<Integer>>(N);
			for (int i = 0; i < N; i++) adj.add(new ArrayList<Integer>(3));
			for (int i = 0; i < N - 1; i++) {
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				adj.get(a).add(b);
				adj.get(b).add(a);
			}
			int ans = N;
			for (int i=0; i<N;i++) {
				visited = new ArrayList<Boolean>(N);
				for (int j = 0; j < N; j++) visited.add(false);
				int val = getData(i).minToRemove;
//				System.out.println(i + " => " + val);
				ans = Math.min(ans, val);
			}
			System.out.println("Case #" + caze + ": " + ans);
		}
	}
	private static List<Boolean> visited;
	private static List<List<Integer>> adj;
	
	private static Data getData(int node) {
		visited.set(node, true);
		List<Data> children = new ArrayList<Data>();
		for (Integer vec : adj.get(node)) {
			if (!visited.get(vec)) children.add(getData(vec));
		}
		if (children.size() == 0) {
			return new Data(0, 1);
		} else if (children.size() == 1) {
			Data child = children.get(0);
			return new Data(child.nodes, child.nodes + 1);
		}
		
		int totNodes = 0;
		for (int i = 0; i< children.size();i++) {
			totNodes += children.get(i).nodes;
		}
		Collections.sort(children, new Comparator<Data>() {

			@Override
			public int compare(Data o1, Data o2) {
				int value1 = o1.nodes - o1.minToRemove;
				int value2 = o2.nodes - o2.minToRemove;
				return value1 > value2 ? -1 : value1 == value2 ? 0 : 1;
			}
		});
		return new Data(totNodes - children.get(0).nodes + children.get(0).minToRemove - children.get(1).nodes + children.get(1).minToRemove, totNodes + 1);
	}
	
	public static class Data {
		public int minToRemove, nodes;

		public Data(int minToRemove, int nodes) {
			this.minToRemove = minToRemove;
			this.nodes = nodes;
		}
	}
}
