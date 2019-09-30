import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int ans = Math.min(A-B, B-1);

		System.out.println(ans);
		reader.close();
	}
}