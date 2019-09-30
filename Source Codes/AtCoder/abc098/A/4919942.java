import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// ?????
		int a = sc.nextInt();
		int b = sc.nextInt();

		int max = Math.max(a + b, a - b);

		System.out.println(Math.max(max, a * b));

	}
}