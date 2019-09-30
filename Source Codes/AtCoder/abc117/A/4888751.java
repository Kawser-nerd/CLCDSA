import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			BigDecimal number1 = new BigDecimal(scanner.next());
			BigDecimal number2 = new BigDecimal(scanner.next());
			System.out.println(number1.divide(number2, 10, RoundingMode.HALF_UP));
		}
	}
}