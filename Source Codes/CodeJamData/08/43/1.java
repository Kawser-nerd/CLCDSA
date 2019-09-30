import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemC {
	int N;
	int[] x, y, z, p;
	
	double calc(double xx, double yy, double zz) {
		double res = 0.0;
		for (int i=0; i < N; i++)
			res = Math.max(res, (Math.abs(xx-x[i]) + Math.abs(yy-y[i]) + Math.abs(zz-z[i])) / (double)p[i]);
		return res;
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			N = sc.nextInt();
			x = new int[N];
			y = new int[N];
			z = new int[N];
			p = new int[N];
			for (int i=0; i < N; i++) {
				x[i] = sc.nextInt();
				y[i] = sc.nextInt();
				z[i] = sc.nextInt();
				p[i] = sc.nextInt();
			}
			double curx = 500000, cury = 500000, curz = 500000;
			double curF = calc(curx, cury, curz);
			double dir = 500000;
			while (dir > 1e-7) {
				double best = curF;
				double bx = curx, by = cury, bz = curz;
				boolean find = false;
				for (int a=0; a<6; a++)
					for (int b=0; b<6; b++) {
						double a1 = 2 * Math.PI * a / 6.0;
						double a2 = 2 * Math.PI * b / 6.0;
						double nx = curx + dir * Math.cos(a2) * Math.cos(a1);
						double ny = cury + dir * Math.cos(a2) * Math.sin(a1);
						double nz = curz + dir * Math.sin(a2);
						double nf = calc(nx, ny, nz);
						if (nf < best) {
							best = nf;
							bx=nx; by=ny; bz=nz;
							find = true;
						}
					}
				if (!find) dir /= 2.0;
				else {
					curx=bx; cury=by; curz=bz;
					curF = best;
				}
			}
			pw.println(curF);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemC()).doMain();
	}
}