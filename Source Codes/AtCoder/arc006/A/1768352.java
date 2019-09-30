import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] e = new int[6];
		int[] l = new int[6];
		for(int i = 0 ; i < 6 ; i++) {
			e[i] = sc.nextInt();
		}
		int b = sc.nextInt();
		for(int i = 0 ; i < 6 ; i++) {
			l[i] = sc.nextInt();
		}
		int ans = 7;
		for(int i = 0 ; i < 6 ; i++) {
			for(int j = 0 ; j < 6 ; j++) {
				if(e[i] == l[j]) {
					ans--;
					e[i] = -1;
					break;
				}
			}
		}
		if(5 <= ans && ans <= 7) System.out.println(0);
		else if(ans == 4) System.out.println(5);
		else if(ans == 3) System.out.println(4);
		else if(ans == 2) {
			boolean ok = false;
			for(int i = 0 ; i < 6 ; i++) {
				if(l[i] == b) ok = true;
			}
			if(ok) System.out.println(2);
			else System.out.println(3);
		} else {
			System.out.println(1);
		}
	}
}