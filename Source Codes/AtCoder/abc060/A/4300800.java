import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String A = sc.next();
		String B = sc.next();
		String C = sc.next();
		if(A.substring(A.length() - 1, A.length()).equals(B.substring(0, 1))){
			if(B.substring(B.length() - 1, B.length()).equals(C.substring(0, 1))) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
}