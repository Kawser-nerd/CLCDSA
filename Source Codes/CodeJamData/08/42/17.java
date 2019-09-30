package round2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class P2 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("round2/p2.in"));
		
		FileWriter out = new FileWriter("p2.out");
		
		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			
			String res = solveOne(br);
			System.out.println("Case #" + i + ": " + res);
			out.write("Case #" + i + ": " + res + "\n");
		}
		br.close();
		out.close();
	}

	private static String solveOne(BufferedReader br) throws Exception {
		String parts[] = br.readLine().split("\\s+");
		int N = Integer.parseInt(parts[0]);
		int M = Integer.parseInt(parts[1]);
		int A = Integer.parseInt(parts[2]);
		if (A>N*M) return "IMPOSSIBLE";
		
		for (int x2=0; x2<=N; x2++)
			for (int y2=0; y2<=M; y2++)
				for (int x3=0; x3<=N; x3++)
					for (int y3=0; y3<=M; y3++) {
						if (A==Math.abs(x2*y3-x3*y2)) {
							return String.format("0 0 %d %d %d %d", x2, y2, x3, y3);
						}
					}
		
		return "IMPOSSIBLE";
	}

}
