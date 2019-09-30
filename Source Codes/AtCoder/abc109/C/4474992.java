import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      int[] a=new int[n+1];
      for(int i=0;i<n+1;i++)a[i]=sc.nextInt();
      Arrays.sort(a);
      for(int i=1;i<n+1;i++)a[i]-=a[0];
      int m=a[1];
      for(int i=1;i<n+1;i++)m=gcd(m,a[i]);
      System.out.println(m);
	}
  public static long gcd(long m, long n) {
		if(m < n) return gcd(n, m);
	    if(n == 0) return m;
	    return gcd(n, m % n);
	}
  public static int gcd(int m, int n) {
		if(m < n) return gcd(n, m);
	    if(n == 0) return m;
	    return gcd(n, m % n);
	}

}