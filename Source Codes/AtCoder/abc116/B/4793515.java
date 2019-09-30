import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int s = sc.nextInt();
		int i = 1;
		Set<Integer> existed = new HashSet<>();

		while (true) {
			if (existed.contains(s)) {
				break;
			}
			existed.add(s);
			if (s % 2 == 0) {
				s = s / 2;
			} else {
				s = s * 3 + 1;
			}
			i++;
		}
		System.out.println(i);
	}
}