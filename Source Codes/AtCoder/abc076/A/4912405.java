import java.util.*;
public class Main {
	public static void main(String[] args) {
		A();
	}
	
	// R+X = 2G
	public static void A() {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int g = sc.nextInt();
		System.out.println(2*g-r);
	}
}