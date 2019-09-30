import java.util.Arrays;
import java.util.Scanner;
public class Main {
	//public static int N,K,a=-1;
	public static String ans="",s;

	//public static int a[][]=new int[5][5];

	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int x=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
			x-=a[i];
		}
		Arrays.sort(a);
		int ans=n;
		for(;;) {
			x-=a[0];
			if(x<0)break;
			ans++;
		}
		System.out.println(ans);
	}
}