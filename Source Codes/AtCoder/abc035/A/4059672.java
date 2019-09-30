import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int h = sc.nextInt();
		if (h / 3 * 4 == w) {
			System.out.println("4:3");
		} else {
			System.out.println("16:9");
		}
	}
}