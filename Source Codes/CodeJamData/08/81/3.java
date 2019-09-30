import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemA {
	int[] xo, yo, xi, yi;

	double getRatio(double x1, double y1, double x2, double y2, double x0, double y0) {
		double A = y2 - y1;
		double B = x1 - x2;
		double C = - A * x1 - B * y1;
		double AP = B, BP = -A;
		double CP = - AP * x0 - BP * y0;
		double d_all = Math.sqrt((x2 - x1)*(x2-x1) + (y2-y1)*(y2-y1));
		double xp = (CP * B - C * BP) / (A * BP - AP * B);
		double yp = (CP * A - C * AP) / (B * AP - BP * A);
		double d = Math.sqrt((xp-x1)*(xp-x1) + (yp-y1)*(yp-y1));
		return d / d_all;
	}

	double getZ(double x0, double y0, double x1, double y1, double x2, double y2) {
		double A = y2 - y1;
		double B = x1 - x2;
		double C = -A * x1 - B * y1;
		return (A * x0 + B * y0 + C) / Math.sqrt(A*A+B*B);
	}

	boolean inside(double x0, double y0, double x1, double y1, double x2, double y2,
			double x3, double y3) {
		double Z1 = getZ(x0, y0, x1, y1, x2, y2);
		double Z2 = getZ(x0, y0, x2, y2, x3, y3);
		double Z3 = getZ(x0, y0, x3, y3, x1, y1);
		if (Z1>=-1e-9 && Z2>=-1e-9 && Z3>=-1e-9) return true;
		if (Z1<=1e-9 && Z2<=1e-9 && Z3<=1e-9) return true;
		return false;
	}

	double f(double cx, double cy) {
		if (!inside(cx, cy, xi[0], yi[0], xi[1], yi[1], xi[2], yi[2]))
			return 1e100;
		double R1 = getRatio(xo[0], yo[0], xo[1], yo[1], cx, cy);
		double R2 = getRatio(xo[0], yo[0], xo[2], yo[2], cx, cy);
		double R3 = getRatio(xi[0], yi[0], xi[1], yi[1], cx, cy);
		double R4 = getRatio(xi[0], yi[0], xi[2], yi[2], cx, cy);
		return (R1 - R3)*(R1 - R3) + (R2 - R4) * (R2 - R4);
	}

	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ":");
			xo = new int[3];
			yo = new int[3];
			xi = new int[3];
			yi = new int[3];
			for (int i=0; i < 3; i++) {
				xo[i] = sc.nextInt();
				yo[i] = sc.nextInt();
			}
			for (int i=0; i < 3; i++) {
				xi[i] = sc.nextInt();
				yi[i] = sc.nextInt();
			}
			double cx = (xi[0] + xi[1] + xi[2]) / 3.0;
			double cy = (yi[0] + yi[1] + yi[2]) / 3.0;
			double step = 20000.0;
			double best = f(cx, cy);
			while (step >= 1e-9) {
				double curBest = best;
				double bx = cx, by = cy;
				boolean find = false;
				for (int i=0; i < 8; i++) {
					double nx = cx + step * Math.cos(Math.PI * i / 4.0);
					double ny = cy + step * Math.sin(Math.PI * i / 4.0);
					double ff = f(nx, ny);
					if (ff < curBest) {
						curBest = ff;
						bx = nx; by = ny;
						find = true;
					}
				}
				if (find) {
					cx = bx; cy = by; best = f(cx, cy);
				} else step /= 2;
			}
			if (best <= 1e-8) {
				pw.println(" "+cx+" "+cy);
			} else pw.println("No Solution");
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemA()).doMain();
	}
}