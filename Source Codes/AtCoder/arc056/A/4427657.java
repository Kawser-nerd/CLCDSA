import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		long k = sc.nextInt();
		long l = sc.nextInt();
		if (a < (double) b / l) {
			System.out.println(a * k);
		} else {
			System.out.println(Math.min(b * ((k + l - 1) / l), b * (k / l) + a * (k % l)));
		}
 	}
}