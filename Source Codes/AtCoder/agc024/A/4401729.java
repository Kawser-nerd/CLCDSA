import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
		long k = sc.nextLong();
		System.out.println(k%2==1? b-a : a-b);
		
	}
}