import java.util.*;
public class Main{
	int n;
	int[]t;
	long q=1000000007;
	Main(){
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		t=new int[n];
		for(int i=0;i<n;i++) {
			t[i]=sc.nextInt();
		}
		Arrays.sort(t);
		System.out.println(calc(0,0));
		if(n==1) {
			System.out.println(1);
			return;
		}
		int idx=0,cnt=0;
		long ans=1;
			for(;idx<n;idx++) {
				if(cnt==0) {
					cnt++;
					continue;
				}
				if(t[idx]==t[idx-1]) {
					cnt++;
				}else {
					ans=(ans*kaijo(cnt))%q;
					cnt=1;
				}
				if(idx==n-1) {
					ans=(ans*kaijo(cnt))%q;
				}
			}
		System.out.println(ans);
	}
	long calc(int idx,long sum) {
		if(idx<n) {
			sum+=t[idx];
			return calc(idx+1,sum)+sum;
		}else {
			return 0;
		}
	}

	long kaijo(long a) {
		return(a==1?1:a*kaijo(a-1)%q);
	}
	public static void main(String[]args) {
		new Main();
	}
}