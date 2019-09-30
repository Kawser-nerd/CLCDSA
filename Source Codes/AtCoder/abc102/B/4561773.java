import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int[]a;
		a=new int[100];
		Scanner sc=new java.util.Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		int max,min;
		max=min=a[0];
		for(int i=1;i<n;i++) {
			max=Math.max(max,a[i]);
			min=Math.min(min,a[i]);
		}
		System.out.println(max-min);
	}
}