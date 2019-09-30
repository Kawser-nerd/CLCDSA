import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t = 1; t <= T;t++){
			int a1 = sc.nextInt();
			int a2 = sc.nextInt();
			int b1 = sc.nextInt();
			int b2 = sc.nextInt();
			long ans = 0;
			for(int a = a1; a <= a2;a++)
				ans += num(a,b1,b2);
			for(int b = b1; b <= b2;b++)
				ans += num(b,a1,a2);
			System.out.format("Case #%d: %d\n",t,ans);
		}
	}

	public static int solve(int a,int b){
		if (a == 0 || b == 0)
			return 1;
		if(a == b)
			return 0;
		if(a < b)
			return solve(b,a);
		if(a >= 2*b)
			return 1;
		else
			return 1-solve(a%b,b);
	}

	public static long num(int a, int b1, int b2){
		int low = 0;
		int high = a-1;
		int far = 0;
		while(low <= high){
			int mid = (low+high)/2;
			if(solve(a,mid) == 1){
				low = mid+1;
				far = mid;
			}else{
				high = mid-1;
			}
		}
		int add = 0;
		if(b1 <= far)
			add = min(b2,far)-b1 +1;
		return add;
	}
}
