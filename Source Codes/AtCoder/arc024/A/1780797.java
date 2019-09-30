import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int L = sc.nextInt();
		int R = sc.nextInt();
		int[] l = new int[L];
		int[] r = new int[R];
		for(int i = 0 ; i < L ; i++) {
			l[i] = sc.nextInt();
		}
		for(int i = 0 ; i < R ; i++) {
			r[i] = sc.nextInt();
		}
		int ans = 0;
		for(int i = 0 ; i < L ; i++) {
			for(int j = 0 ; j < R ; j++) {
				if(l[i] == r[j]) {
					l[i] = r[j] = -1;
					ans++;
					break;
				}
			}
		}
		System.out.println(ans);
	}
}