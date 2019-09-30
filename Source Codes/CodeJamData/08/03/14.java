import java.lang.Math;
import java.io.*;

public class probC {
    
    //Find area of intersection of triangle with verts (0,0) (x,0) (x,y) and the circle of radius r
    private static double triangleSector(double r, double x, double y) {
	if (x==0) return 0;
	if (y<0) {
	    x *= -1;
	    y *= -1;
	}
	if (Math.abs(x) > r) {
	    double theta = Math.atan(y/x);
	    return r*r*theta/2;
	}

	double y2 = Math.sqrt(r*r-x*x);
	if (y < y2) {
	    return x*y/2;
	}

	double theta1 = Math.atan(y2/x);
	double theta2 = Math.atan(y/x);
	return x*y2/2 + r*r*(theta2-theta1)/2;
    }
    
    private static double rectAtCenter(double r, double x, double y) {
	return triangleSector(r,x,y) + triangleSector(r,y,x);	
    }

    private static double rectSector(double r, double x1, double y1, double x2, double y2) {
	return (rectAtCenter(r,x2,y2) - rectAtCenter(r,x1,y2)) - (rectAtCenter(r,x2,y1) - rectAtCenter(r,x1,y1));
    }

    public static void main(String[] args) throws Exception{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	int N = Integer.parseInt(in.readLine());
	for (int i=0; i<N; i++) {
	    String s = in.readLine();
	    int k = 0;
	    double[] num = new double[5];
	    for (int j=0; j<5; j++) {
		int h = s.indexOf(' ', k+1);
		if (h==-1) h=s.length();
		num[j] = Double.parseDouble(s.substring(k,h));
		k = h;
	        //System.out.println(num[j]);
	    }
	    //System.out.println();
	    double p = oneCase(num[0],num[1],num[2],num[3],num[4]);
	    System.out.println("Case #" + (i+1) + ": " + p);
	}
    }

    public static double oneCase(double f, double R, double t, double r, double g) {
	if (2*f  > g) return 1;

	//Area where fly would miss if center is there
	double miss = 0;

	int d = (int) (R / (g+2*r)) + 1;
	for (int i=-d; i<d; i++) {
	    double rowMiss = 0; //Groups to avoid rounding error
	    for (int j=-d; j<d; j++) {
		double x = i*(g+2*r)+r;
		double y = j*(g+2*r)+r;
		rowMiss += rectSector(R-t-f, x+f, y+f, x+g-f, y+g-f);
	    }
	    miss += rowMiss;
	}

	double pMiss = miss / (Math.PI*R*R);
	return 1 - pMiss;
    }

}