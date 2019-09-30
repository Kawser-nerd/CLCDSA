import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int[] a = new int[k];
		for(int i=0;i<k;i++) {
			a[i]=sc.nextInt();
		}
		
		long max = 2;
		long min = 2;
		
		
		for (int i=k-1;i>=0;i--) {
			max = (long)Math.floor((double)max/a[i])*a[i]+a[i]-1;
			min = (long)Math.ceil((double)min/a[i])*a[i];
			
		}
		
		if (max<min) {
			System.out.println(-1);
		} else {
			System.out.println(min+" "+max);
		}
	}

}