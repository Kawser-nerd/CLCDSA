import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String s = sc.next();
		String t = sc.next();
		sc.close();
		for(int i = 0; i < N; i++) {
			boolean flag = true;
			for(int j = 0; j + i < N; j++) {
				char cs = s.charAt(j + i);
				char ct = t.charAt(j);
				if(cs != ct) {
					flag = false;
					break;
				}
			}
			if(flag) {
				System.out.println(N + i);
				break;
			}
			if(i == N - 1) {
				System.out.println(2 * N);
			}
		}
	}
}