import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int d=sc.nextInt();
		int x=sc.nextInt();
		int X[]=new int[n];
		int ans=x;
		for(int i=0;i<n;i++)X[i]=sc.nextInt();
		for(int i=1;i<=d;i++) {
			for(int j=0;j<n;j++) {
				if((i-1)%X[j]==0)ans++;
			}
		}

		System.out.println(ans);
	}
}