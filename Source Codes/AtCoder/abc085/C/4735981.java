import java.util.Scanner;
import java.util.HashSet;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Y = sc.nextInt();
		sc.close();
			
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= N-i; j++) {
				int k = N - i -j;
				if(i + j + k == N) {
					if(Y == 10000*i+5000*j+1000*k) {
						System.out.println(i +" "+ j + " " + k);
						System.exit(0);
					}
				}
			}
		}
		System.out.println("-1 -1 -1");
	}
}