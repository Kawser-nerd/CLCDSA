import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		String S = sc.next();
		sc.close();

		int cnt=0,max=0;
		for(int i=0;i<n;i++) {
			if(S.substring(i, i+1).equals("I")) {
				cnt++;
				if(cnt>max)max=cnt;
			}else {
				cnt--;
			}
		}
		System.out.println(max);
	}

}