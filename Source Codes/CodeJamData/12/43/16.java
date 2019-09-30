import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));

		L : for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt();
			int[] r = new int[n-1];
			for (int i = 0; i < n-1; i++) r[i] = in.nextInt()-1;
			
			if (r[n-2] != n-1) {
				out.println("Impossible");
				continue L;
			}
			
			int[] h = new int[n];
			h[n-1] = 0;
			h[n-2] = 0;
			Set<Integer> set = new HashSet<Integer>();
			set.add(n-1);
			set.add(n-2);
			
			for (int i = n-3; i >= 0; i--) {
				if (!set.contains(r[i])) {
					out.println("Impossible");
					continue L;
				}
				h[i] = 0;
				while (!can(i, r[i], h)) {
					h[i]++;
				}
				if (r[i] != n-1) while (can(i, r[r[i]], h)) {
					for (int j = r[i]; j < n; j++) {
						h[j]++;
					}
				}
				//System.out.println(Arrays.toString(h));
				
				set.add(i);
				for (int j = i+1; j < r[i]; j++) set.remove(j);
			}
			
			while (!check(r, h)){};
			
			for (int i = 0; i < n; i++) {
				out.print(h[i] + " ");
			}
			out.println();
		}
		
		out.flush();
	}

	static boolean can(int a, int b, int[] h) {
		boolean good = true;
		int dx1 = b - a, dy1 = h[b] - h[a];
		for (int i = a+1; i < b; i++) {
			good &= dy1*(i - a) > (h[i] - h[a])*dx1;
		}
		return good;
	}
	
	static boolean check(int[] r, int[] h) {
		int n = h.length;
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j > i; j--) {
				if (can(i, j, h)) {
					if (j == r[i]) break;
					else {
						for (int k = r[i]; k < n; k++) h[k]++;
						return false;
					}
				}
			}
		}
		return true;
	}
}
