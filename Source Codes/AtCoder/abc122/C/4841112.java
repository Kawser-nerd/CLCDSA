import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		String s = sc.next();
		int[] t = new int[n+1];
		int i;
		t[0]=0;
		for(i=1; i<n; i++) {
			t[i] = t[i-1] + ((s.charAt(i-1) == 'A' && s.charAt(i) == 'C')?1:0); 
		}
		t[i] = t[i-1];
		int l,r;
		for(i=0; i<q; i++) {
			l=sc.nextInt();
			r=sc.nextInt();
			System.out.println(t[r-1]-t[l-1]);
		}
	}
}