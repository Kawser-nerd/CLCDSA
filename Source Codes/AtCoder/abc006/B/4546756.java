import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a= new long[1000000];
		a[0]=0;
		a[1]=0;
		a[2]=1;
		for(int i=3;i<a.length;i++) {
			long num=a[i-3]+a[i-2]+a[i-1];
			a[i]=num%10007;
		}
		System.out.println(a[n-1]);
		}
		
}