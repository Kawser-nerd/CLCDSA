import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int ans=0;
	Integer l[]=new Integer[n];
		for(int i=0;i<n;i++)l[i]=sc.nextInt();
		Arrays.sort(l,Comparator.reverseOrder());
		for(int i=0;i<m;i++)ans+=l[i];
		System.out.println(ans);
	}
}