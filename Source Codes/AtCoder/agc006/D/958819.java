import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int L = 2*N-1;
		int[] a = new int[L];
		for(int i=0; i<L; i++)
			a[i] = sc.nextInt();
		
		int min = 1;
		int max = L;
		boolean b[] = new boolean[L];
		while(min+1 < max) {
			int mid = (min + max)/2;
			for(int i=0; i<L; i++)
				b[i] = a[i]>=mid;
			if(satisfy(b))
				min = mid;
			else
				max = mid;
		}
		System.out.println(min);
		
		sc.close();
	}
	
	static boolean satisfy(boolean[] b) {
		int L = b.length;
		int N = (L+1)/2;

		int l = N-1;
		while(l>0 && b[l]!=b[l-1])
			l--;

		int r = N-1;
		while(r<L-1 && b[r]!=b[r+1])
			r++;
		
		if(l>0) {
			if(r<L-1) {
				if(b[l]==b[r])
					return b[l];
				else
					return (l+r)/2>=N-1 ? b[l] : b[r];
			} else {
				return b[l];
			}
		} else if(r<L-1) {
			return b[r];
		} else {
			return b[N-1] ^ N%2==0;
		}
	}
}