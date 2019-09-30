import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		BigDecimal b = BigDecimal.ONE;
		BigDecimal ten = BigDecimal.TEN;
		int n = sc.nextInt();
		for(int i = 0; i < n; i++) {
			b=b.multiply(ten);
		}
		b=b.add(new BigDecimal(7));
		System.out.println(b);
	}
}