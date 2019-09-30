import java.io.PrintWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());
		int[] x = new int[n + 1];
		int[] rank = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			x[i] = Integer.parseInt(sc.next());
			rank[x[i]] = i;
		}
		PriorityQueue p = new PriorityQueue(k, new MyComparator());
		for (int i = 1; i <= k; i++)
			p.add(x[i]);
		for (int i = k + 1; i <= n; i++) {
			out.println(rank[(int)p.peek()]);
			p.add(x[i]);
			p.poll();
		}
		out.println(rank[(int)p.peek()]);
		out.flush();
	}
}
class MyComparator implements Comparator {
	@Override
	public int compare(Object o1, Object o2) {
		return (int)o2 - (int)o1;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.