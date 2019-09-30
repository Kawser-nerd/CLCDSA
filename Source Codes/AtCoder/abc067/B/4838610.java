import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		Integer[]l=new Integer[n];
		for(int i=0;i<n;i++) {
			l[i]=sc.nextInt();
		}
		Arrays.sort(l,Collections.reverseOrder());
		int ans=0;
		for(int i=0;i<k;i++) {
			ans+=l[i];
		}
		System.out.println(ans);
	}
}