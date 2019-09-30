import java.util.Scanner;
public class Main {
	public static int div2(int a) {
		int div2 = 0;
		if(a != 0) {
			while(a % 2 == 0) {
				div2 += 1;
				a /= 2;
			}
		}
		return div2;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int ans = 0;
		for(int i = 0; i < N; i++) {
			ans += div2(sc.nextInt());
		}
		System.out.println(ans);	

	}

}