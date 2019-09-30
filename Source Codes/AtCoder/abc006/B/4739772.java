import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();

		ArrayList<Integer> tribonach = new ArrayList<Integer>();
		tribonach.add(0);
		tribonach.add(0);
		tribonach.add(1);

		for (int i = 3; i < n; i++) {
			int a = (tribonach.get(i - 1) + tribonach.get(i - 2) + tribonach.get(i - 3)) % 10007;
			tribonach.add(a);
		}

		int an = tribonach.get(n-1);

		System.out.println(an);
	}

}