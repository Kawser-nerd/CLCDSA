import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		double h = sc.nextDouble() / 100;
		double b = sc.nextDouble();
		System.out.println(b * h * h);
	}
}