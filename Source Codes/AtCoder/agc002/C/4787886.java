import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int l=sc.nextInt();
		int[]a=new int[n];
		int lastIdx = 0;
		boolean b=true;
		a[0]=sc.nextInt();
		for(int i=1;i<n;i++) {
			a[i]=sc.nextInt();
			if(b&&a[i-1]+a[i]>=l) {
				b=false;
				lastIdx=i;
			}
		}
		if(b) {
			System.out.println("Impossible");
			return;
		}
		System.out.println("Possible");
		for(int i=1;i<lastIdx;i++) {
			System.out.println(i);
		}
		for(int i=n-1;i>=lastIdx;i--) {
			System.out.println(i);
		}
	}
}