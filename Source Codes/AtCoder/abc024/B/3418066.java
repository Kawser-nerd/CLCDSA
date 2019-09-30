import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int t=scanner.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=scanner.nextInt();
		}
		int sum=0;
		for(int i=0;i<n-1;i++) {
			if(a[i]+t>a[i+1]) {
				sum+=a[i+1]-a[i];
			}else {
				sum+=t;
			}
		}
		sum+=t;
		System.out.println(sum);
	}
}