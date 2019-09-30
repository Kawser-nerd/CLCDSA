import java.util.Arrays;
import java.util.Scanner;

class Main {
	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int h=scanner.nextInt();
		int[] a=new int[n];
		int[] b=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=scanner.nextInt();
			b[i]=scanner.nextInt();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		int l=-1;
		int r=b.length;
		while(r-l>1) {
			int mid=(l+r)/2;
			if(a[n-1]<b[mid]) {
				r=mid;
			}else {
				l=mid;
			}
		}
		int d=0;
		int cnt=0;
		for(int i=r;i<n;i++) {
			d+=b[n-1-i+r];
			cnt++;
			if(d>=h) {
				System.out.println(cnt);
				return;
			}
		}
		h-=d;
		System.out.println(cnt+(int)Math.ceil((double)h/a[n-1]));
	}
}