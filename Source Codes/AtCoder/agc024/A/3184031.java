import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		Long K = sc.nextLong();
		int ans = 0;
		if(K%2==1) {
			ans = B-A;
		}else {
			ans = A-B;
		}
		System.out.println(ans);
	}
}