import java.util.*;
public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String __[]){
		int n=s.nextInt(),x=s.nextInt(),ar[]=new int[n],init[]=new int[n];
		for(int i=0;i<n;i++) {
			ar[i]=s.nextInt();
			init[i]=ar[i];
		}
		ar[0]=Math.min(ar[0],x);
		for(int i=1;i<n;i++) {
			ar[i]=Math.min(ar[i], x-ar[i-1]);
		}
		long res=0;
		for(int i=0;i<n;i++)
			res+=init[i]-ar[i];
		System.out.println(res);
	}
}