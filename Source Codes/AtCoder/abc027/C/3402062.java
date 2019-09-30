import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long N = scan.nextLong();
		scan.close();
		int depth = 0;

		for(long n = N; n > 0; n /= 2) {
			depth++;
		}

		if(depth % 2 == 0) {
			long x = 1;
			for(int i = 0; i <= depth; i++) {
				if(i % 2 == 0) {
					x = 2 * x;
				}else {
					x = 2 * x + 1;
				}
				if(x > N) {
					if(i % 2 == 0) {
						System.out.println("Aoki");
						System.exit(0);
					}else {
						System.out.println("Takahashi");
						System.exit(0);
					}
				}
			}
		}else {
			long x = 1;
			for(int i = 0; i < depth; i++) {
				if(i % 2 == 0) {
					x = 2 * x + 1;
				}else {
					x = 2 * x;
				}
				if(x > N) {
					if(i % 2 == 0) {
						System.out.println("Aoki");
						System.exit(0);
					}else {
						System.out.println("Takahashi");
						System.exit(0);
					}
				}
			}
		}
	}
}