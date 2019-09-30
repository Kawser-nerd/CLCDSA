import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int ans=0;
		int a[]=new int[n*2];
		for(int i=0;i<n*2;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		for(int i=0;i<n*2;i+=2) ans+=a[i];
System.out.println(ans);
	}
}