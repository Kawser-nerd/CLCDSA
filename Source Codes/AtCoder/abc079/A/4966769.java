import java.util.*;
public class Main {
	public static void main(String[] args) {
		A();
	}
	
	public static void A() {
		Scanner sc = new Scanner(System.in);
		Integer n = sc.nextInt();
		sc.close();
		String num = n.toString();
		if(num.charAt(1) != num.charAt(2)) {
			System.out.println("No");
			return;
		}
		char mid = num.charAt(1);
		if(mid == num.charAt(0) || mid == num.charAt(3)) {
			System.out.println("Yes");
		}
		else System.out.println("No");
	}
	
	
}