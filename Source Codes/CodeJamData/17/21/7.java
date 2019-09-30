import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A
{
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; ++i) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			long D = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken());
			double ret = Double.POSITIVE_INFINITY;
			for (int j = 0; j < N; ++j) {
				st = new StringTokenizer(in.readLine());
				long K = Integer.parseInt(st.nextToken()); 
				long S = Integer.parseInt(st.nextToken());
				double myTime = D/ret, otherTime = (D-K)*1.0/S;
				if (myTime < otherTime) ret = D/otherTime;
			}
			System.out.printf("Case #%d: %f\n", i+1, ret);
		}
	}
}
