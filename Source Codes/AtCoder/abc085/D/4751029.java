import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		long h = Integer.parseInt(sc.next());
		Long[] Throw = new Long[n];
		long maxAP = 0;long t=0;
		for(int i=0;i<n;i++) {
			t = Long.parseLong(sc.next());
			Throw[i] = Long.parseLong(sc.next());
			if(t>maxAP)maxAP=t;
		}
		sc.close();
		Arrays.sort(Throw,Comparator.reverseOrder());

		int cnt=0;
		while(cnt<n&&0<h) {
			if(Throw[cnt]<=maxAP)break;
			h-=Throw[cnt];
			cnt++;
		}

		if(h > 0) {
			cnt+=h/maxAP+1;
			if(h%maxAP==0)cnt--;
		}
		System.out.println(cnt);
	}

}