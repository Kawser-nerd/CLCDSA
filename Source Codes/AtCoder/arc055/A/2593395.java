import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			BigInteger ten = BigInteger.valueOf(10);
			System.out.println(ten.pow(n).add(BigInteger.valueOf(7)));
		}
	}
}