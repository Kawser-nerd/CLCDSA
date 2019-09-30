import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int a[]=new int [n];
		for(int i=0;i<n;i++) {
			a[i]=scanner.nextInt();
		}
		
		int maxt=-1000000000;
		int inds[]=new int[n];
		for(int tk=0;tk<n;tk++) {
			int maxa=-1000000000;
			int ind=0;
			for(int ao=0;ao<n;ao++) {
				if(tk!=ao) {
					int tmp=check(tk,ao,a);
					if(maxa<tmp) {
						maxa=tmp;
						ind=ao;
					}
				}
			}
			maxt=Math.max(maxt, calc(tk,ind,a));
		}
		System.out.println(maxt);
	}

	private static int calc(int tk, int ind, int[] a) {
		int sc=0;
		int sm=0;
		int bi=0;
		if(tk<ind) {
			sm=tk;
			bi=ind;
		}else {
			sm=ind;
			bi=tk;
		}
		int cnt=1;
		for(int i=sm;i<=bi;i++) {
			if(cnt%2==1) {
				sc+=a[i];
			}
			cnt++;
		}
		return sc;
	}

	private static int check(int tk, int ao, int[] a) {
		int sc=0;
		int sm=0;
		int bi=0;
		if(tk<ao) {
			sm=tk;
			bi=ao;
		}else {
			sm=ao;
			bi=tk;
		}
		int cnt=1;
		for(int i=sm;i<=bi;i++) {
			if(cnt%2==0) {
				sc+=a[i];
			}
			cnt++;
		}
		return sc;
	}

}