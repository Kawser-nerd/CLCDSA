import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long temp = n;
		int depth = 0;
		while(temp > 0) {
			temp /= 2;
			depth++;
		}
		long x = 1;
		char turn = 'T';
		if(depth % 2 == 0) {
			while(n >= x) {
				if(turn == 'T') {
					turn = 'A';
					x *= 2;
				} else {
					turn = 'T';
					x = x * 2 + 1;
				}
			}
		} else {
			while(n >= x) {
				if(turn == 'T') {
					turn = 'A';
					x = x * 2 + 1;
				} else {
					turn = 'T';
					x *= 2;
				}
			}
		}
		String ans = turn == 'T' ? "Takahashi" : "Aoki";
		System.out.println(ans);
	}
}