import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		List<Integer> list = new ArrayList<Integer>();
		for(int i=0;i<n;i++)list.add(Integer.parseInt(sc.next()));
		sc.close();

		List<Integer> res = new ArrayList<Integer>();
		for (int i=n-1;i>=0;i--) {
			for (int j=i;j>=0;j--) {
				if (list.get(j)==j+1) {
					res.add(j+1);
					list.remove(j);
					break;
				}
			}
		}

		if (res.size()==n)for (int i=n-1;i>=0;i--)System.out.println(res.get(i));
		else System.out.println(-1);
	}
}