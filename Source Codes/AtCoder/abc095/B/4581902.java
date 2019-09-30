//2019/3/15
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		int X = sc.nextInt();

		int sum = 0;

		int min = sc.nextInt();

		int a = 0;

		sum += min;

		int ans = N;

		for(int i=1;i<N;i++) {

			a = sc.nextInt();

			sum += a;

			if(a<min) min = a;
		}

		X -= sum;

		while(true) {

			if(X<min) break;

			X -= min;

			ans++;
		}

		System.out.println(ans);
	}

}