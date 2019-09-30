import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		int x = Integer.parseInt(sc.next());
		
		int[] a = new int[n];
		
		for(int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(sc.next());
		}
		
		Arrays.sort(a);
		
		int res = 0;
		
		for(int i = 0; i < n-1; i++) {
			if(a[i]<= x) {
				x-=a[i];
				res++;
			}else{
				break;
			}
		}
		
		if( x == a[a.length-1]) {
			res++;
		}
		
		System.out.println(res);
	}
}