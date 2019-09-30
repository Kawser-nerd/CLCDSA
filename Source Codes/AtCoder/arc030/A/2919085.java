import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		System.out.println(k <= n/2 ? "YES" : "NO");
		in.close();
	}

}