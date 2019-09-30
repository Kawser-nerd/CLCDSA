import java.util.*;
import java.io.*;

public class SavingTheUniverse {
	void doMain() throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int cases = Integer.parseInt(br.readLine());
		for (int caseNum=0; caseNum<cases; caseNum++) {
			pw.print("Case #" + (caseNum+1) + ": ");
			int S = Integer.parseInt(br.readLine());
			String[] eng = new String[S];
			for (int i=0; i < S; i++)
				eng[i] = br.readLine();
			int Q = Integer.parseInt(br.readLine());
			String[] que = new String[Q];
			for (int i=0; i < Q; i++)
				que[i] = br.readLine();
			if (Q == 0) {
				pw.println(0);
				continue;
			}
			int[] F = new int[Q+1];
			Arrays.fill(F, 1000000);
			F[0] = 0;
			for (int i=0; i < Q; i++) {
				for (int j=0; j < S; j++) {
					if (que[i].equals(eng[j])) continue;
					int k = i;
					while (k + 1 < Q && !que[k + 1].equals(eng[j])) k++;
					F[k + 1] = Math.min(F[k + 1], F[i] + 1);
				}
			}
			pw.println(F[Q]-1);
		}
		pw.flush();
		pw.close();
		br.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new SavingTheUniverse()).doMain();
	}
}
