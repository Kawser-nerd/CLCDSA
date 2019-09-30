import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class Main {
	public static void main(String args[]) throws IOException {
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		ArrayList<String> inLines = new ArrayList<String>();
		for (; cin.hasNext();) {
			inLines.add(cin.nextLine());
		}
		Solver solver = new Solver();
		solver.solve(inLines);
	}
}

class Solver {

	public void solve(ArrayList<String> inLines) {
		int N = Integer.parseInt(inLines.get(0));
		String[] strArr = inLines.get(1).split(" ");
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < N; i++) {
			int An = Integer.parseInt(strArr[i]);
			if (map.containsKey(An))
				map.put(An, map.get(An) + 1);
			else
				map.put(An, 1);
		}
		int cnt = 0;
		for (int key : map.keySet()) {
			if (map.get(key) % 2 == 0) {
				cnt++;
			}
		}
		if (cnt % 2 == 0)
			System.out.println(map.size());
		else
			System.out.println(map.size() - 1);
	}
}