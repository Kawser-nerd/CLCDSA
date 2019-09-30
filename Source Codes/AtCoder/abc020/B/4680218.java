import java.util.Scanner;

public class Main {
	static int b;
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		String A = reader.next();
		String B = reader.next();
		reader.close();
		int ans = Integer.parseInt(A + B) * 2;
		System.out.println(ans);
	}
}