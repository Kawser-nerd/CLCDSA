import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int division = 1000000007;
		// ?????????????result??????
		long result = 1;
		for (int i = 1; i <= N; i++) {
			result = (result * i) % division;
		}
		System.out.println(result);
		sc.close();
	}
}