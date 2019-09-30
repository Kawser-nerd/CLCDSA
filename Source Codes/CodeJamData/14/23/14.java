import java.util.*;

public class Main
{
	int n;
	String[] zip;
	ArrayList<ArrayList<Integer>> nbrs;

	public static void main(String[] args)
	{
		new Main().run();
	}

	void run()
	{
		Scanner in = new Scanner(System.in);
		int ts = in.nextInt();
		for (int ti = 1; ti <= ts; ti++)
		{
			n = in.nextInt();
			int m = in.nextInt();
			zip = new String[n];
			nbrs = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < n; i++) {
				zip[i] = in.next();
				nbrs.add(new ArrayList<Integer>());
			}
			for (int i = 0; i < m; i++) {
				int a = in.nextInt() - 1, b = in.nextInt() - 1;
				nbrs.get(a).add(b);
				nbrs.get(b).add(a);
			}
			System.out.format("Case #%d: %s\n", ti, solve());
		}
	}

	String solve()
	{
		StringBuilder res = new StringBuilder();
		ArrayList<String> res_zips = new ArrayList<String>();

		HashSet<Integer> visited = new HashSet<Integer>();
		LinkedList<Integer> stack = new LinkedList<Integer>();

		int x = start();
		update(res, visited, stack, x);
		res_zips.add(zip[x]);

		for (int i = 1; i < n; i++)
		{
			int best_bt = -1, best_nbr = -1;
			String best_zip = null;
			LinkedList<Integer> stack_trial = new LinkedList<Integer>(stack);
			while (stack_trial.size() >= 1) {
				int bt = stack_trial.getFirst();
				for (int nbr : nbrs.get(bt)) {
					if (!visited.contains(nbr) && (best_zip == null || zip[nbr].compareTo(best_zip) < 0)) {
						LinkedList<Integer> queue = new LinkedList<Integer>(stack_trial);
						queue.addFirst(nbr);
						if (possible(queue, new HashSet<Integer>(visited))) {
							best_bt = bt;
							best_nbr = nbr;
							best_zip = zip[best_nbr];
						}
					}
				}
				stack_trial.removeFirst();
			}
			x = best_nbr;
			backtrack(stack, best_bt);
			update(res, visited, stack, x);
			res_zips.add(zip[x]);
		}

		Collections.sort(res_zips);
		List<String> orig_zips = new ArrayList<String>(Arrays.asList(zip));
		Collections.sort(orig_zips);
		if (!res_zips.equals(orig_zips)) {
			System.err.println("failed");
		}
		return res.toString();
	}

	void update(StringBuilder res, HashSet<Integer> visited, LinkedList<Integer> stack, int x)
	{
		res.append(zip[x]);
		visited.add(x);
		stack.addFirst(x);
	}

	void backtrack(LinkedList<Integer> stack, int x)
	{
		while (stack.getFirst() != x) {
			stack.removeFirst();
		}
	}

	int start()
	{
		int b = 0;
		for (int i = 0; i < n; i++) {
			if (zip[i].compareTo(zip[b]) <= 0) {
				b = i;
			}
		}
		return b;
	}

	boolean possible(LinkedList<Integer> queue, HashSet<Integer> visited)
	{
		while (!queue.isEmpty())
		{
			int q = queue.removeFirst();
			visited.add(q);
			for (int nbr : nbrs.get(q)) {
				if (!visited.contains(nbr)) {
					queue.addFirst(nbr);
				}
			}
		}
		return visited.size() == n;
	}
}

