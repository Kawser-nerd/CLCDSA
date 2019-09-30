import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] k = new int[3];
		for(int i = 0; i < 3; i++) {
			k[i] = sc.nextInt();
		}
		sc.close();
		if(k[0] % 2 == 1 || k[1] % 2 == 1 || k[2] % 2 == 1) {
			System.out.println(0);
			System.exit(0);
		}
		if(k[0] == k[1] || k[1] == k[2]) {
			System.out.println(-1);
			System.exit(0);
		}
		int cnt = 0;
		while(k[0] % 2 == 0 && k[1] % 2 == 0 && k[2] % 2 == 0) {
			int t0 = k[0];
			int t1 = k[1];
			int t2 = k[2];
			k[0] = (t1 + t2) / 2;
			k[1] = (t0 + t2) / 2;
			k[2] = (t0 + t1) / 2;
			cnt++;
		}
		System.out.println(cnt);
	}
}