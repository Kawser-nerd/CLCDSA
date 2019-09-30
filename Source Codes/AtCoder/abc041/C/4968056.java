import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[][]a=new int[n][2];
		for(int i=0;i<n;i++) {
			a[i][0]=sc.nextInt();
			a[i][1]=i+1;
		}
		Arrays.sort(a,(x,y)->Integer.compare(y[0], x[0]));
		for(int i=0;i<n;i++) {
			System.out.println(a[i][1]);
		}
	}
}