import java.io.*;
import java.util.*;

public class Magick {

	public static void main(String args[]) throws Exception {
		String file =
		//	"B-example.in"
		//	"B-small-attempt0.in"
			"B-large.in"
		;
		BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter(file + ".out"));
		final int T = Integer.parseInt(in.readLine());
		for(int casenr = 1; casenr  <= T; casenr++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int list[] = new int[150];
			int len = 0;
			int combines[][] = new int[26][26];
			boolean opposes[][] = new boolean[26][26];
			for(int i = 0; i < 26; i++)
				for(int j = 0; j < 26; j++)
					combines[i][j] = -1;
			int C = Integer.parseInt(st.nextToken());
			for(int i = 0; i < C; i++) {
				String combine = st.nextToken();
				int a = combine.charAt(0) - 'A';
				int b = combine.charAt(1) - 'A';
				int c = combine.charAt(2) - 'A';
				combines[a][b] = c;
				combines[b][a] = c;
			}
			int D = Integer.parseInt(st.nextToken());
			for(int i = 0; i < D; i++) {
				String oppose = st.nextToken();
				int a = oppose.charAt(0) - 'A';
				int b = oppose.charAt(1) - 'A';
				opposes[a][b] = true;
				opposes[b][a] = true;
			}
			int N = Integer.parseInt(st.nextToken());
			String invoke = st.nextToken();
		_FOR:
			for(int i = 0; i < N; i++) {
				int a = invoke.charAt(i) - 'A';
				while(len > 0) {
					int b = list[len - 1];
					int c = combines[a][b];
					if(c < 0)
						break;
					len--;
					a = c;
				}
				for(int j = len; --j >= 0; ) {
					int b = list[j];
					if(opposes[a][b]) {
						len = 0;
						continue _FOR;
					}
				}
				list[len++] = a;
			}
			StringBuilder sb = new StringBuilder();
			sb.append('[');
			for(int i = 0; i < len; i++) {
				if(i > 0)
					sb.append(", ");
				sb.append((char)(list[i] + 'A'));
			}
			sb.append(']');
			out.println("Case #" + casenr + ": " + sb);
			out.flush();
		}
		out.close();
	}
}
