import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		Integer[] x=new Integer[n+1];
		Integer[] y=new Integer[m+1];
		x[0]=sc.nextInt();
		y[0]=sc.nextInt();
		for(int i=1;i<=n;i++) {
			x[i]=sc.nextInt();
		}
		for(int i=1;i<=m;i++) {
			y[i]=sc.nextInt();
		}
		Arrays.sort(x,Collections.reverseOrder());
		Arrays.sort(y);
		if(x[0]<y[0]) {
			System.out.println("No War");
		}else {
			System.out.println("War");
		}
	}
}