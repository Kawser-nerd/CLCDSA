import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String S1 = S.replace("0","");
		int n1 = S1.length();
		int n0 = S.length() - n1;
		int min = Math.min(n1,n0);
			System.out.println( 2 * min);

	}

}