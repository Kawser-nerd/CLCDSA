import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Y = sc.nextInt();
		boolean ok = false;
		LOOP:for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= N-i; j++) {
				if(i*10000 + j*5000 + (N-j-i)*1000 == Y) {
					ok = true;
					System.out.println(i + " " + j + " " + (N-j-i));
					break LOOP;
				}
			}
		}
		if(!ok)
			System.out.println(-1 + " " + -1 + " " + -1);

	}

}