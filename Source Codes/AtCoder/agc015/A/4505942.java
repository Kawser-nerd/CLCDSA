import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws IOException {
//		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		long a = sc.nextInt();
		long b = sc.nextInt();
		if(a>b) {
			System.out.println(0);
			return;
		}
		if(n==1) {
			System.out.println(a==b?1:0);
			return;
		}else {
//			int l = a*(n-1)+b;
//			int r = a+b*(n-1);
//			System.out.println(r-l+1);
			System.out.println((long)((b-a)*(n-2)+1));
		}
	}
}