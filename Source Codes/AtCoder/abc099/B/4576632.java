//2019/3/14
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();

		int b = sc.nextInt();

		int c = b-a;

		int d = 0;

		for(int i=1;i<c;i++) d += i;

		int ans = d-a;

		System.out.println(ans);
	}

}