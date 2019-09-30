import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long temp = n;
		int depth = 0;
		// ??????
		while(true) {
			temp /= 2;
			if(temp == 0) {
				break;
			}
			depth++;
		}
		long x = 1;
		char turn = 'T';
		// depth % 2 == 0 => ?????????
		// depth % 2 == 1 => ?????????
		if(depth % 2 == 0) {
			while(true) {
				if(turn == 'T') {
					x = x * 2 + 1;
					if(x > n) {
						System.out.println("Aoki");
						return;
					}
					turn = 'A';
				} else if(turn == 'A') {
					x *= 2;
					if(x > n) {
						System.out.println("Takahashi");
						return;
					}
					turn = 'T';
				}
			}
		} else {
			while(true) {
				if(turn == 'T') {
					x = x * 2;
					if(x > n) {
						System.out.println("Aoki");
						return;
					}
					turn = 'A';
				} else if(turn == 'A') {
					x = x * 2 + 1;
					if(x > n) {
						System.out.println("Takahashi");
						return;
					}
					turn = 'T';
				}
			}
		}
	}
}