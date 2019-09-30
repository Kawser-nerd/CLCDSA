import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int X = scan.nextInt();
		int Y = scan.nextInt();
		int[]a = new int[N];
		int[]b = new int[M];
		for(int i = 0; i < N; i++) {
			a[i] = scan.nextInt();
		}
		for(int i = 0; i < M; i++) {
			b[i] = scan.nextInt();
		}
		scan.close();
		int id_a = 0;
		int id_b = 0;
		int t = 0;
		int cnt = 0;
		int k = 0;
		while(id_a < N && id_b < M) {
			if(k == 0) {
				boolean flag = true;
				for(int i = id_a; i < N; i++) {
					if(t <= a[i]) {
						t = a[i] + X;
						flag = false;
						k = 1;
						id_a = i + 1;
						//System.out.println("A " + t);
						break;
					}
				}
				if(flag) {
					break;
				}
			}
			if(k == 1) {
				boolean flag = true;
				for(int i = id_b; i < M; i++) {
					if(t <= b[i]) {
						t = b[i] + Y;
						flag = false;
						k = 0;
						id_b = i + 1;
						cnt++;
						//System.out.println("B " + t);
						break;
					}
				}
				if(flag) {
					break;
				}
			}
		}
		System.out.println(cnt);
	}
}