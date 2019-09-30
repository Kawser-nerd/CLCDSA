import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		Integer[]h = new Integer[n];
		for(int i=0;i<n;i++) {
			h[i]=sc.nextInt();
		}
		int w;
		Arrays.sort(h);
		int min=2000000000;
		for(int i=0;i<n-k+1;i++) {
			min=Math.min(h[i+k-1]-h[i],min);
		}
		System.out.println(min);
	}
}