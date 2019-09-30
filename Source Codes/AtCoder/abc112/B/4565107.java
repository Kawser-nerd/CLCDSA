import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int T = reader.nextInt();
		int min = 1000;
		String result = "TLE";
		for (int i = 0; i < N; i++) {
			int A = reader.nextInt();
			int B = reader.nextInt();
			if (B <= T && A <= min) {
				min = A;
				result = Integer.toString(min);
			}
		}

		reader.close();
		System.out.print(result);
	}
}