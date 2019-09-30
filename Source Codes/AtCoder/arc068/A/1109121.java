import java.io.IOException;
import java.util.ArrayList;
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
		long x = Long.parseLong(inLines.get(0));
		long ans = (x / 11) * 2;
		if (x % 11 != 0) {
			if (x % 11 <= 6)
				ans += 1;
			else
				ans += 2;
		}
		System.out.println(ans);
	}
}