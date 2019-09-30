import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
	int n=sc.nextInt();
	int m=sc.nextInt();
	int a[]=new int[m];
	int d[]=new int[m-1];
	for(int i=0;i<m;i++) {
		a[i]=sc.nextInt();
	}
	Arrays.sort(a);
	for(int i=0;i<m-1;i++) {
		d[i]=a[i+1]-a[i];
	}
	Arrays.sort(d);
	int ans=0;
	for(int i=0;i<m-n;i++) {
		ans+=d[i];
	}
	System.out.println(ans);
	}
}