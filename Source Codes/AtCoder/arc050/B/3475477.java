import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long r = sc.nextLong();
		long b = sc.nextLong();
		long x = sc.nextLong();
		long y = sc.nextLong();
		long low = 0L;
		long upp = Math.min(r, b) + 1;
		long mid = (low + upp) / 2;
		while(upp-low>1){
			if((r-mid)/(x-1)+(b-mid)/(y-1)>=mid){
				low = mid;
				mid = (low + upp) / 2;
			}
			else{
				upp = mid;
				mid = (low + upp) / 2;
			}
		}
		System.out.println(mid);
	}
}