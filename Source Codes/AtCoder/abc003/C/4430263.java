import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		double c=0;
		Integer[]r=new Integer[n];
		for(int i=0;i<n;i++) {
			r[i]=sc.nextInt();
		}
		Arrays.sort(r);
		for(int i=n-k;i<n;i++) {
			c=(double)(c+r[i])/2;
		}
		System.out.println(c);
	}
}