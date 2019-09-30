import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c = 0;
		for (int i = 0; i < n; i++) {
			String a = sc.next();
			if (a.equals("Y")) {
				c++;
			}
		}
		if (c != 0) {
			System.out.println("Four");
		} else {
			System.out.println("Three");
		}
		sc.close();
	}

}