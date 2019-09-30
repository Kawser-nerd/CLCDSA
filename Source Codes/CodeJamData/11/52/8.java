package round3;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	static class Niz {
		int zadnji, duzina;
		Niz(int element) {
			duzina = 1;
			zadnji = element;
		}
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		int tt = in.nextInt();
		for (int ttt = 1; ttt <= tt; ttt++) {
			int n = in.nextInt();
			int[] t = new int[n];
			for (int i = 0; i < n; i++)
				t[i] = in.nextInt();
			int res = 0;
			if (n > 0) {
				Arrays.sort(t);
				ArrayList<Niz> nizovi = new ArrayList<B.Niz>();
				for (int i = 0; i < n; i++) {
					Niz a = null;
					for (Niz niz : nizovi)
						if (niz.zadnji == t[i] - 1
								&& (a == null || a.duzina > niz.duzina))
							a = niz;
					if (a == null)
						nizovi.add(new Niz(t[i]));
					else {
						a.duzina++;
						a.zadnji = t[i];
					}
				}
				res = n;
				for (Niz niz : nizovi)
					if (niz.duzina < res)
						res = niz.duzina;
			}
			out.printf("Case #%d: %d", ttt, res);
			out.println();
		}
		out.flush();
		out.close();
		in.close();
	}
}
