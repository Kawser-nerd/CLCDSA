//2019/3/14
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int D = sc.nextInt();

		int N = sc.nextInt();

		int ans = 0;

		if(D==0 && N>=100) {

			ans = 101;

		}else if(D==0 && N<100) {

			ans = N;

		}else if(D==1 && N>=100) {

			ans = 101*100;

		}else if(D==1 && N<100) {

			ans = N*100;

		}else if(D==2 && N>=100) {

			ans = 101*10000;

		}else if(D==2 && N<100) {

			ans = N*10000;
		}

		System.out.println(ans);
	}

}