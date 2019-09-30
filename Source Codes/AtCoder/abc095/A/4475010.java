import java.util.Scanner;

public class Main {

	private static Scanner sc;

	public static void main(String[] args) {

		sc = new Scanner(System.in);
		String order = sc.next();
		int price = 700;

		if ("o".equals(order.subSequence(0,1))) price += 100;
		if ("o".equals(order.subSequence(1,2))) price += 100;
		if ("o".equals(order.subSequence(2,3))) price += 100;

		System.out.println(price);
	}

}