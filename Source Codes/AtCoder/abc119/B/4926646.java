import java.math.BigDecimal;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int count = scanner.nextInt();
			scanner.nextLine();
			BigDecimal rate = new BigDecimal("380000.0");
			System.out.println(IntStream.range(0, count).mapToObj(i -> {
				String amount = scanner.next();
				String currency = scanner.next();
				scanner.nextLine();
				if ("JPY".equals(currency)) {
					return new BigDecimal(amount);
				} else {
					return (new BigDecimal(amount)).multiply(rate);
				}
			}).reduce(BigDecimal.ZERO, BigDecimal::add));
		}
	}
}