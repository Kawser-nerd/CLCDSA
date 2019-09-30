//Doing this on dialup from my camping trip in Montana. =)

import java.io.*;
import java.util.*;

public class StarWars {

	public static void main(String[] args) throws FileNotFoundException {
		String inFile = "C-large.in";
		String outFile = "c.out";
		Scanner s = new Scanner(new File(inFile));
		PrintWriter out = new PrintWriter(new File(outFile));
		int caseCount = s.nextInt();
		
		for(int caseNum = 1; caseNum <= caseCount; caseNum++){
			int N = s.nextInt();
			double[] x = new double[N];
			double[] y = new double[N];
			double[] z = new double[N];
			double[] p = new double[N];
			
			double xmin=0, xmax=0, ymin=0, ymax=0, zmin=0, zmax=0;
			for (int i = 0; i < N; i++){
				x[i] = s.nextInt();
				y[i] = s.nextInt();
				z[i] = s.nextInt();
				p[i] = s.nextInt();
				if(i==0){
					xmin = x[i];
					xmax = x[i];
					ymin = y[i];
					ymax = y[i];
					zmin = z[i];
					zmax = z[i];
				} else {
					xmin = Math.min(x[i], xmin);
					xmax = Math.max(x[i], xmax);
					ymin = Math.min(y[i], ymin);
					ymax = Math.max(y[i], ymax);
					zmin = Math.min(z[i], zmin);
					zmax = Math.max(z[i], zmax);
				}
			}
			
			double xx = x[0], yy = y[0], zz = z[0];
			double nextxx = xx, nextyy = yy, nextzz = zz;
			double lowestPower = Double.POSITIVE_INFINITY;
			double jump = Math.max(Math.max(xmax - xmin, 1), Math.max(ymax - ymin, zmax - zmin));
			double initialJump = jump;
			while(jump  > 1e-10){
				for(int sx = -1; sx <= 1; sx++){
					double tx = xx + sx * jump;
					for(int sy = -1; sy <= 1; sy++){
						double ty = yy + sy * jump;
						for(int sz = -1; sz <= 1; sz++){
							if(jump == initialJump || sx != 0 || sy != 0 || sz != 0){
								double power = 0;
								double tz = zz + sz * jump;
								for(int i = 0; i < N; i++){
									double thisPower = (Math.abs(x[i] - tx) + Math.abs(y[i] - ty) + Math.abs(z[i] - tz)) / p[i];
									power = Math.max(power, thisPower);
								}
								if(power < lowestPower){
									nextxx = tx;
									nextyy = ty;
									nextzz = tz;
									lowestPower = power;
								}
							}
						}
					}
				}
//				System.out.println(xx + " " + yy + " " + zz + " " + jump);
				xx = nextxx;
				yy = nextyy;
				zz = nextzz;
				jump /= 2; 
			}
			
//			System.out.println("Best pos: " + xx + " " + yy + " " + zz);
			System.out.println("Case #" + caseNum + ": " + lowestPower);
			out.println("Case #" + caseNum + ": " + lowestPower);
//			out.println("Case #" + caseNum + ": " + (bestCount + 1));
			
			
		}
		
		s.close();
		out.close();
//		inFile.close();
	}
}
