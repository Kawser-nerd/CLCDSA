import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();

		int B = sc.nextInt();

		int ans = 0;

		for(int i=A;i<=B;i++) {

			int s = i/10000;

			int t = i/1000 - s*10;

			int u = i%10;

			int v = (i%100 - u)/10;

			if(s==u && t==v)ans++;
		}
		System.out.println(ans);
	}

}