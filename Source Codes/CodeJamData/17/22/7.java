import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B
{
	//ROYGBV
	static int[][] nbrs = new int[6][];
	static int R = 0, O = 1, Y = 2, G = 3, B = 4, V = 5;
	static
	{
		nbrs[R] = new int[]{R,O,V};
		nbrs[O] = new int[]{O,R,Y,V,G};
		nbrs[Y] = new int[]{Y,O,G};
		nbrs[G] = new int[]{O,Y,G,B,V};
		nbrs[B] = new int[]{V,B,G};
		nbrs[V] = new int[]{O,R,V,B,G};
	}
	static int[] makeCnts(int[] c) {
		int[] ret = new int[6];
		for (int r = 0; r < 6; ++r) {
			for (int s = 0; s < nbrs[r].length; ++s) {
				ret[r] += c[nbrs[r][s]];
			}
		}
		return ret;
	}
	static boolean isIn(int[] a, int x) {
		for (int i : a) if (i == x) return true;
		return false;
	}
	static int getNext(int last, int first, int[] c, boolean isFinal) {
		int ret = -1;
		boolean retFirst = true;
		int[] cnts = makeCnts(c);
		for (int i = 0; i < 6; ++i) {
			boolean inLast = last == -1 ? false : isIn(nbrs[last],i);
			boolean inFirst = first == -1 ? false : isIn(nbrs[first],i);
			if (inLast || c[i] == 0 || isFinal && inFirst) continue;
			if (ret == -1 || cnts[ret] < cnts[i] || cnts[ret] == cnts[i] && !retFirst && inFirst) {
				ret = i;
				retFirst = inFirst;
			}
		}
		return ret;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String str = "ROYGBV";
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; ++i) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int[] cnts = new int[6];
			int N = Integer.parseInt(st.nextToken());
			for (int c = 0; c < 6; ++c) cnts[c] = Integer.parseInt(st.nextToken());
			StringBuilder ret = new StringBuilder();
			int last = -1, first = -1;
			for (int a = 0; a < N; ++a) {
				int pos = getNext(last, first, cnts, a == N-1);
				//System.out.printf("cnts=%s, last = %d, first = %d, pos = %d\n", Arrays.toString(cnts),last,first,pos);
				if (pos == -1) break;
				ret.append(str.charAt(pos));
				cnts[pos]--;
				last = pos;
				if (first == -1) first = pos;
			}
			System.out.printf("Case #%d: %s\n", i+1, ret.length() == N ? ret.toString() : "IMPOSSIBLE");
		}
	}
}

