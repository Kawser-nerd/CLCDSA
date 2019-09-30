import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		Integer[]x=new Integer[m];
		for(int i=0;i<m;i++) {
			x[i]=sc.nextInt();
		}
		Arrays.sort(x);
		Integer[]dif=new Integer[m-1];
		for(int i=0;i<m-1;i++) {
			dif[i]=x[i+1]-x[i];
		}
		Arrays.sort(dif);
		int ans=0;
		for(int i=0;i<m-n;i++) {
			ans+=dif[i];
		}
		System.out.println(ans);
	}
}