import java.util.*;

public class Main {

	private static final char LEFT = '(';
	private static final char RIGHT = ')';

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);

		final int N = sc.nextInt();
		sc.nextLine();
		String s = sc.nextLine();

		int[] count = new int[N];

		count[0] = (s.charAt(0) == LEFT) ? 1 : -1;
		int min = Math.min(0, count[0]);
		
		for (int i = 1; i < N; i++) {
			switch (s.charAt(i)) {
			case LEFT:
				count[i] = count[i - 1] + 1;
				break;
			case RIGHT:
				count[i] = count[i - 1] - 1;
				break;
			default:
				throw new IllegalArgumentException();
			}
			if (count[i] < 0) {
				min = Math.min(count[i], min);
			}
		}
		StringBuilder str = new StringBuilder();

		for (int i = 0, bound = Math.abs(min); i < bound; i++) {
			str.append(LEFT);
		}
		str.append(s);

		for (int i = 0, bound = count[N - 1] + Math.abs(min); i < bound; i++) {
			str.append(RIGHT);
		}

		System.out.println(str.toString());
		sc.close();

	}
}