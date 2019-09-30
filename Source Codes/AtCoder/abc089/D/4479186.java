import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int H = Integer.parseInt(sc.next());
		int W = Integer.parseInt(sc.next());
		int D = Integer.parseInt(sc.next());

		HashMap<Integer, Integer> ty = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> tx = new HashMap<Integer, Integer>();

		for(int i=1;i<=H;i++) {
			for(int j=1;j<=W;j++) {
				int a = Integer.parseInt(sc.next());
				ty.put(a,i);
				tx.put(a,j);
			}
		}
		int[] d = new int [90001];
		for(int i=D+1;i<=H*W;i++) {
			d[i]=d[i-D]+Math.abs(ty.get(i)-ty.get(i-D))+Math.abs(tx.get(i)-tx.get(i-D));
		}
		StringBuilder buf = new StringBuilder();
		int Q = Integer.parseInt(sc.next());
		while(Q>0) {
			int L = Integer.parseInt(sc.next());
			int R = Integer.parseInt(sc.next());
			buf.append(d[R]-d[L]+System.getProperty("line.separator"));
			Q--;
		}
		sc.close();
		System.out.println(buf);
    }
}