import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int[] a=new int[3];
		int[] b=new int[3];
		for(int i=0;i<3;i++)
			a[i]=sc.nextInt();
		b[0]=Math.abs(a[0]-a[1]);
		b[1]=Math.abs(a[1]-a[2]);
		b[2]=Math.abs(a[2]-a[0]);
		Arrays.sort(b);
		int ans=b[0]+b[1];
		System.out.println(ans);
	}
}