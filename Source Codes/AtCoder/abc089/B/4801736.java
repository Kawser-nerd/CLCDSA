import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		String ans = "Three";
		for (int i = 0; i < N; i++) {
			char ch = reader.next().charAt(0);
			if (ch == 'Y') {
				ans = "Four";
			}

		}



		System.out.print(ans);
		reader.close();
	}
}