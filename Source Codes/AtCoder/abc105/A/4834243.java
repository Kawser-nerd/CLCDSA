import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// ?????
		int a = sc.nextInt();
		// ?????????????
		int b = sc.nextInt();
		// ?????????
		sc.close();
		System.out.println(a % b == 0 ? 0 : 1);
	}
}