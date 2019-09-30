package round1c;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=0;i<t;i++) {
			int n = sc.nextInt();
			List<Integer> [] inherits = new List[n];
			for (int j=0;j<n;j++) {
				int mi = sc.nextInt();
				inherits[j] = new ArrayList<Integer>(mi);
				for (int k=0;k<mi;k++) {
					inherits[j].add(new Integer(sc.nextInt() - 1));
				}
			}
			
			boolean found = false;
			for (int j=0;j<n;j++) {
				List<Integer> queue = new LinkedList<Integer>();
				queue.add(new Integer(j));
				boolean [] visited = new boolean[n];
				for (int k=0;k<n;k++) visited[k] = false;
				while (!queue.isEmpty() && !found) {
					int curr = queue.remove(0).intValue();
					
					for (Integer anc : inherits[curr]) {
						int a = anc.intValue();
						if (!visited[a]) {
							visited[a] = true;
							queue.add(anc);
						} else {
							found = true;
							break;
						}
					}
				}
				if (found) break;
			}
			
			System.out.println("Case #" + (i + 1) + ": " + (found ? "Yes" : "No"));
		}
	}
}
