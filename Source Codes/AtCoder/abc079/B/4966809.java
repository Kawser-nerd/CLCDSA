import java.util.*;
public class Main {
	public static void main(String[] args) {
		B();
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
	
	public static void B() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if(N==1) {
			System.out.println(1);
			return;
		}
		sc.close();
		long Li = 2;
		long Lj = 1;
		long temp;
		for(int i=2;i<N+1;i++) {
			temp = Lj;
			Lj = Li+Lj;
			Li = temp;
		}
		System.out.println(Lj);
	}
	
}