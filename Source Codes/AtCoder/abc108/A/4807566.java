import java.util.*;

public class Main {
	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		System.out.println((n / 2) * ((n + 1) / 2));
	}
}