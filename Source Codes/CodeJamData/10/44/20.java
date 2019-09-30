import java.io.*;
import java.util.*;
import java.math.*;

public class GrazingGoogleGoats extends Template {
	public GrazingGoogleGoats(String inputFileName, String outputFileName) {
		super("Grazing Google Goats Files", inputFileName, outputFileName, true);
	}

	int n, m;
	int[] px, py, qx, qy;
	double answer[];
	
	static BigDecimal PI = new BigDecimal(Math.PI);
	static BigDecimal TWO = new BigDecimal(2);
	static BigDecimal FOUR = new BigDecimal(4);

	protected void init() {
	
	}
	
	private final double distance(int x1, int y1, int x2, int y2) {
		return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
	}

	protected void algorithm() {
		// solve only small case
		answer = new double[m];
		for (int i = 0; i < m; i++) {
			/*
			double r = distance(px[0], py[0], qx[i], qy[i]);
			double R = distance(px[1], py[1], qx[i], qy[i]);
			if (r > R) {
				double temp = r;
				r = R;
				R = temp;
			}
			double d = distance(px[0], py[0], px[1], py[1]);
			if (r + R <= d)
				answer[i] = 0;
			else {
				double r2 = r * r;
				double R2 = R * R;
				double d2 = d * d;
				
				BigDecimal br = new BigDecimal(r);
				BigDecimal bR = new BigDecimal(R);
				BigDecimal bd = new BigDecimal(d);
				
				BigDecimal br2 = new BigDecimal(r2);
				BigDecimal bR2 = new BigDecimal(R2);
				BigDecimal bd2 = new BigDecimal(d2);
				
				answer[i] = PI.multiply(br2).
				subtract(br2.multiply(new BigDecimal(Math.acos(bR2.subtract(br2).subtract(bd2).divide(TWO.multiply(bd).multiply(br), 10, RoundingMode.HALF_UP).doubleValue())))).
				add(bR2.multiply(new BigDecimal(Math.acos(bR2.subtract(br2).add(bd2).divide(TWO.multiply(bR).multiply(bd), 10, RoundingMode.HALF_UP).doubleValue())))).
				subtract(br.multiply(bR).divide(TWO, 10, RoundingMode.HALF_UP).multiply(new BigDecimal(Math.sqrt(FOUR.subtract(bd2.subtract(bR2).subtract(br2).pow(2).divide(br2.multiply(bR2), 10, RoundingMode.HALF_UP)).doubleValue()))))
				.doubleValue();
				
				answer[i] = Math.PI * r2 
					- r2 * Math.acos((R2 - r2 - d2) / (2 * d * r))
					+ Math.acos((-r2 + R2 + d2) / (2 * R * d)) * R2
					- (r * R / 2) * Math.sqrt(4 - Math.pow(d2 - R2 - r2, 2) / (r2 * R2));
		
			}
			*/
			double r0 = distance(px[0], py[0], qx[i], qy[i]);
			double r1 = distance(px[1], py[1], qx[i], qy[i]);
			double ab = distance(px[0], py[0], px[1], py[1]);
			double c = ab;
			double cbd = 2 * Math.acos((r1*r1 + c*c - r0*r0) / (2 * r1 * c));
			double cad = 2 * Math.acos((r0*r0 + c*c - r1*r1) / (2 * r0 * c));
			answer[i] = 0.5 * cbd * r1*r1 - 0.5 * r1*r1 * Math.sin(cbd)
						+ 0.5 * cad * r0*r0 - 0.5 * r0*r0 * Math.sin(cad);
		}
	}

	protected void readInputFileOneCase() throws IOException {
		readLineToken();
		n = getTokenInt();
		m = getTokenInt();
		px = new int[n];
		py = new int[n];
		for (int i = 0; i < n; i++) {
			readLineToken();
			px[i] = getTokenInt();
			py[i] = getTokenInt();
		}
		qx = new int[m];
		qy = new int[m];
		for (int i = 0; i < m; i++) {
			readLineToken();
			qx[i] = getTokenInt();
			qy[i] = getTokenInt();
		}
	}

	protected void writeOutputFileOneCase() throws IOException {
		for (int i = 0; i < m; i++) {
			write(answer[i], 7);
			if (i != m-1)
				write(" ");
		}
		writeLine();
	}

	public static void main(String[] args) {
		//new GrazingGoogleGoats("GrazingGoogleGoats.in.txt", "GrazingGoogleGoats.out.txt");
		new GrazingGoogleGoats("D-small-attempt2.in.txt", "D-small-attempt2.out.txt");
		//new GrazingGoogleGoats("D-large.in.txt", "D-large.out.txt");
	}
}
