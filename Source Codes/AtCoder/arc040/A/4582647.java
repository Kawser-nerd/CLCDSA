import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int takahashi = 0;
		int aoki = 0;

		for(int i=0; i<n; i++) {
			 String s = sc.next();
			for(int j=0; j<n; j++) {
				if(s.charAt(j) == 'R') {
					takahashi++;
				}else if(s.charAt(j) == 'B') {
					aoki++;
				}
			}
		}

		if(takahashi > aoki) {
			System.out.println("TAKAHASHI");
		}else if(takahashi < aoki) {
			System.out.println("AOKI");
		}else {
			System.out.println("DRAW");
		}
	}
}