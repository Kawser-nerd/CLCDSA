import java.util.*;
import java.util.stream.*;

public class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		long x=s.nextInt();
		long[][] a=new long[n][n];
		Arrays.setAll(a[0],i->s.nextLong());
		for(int j=0;j<n;++j){
			for(int i=1;i<n;++i){
				a[i][j]=Math.min(a[i-1][j],a[0][(j-i+n)%n]);
			}
		}
		System.out.println(IntStream.range(0,n)
				.mapToLong(i->i*x+Arrays.stream(a[i]).sum())
				.min().getAsLong());
	}
}