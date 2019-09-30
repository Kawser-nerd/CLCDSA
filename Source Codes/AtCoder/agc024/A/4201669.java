import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();
		long K = sc.nextLong();
		
		if(K % 2 == 0) {
			if(A - B > Math.pow(10, 18)) {
				System.out.println("Unfair");
			} else {
				System.out.println(A - B);
			}
		} else {
			if(B - A > Math.pow(10, 18)) {
				System.out.println("Unfair");
			} else {
				System.out.println(B - A);
			}
		}
	}
}