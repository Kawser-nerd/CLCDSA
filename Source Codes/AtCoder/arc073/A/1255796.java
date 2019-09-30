import java.util.*;
import java.io.*;
//import java.util.stream.Stream;
import static java.lang.Math.*;

public class Main {
	Scanner cin;

	void init() throws Exception {
		cin = new Scanner(new BufferedInputStream(System.in));
//		cin = new Scanner(new File("in.txt"));
//		System.setOut(new PrintStream(new File("out.txt")));
		solve();
	}

	void solve() {
		int N = cin.nextInt();
		int T = cin.nextInt();
		int[] t = new int[N];
		int cnt = 0;
		t[0] = cin.nextInt();
		for (int i=1;i<N;i++){
			t[i] = cin.nextInt();
			cnt += min(t[i]-t[i-1], T);
		}
		cnt += T;
		System.out.println(cnt);
	}

	public static void main(String[] args) throws Exception {
		Main M = new Main();
		M.init();
	}

}