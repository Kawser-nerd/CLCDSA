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
		cin.nextLine();
		int[] t = Arrays.stream(cin.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		int cnt = 0;
		for (int i=1;i<N;i++){
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