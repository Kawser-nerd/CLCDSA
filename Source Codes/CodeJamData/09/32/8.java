package gcj2009.round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.ObjectInputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;

public class CenterOfMass {
	
	public static final String path = "google/gcj2009/round1c/resources";
	public static final String inFile = "B-large.in";
	public static final String outFile = "B-large.out";
	public static final String objFile = "B.obj";
	

	static double x, y, z, vx, vy, vz;
	
	static double distP() {
		return Math.sqrt(x*x+y*y+z*z); 
	}
	
	static String fmt(double dist, double time) {
		return Double.toString(dist)+" "+Double.toString(time);
	}
	
	static boolean isNull(double d) {
		return Math.abs(d) <= 1e-6;
	}
	
	static double vlen() {
		return Math.sqrt(vx*vx+vy*vy+vz*vz);
	}
	
	static double scal() {
		return x*vx + y*vy + z*vz;
	}
	
	public static String solve(BufferedReader in) throws Exception {
		int n = Integer.parseInt(in.readLine().trim());
		
		x = .0; y= .0; z= .0; vx= .0; vy= .0; vz= .0; 
		for (int i=0; i<n; i++) {
			String [] ss = in.readLine().trim().split(" ");
			x += Double.parseDouble(ss[0]);
			y += Double.parseDouble(ss[1]);
			z += Double.parseDouble(ss[2]);
			vx += Double.parseDouble(ss[3]);
			vy += Double.parseDouble(ss[4]);
			vz += Double.parseDouble(ss[5]);
		}
		x/=n;
		y/=n;
		z/=n;
		vx /= n;
		vy /= n;
		vz /= n;
		
		System.out.println(String.format("%.6f %.6f %.6f %.6f %.6f %.6f", x, y, z, vx, vy, vz));
		
		if (isNull(vx) && isNull(vy)  && isNull(vz) ) return fmt(distP(), 0);
		if (isNull(distP())) return fmt(distP(), 0);
		if (scal() >= 0 || isNull(scal())) return fmt(distP(), 0);
		
		double vv = - scal()/(vlen());
		
		double time = vv/vlen();
		double xx = x + vx*time;
		double yy = y + vy*time;
		double zz = z + vz*time;
		System.out.println(String.format("%.6f %.6f %.6f", xx, yy, zz));
		
		double len = Math.sqrt(xx*xx+yy*yy+zz*zz);
		return fmt(len, time);
		
	}
	
	
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader in = new BufferedReader(new FileReader(path + "/" + inFile));
		BufferedWriter out = new BufferedWriter(new FileWriter(path + "/" + outFile));
		
//		ObjectInputStream obj = new ObjectInputStream(new FileInputStream(path + "/" + objFile));		
//		res = (int[])obj.readObject();
		
		
		
		int ncases = Integer.parseInt(in.readLine().trim());
		for (int i=0; i<ncases; i++) {
			String res = solve(in);
			System.out.println("Handled case: "+(i+1));
			out.write("Case #"+(i+1)+": "+res+"\n");			
		}
		in.close();
		out.close();
	}
}
