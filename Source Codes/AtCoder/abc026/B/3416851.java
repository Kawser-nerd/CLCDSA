import java.util.Arrays;
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int r[]=new int[n];
		for(int i=0;i<n;i++) {
			r[i]=scanner.nextInt();
		}
		Arrays.sort(r);
		double ans=0;
		for(int i=r.length-1;i>=0;i--) {
			if(i%2==(r.length-1)%2) {
				ans+=Math.pow(r[i], 2);
			}else {
				ans-=Math.pow(r[i], 2);
			}
		}
		ans*=Math.PI;
		System.out.println(ans);
	}
}