import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();

		int B = sc.nextInt();

		String S = sc.next();

		boolean ans = true;

		for(int i=0;i<A;i++) {

			if(S.charAt(i)=='-') ans = false;
		}

		if(S.charAt(A)!='-') ans = false;

		for(int i=A+1;i<S.length();i++) {

			if(S.charAt(i)=='-') ans = false;
		}

		if(ans) System.out.println("Yes");

		else System.out.println("No");
	}

}