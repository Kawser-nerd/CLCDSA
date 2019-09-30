import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt()*2;
		int[]l=new int[n];
		for(int i=0;i<n;i++) {
			l[i]=sc.nextInt();
		}
		Arrays.sort(l);
		int ans=0;
		for(int i=0;i<n;i+=2) {
			ans+=l[i];
		}
		System.out.println(ans);
	}
}