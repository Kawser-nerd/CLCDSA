import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		int x=scanner.nextInt();
		int y=scanner.nextInt();
		Long a[]=new Long[n];
		Long b[]=new Long[m];
		for(int i=0;i<n;i++) {
			a[i]=scanner.nextLong();
		}
		for(int i=0;i<m;i++) {
			b[i]=scanner.nextLong();
		}
		long t=0;
		int cnt=0;
		while (true) {
			int au = upper_bound(Arrays.asList(a), t-1);
			if(au==a.length) break;
			t+=a[au]-t+x;
			int bu = upper_bound(Arrays.asList(b), t-1);
			if(bu==b.length) break;
			t+=b[bu]-t+y;
			cnt++;
		}
		System.out.println(cnt);
		
	}
	private static int upper_bound(List<Long> list, long val) {
		return ~Collections.binarySearch(list, val, (x, y) -> x.compareTo(y) > 0 ? 1 : -1);
	}

}