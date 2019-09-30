import java.util.*;
public class Main{
	public static void main(String[]args) throws Throwable{
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		long k=sc.nextLong();
		Long[][]a=new Long[n][2];
		for(int i=0;i<n;i++) {
			a[i][0]=sc.nextLong();
			a[i][1]=sc.nextLong();
		}
		Arrays.sort(a,(x,y)->Long.compare(x[0], y[0]));
		for(int i=0;i<n;i++) {
			k-=(long)a[i][1];
			if(k<=0) {
				System.out.println(a[i][0]);
				break;
			}
		}
	}
}