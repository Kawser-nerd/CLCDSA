import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		String a = reader.next();
		String b = reader.next();
		int N = Integer.parseInt(a + b);
		String ans = "No";

		int base = 1;
		while (Math.pow((base), 2) <= N) {
			if (Math.pow((base), 2) == N) {
				ans = "Yes";
			}
			base++;
		}


		System.out.print(ans);
		reader.close();
	}
}