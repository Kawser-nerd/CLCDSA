import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		String ab = a + b;
		int num = Integer.parseInt(ab);
		for(int i = 1; i < 1000; i++) {
			if(i * i == num) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
}