import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		List<ArrayList<Integer>> connect = new ArrayList<ArrayList<Integer>>();
		for (int i=0;i<n+1;i++) {
			connect.add(new ArrayList<Integer>());
		}

		for (int i=0;i<m;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			connect.get(a).add(b);
			connect.get(b).add(a);
		}

		boolean taken[] = new boolean[n+1];
		taken[1]=true;
		LinkedList<Integer> ans = new LinkedList<Integer>();
		ans.add(1);
		extend(ans, connect, taken, false);
		extend(ans, connect, taken, true);
		System.out.println(ans.size());

		StringBuilder sb = new StringBuilder();
		for (Integer i : ans) {
			sb.append(i);
			sb.append(' ');
		}
		sb.deleteCharAt(sb.length()-1);
		System.out.println(sb);
	}

	static void extend(LinkedList<Integer> ans, List<ArrayList<Integer>> connect, boolean[] taken, boolean right) {

		while (true) {
			Integer tmp = right ? ans.getLast() : ans.getFirst();
			boolean found = false;
			for (Integer i : connect.get(tmp)) {
				if (!taken[i]) {
					taken[i] = true;
					if(right) {
						ans.addLast(i);
					} else {
						ans.addFirst(i);
					}
					found = true;
					break;
				}
			}

			if (!found) {
				break;
			}
		}
	}

}