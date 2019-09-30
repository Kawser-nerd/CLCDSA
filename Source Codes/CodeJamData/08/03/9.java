package emm.cj08;

import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Fly {
	private static final File IN = new File("/home/eric/cj/fly-in.txt"), OUT = new File("/home/eric/cj/fly-out.txt");
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(IN));
		PrintStream ps = new PrintStream(OUT);
		
		int trials = Integer.parseInt(br.readLine());
		ArrayList<Double> probs = new ArrayList<Double>(trials);
		
		for(int trial = 0; trial < trials; trial++) {
			String[] line = br.readLine().trim().split(" ");
			
			double f = Double.parseDouble(line[0]);
			double R = Double.parseDouble(line[1]);
			double t = Double.parseDouble(line[2]);
			double r = Double.parseDouble(line[3]);
			double g = Double.parseDouble(line[4]);
			
			if(f * 2 >= g || R - t - f * 2 - r <= 0) {
				probs.add(1.);
				continue;
			}
			
			r += f;
			g -= f * 2;
			t += f;
			
			BigDecimal squareSum = BigDecimal.ZERO;
			int gridDim = (int)((R - t) / (g + 2 * r) + 3);
			double rSq = square(R - t);
			int fullCount = 0;
			
			for(int x = 0; x < gridDim; x++)
				for(int y = 0; y < gridDim; y++) {
					double minX = (g + 2 * r) * x + r;
					double minY = (g + 2 * r) * y + r;
					
					if(minX * minX + minY * minY >= rSq)
						continue;
					
					if(square(minX + g) + square(minY + g) < rSq) {
						fullCount++;
						continue;
					}
					
					double maxX = Math.min(minX + g, Math.sqrt(rSq - minY * minY));
					
					double xInt = Math.sqrt(rSq - square(minY + g));
					double result;
					
					if(Double.isNaN(xInt) || xInt < minX)
						result = integral(maxX, minY, rSq) - integral(minX, minY, rSq);
					else
						result = integral(maxX, minY, rSq) - integral(xInt, minY, rSq) + (xInt - minX) * g;
					
					squareSum = new BigDecimal(result).add(squareSum, MathContext.UNLIMITED);
				}
			
			
			squareSum = squareSum.add(new BigDecimal(g * g * fullCount), MathContext.UNLIMITED);
			
			double prob = 1 - squareSum.doubleValue() / (R * R * Math.PI / 4);
			
			
			probs.add(prob);
		}
		
		DecimalFormat df = new DecimalFormat("0.000000");
		for(int trial = 0; trial < trials; trial++)
			ps.println("Case #" + (trial + 1) + ": " + df.format(probs.get(trial)));
		
		br.close();
		ps.close();
	}
	
	private static double square(double x) {
		return x * x;
	}
	
	private static double integral(double x, double minY, double rSq) {
		return .5 * x * Math.sqrt(rSq - x * x) + .5 * rSq * Math.asin(x / Math.sqrt(rSq)) - x * minY; 
	}
}
