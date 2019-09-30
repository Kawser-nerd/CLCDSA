import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int txa = sc.nextInt();
		int tya = sc.nextInt();
		int txb = sc.nextInt();
		int tyb = sc.nextInt();
		int T = sc.nextInt();
		int V = sc.nextInt();
		int N = sc.nextInt();
		int x[] = new int[N];
		int y[] = new int[N];
		for(int i = 0; i < N; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}
		
		boolean flag = false;
		for(int i = 0; i < N; i++) {
			if(Math.sqrt(Math.pow(x[i] - txa, 2) + Math.pow(y[i] - tya, 2)) + Math.sqrt(Math.pow(x[i] - txb, 2) + Math.pow(y[i] - tyb, 2)) <= T * V) {
				flag = true;
			}
		}
		if(flag) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}