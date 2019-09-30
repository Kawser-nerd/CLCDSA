import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] w = new String[n];
		for(int i = 0 ; i < n ; i++) w[i] = sc.next();
		int ans = 0;
		for(int i = 0 ; i < n ; i++) {
			if(i == n - 1) {
				w[i] = w[i].replaceAll("\\.", "");
			}
			if(w[i].equals("TAKAHASHIKUN") || w[i].equals("Takahashikun") || w[i].equals("takahashikun")) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}