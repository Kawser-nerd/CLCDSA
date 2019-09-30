import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		int L = str.length();
		int cnt = 0;

		boolean check = true;
		
		for (int i = 0; i < L; i++) {
			if ( i == 0) {
				if(str.charAt(i) != 'A') {
					check = false;
				}
			}
			else if( 2 <= i && i <= L - 2) {
				if (str.charAt(i) == 'C') {
					cnt++;
				}
				else if( 'A'<= str.charAt(i) && str.charAt(i) <= 'Z' ) {
					check = false;
				}
			}
			else {
				if('A'<= str.charAt(i) && str.charAt(i) <= 'Z')
					check = false;
			}
	}
		if (cnt != 1) {
			check = false;
		}
		
		if(check) {
			System.out.println("AC");
		}
		else {
			System.out.println("WA");
		}
}
}