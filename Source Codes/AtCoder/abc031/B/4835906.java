import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int l = Integer.parseInt(sc.next());
		int h = Integer.parseInt(sc.next());
		int n = Integer.parseInt(sc.next());
		int[]a=new int[n];
		for(int i=0;i<n;i++)a[i]=Integer.parseInt(sc.next());
		sc.close();
		for(int i=0;i<n;i++) {
			if(h<a[i]) {
				System.out.println(-1);
				continue;
			}
			if(l>a[i])System.out.println(l-a[i]);
			else System.out.println(0);
		}
	}

}