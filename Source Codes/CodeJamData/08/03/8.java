import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.util.Scanner;

class Point2d {
	double x, y;
	public Point2d() {
		
	}
	public Point2d(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
}

public class FlySwatter {
	
	public double func(double x, double h, double k, double r) {
		double result = k;
		result -= Math.sqrt(-h*h +r*r + 2*h*x - x*x);
		return result;
	}
	
	/**
	 * integrate k - Sqrt[-h^2 + r^2 + 2 h x - x^2]
	 * @param left
	 * @param right
	 * @param h
	 * @param k
	 * @param r
	 * @return
	 */
	public double integrate(double left, double right, double h, double k, double r) {
		final int resolution = 5000;
		final double dx = (right - left)/resolution;
		double result = 0;
		//Use the Center rectangle approximation method
		for (int i = 0; i < resolution; i++) {
			result += func(left + dx * i + dx/2, h, k, r);
		}
		result *= dx;
		return result;
	}
	
	public void solve(Scanner in, PrintStream out) throws Exception {
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; test++) {
			// f, R, t, r and g
			final double f = in.nextDouble();	//fly radius
			final double R = in.nextDouble();	//Radius of large circle
			final double t = in.nextDouble();	//thickness of ring
			final double r = in.nextDouble(); //radius of string
			final double g = in.nextDouble(); //gap between strings
			
			double innerR = R - t - f; //inner ring
			//double flyInnerR = innerR - f;	//the real inner radius
			int numGaps = (int)Math.ceil(innerR/(g + 2 *r));
			//System.out.println("Num Gaps: " + numGaps);
			
			//Calculate the amount of area the fly's center can be such that it avoid being hit
			double wantTotal = 0.0;
			for (int y = 0; y < numGaps; y++) {
				for (int x = 0; x < numGaps; x++) {
					//Check if the bottom right corner is inside the inner ring
					Point2d br = new Point2d();
					br.x = x * (g + 2*r) + r + g - f;
					br.y = -1*(y * (g+2*r) + r + g - f);
					
					//Include the whole region
					if (Math.sqrt(br.x * br.x + br.y * br.y) < innerR) {
						//There before the whole box is inside the ring
						wantTotal += (g- 2*f) * (g-2*f);
						continue;
					}
					
					//Check if the top left corner is inside the inner ring
					Point2d tl = new Point2d();
					tl.x = x * (g + 2*r) + r + f;
					tl.y = -1 * (y * (g+2*r) + r + f);
					
					//Exclude the whole region
					if (Math.sqrt(tl.x * tl.x + tl.y * tl.y) > innerR) {
						//There before the whole box is outside the ring						
						continue;
					}
					
					//There are four cases otherwise use integration
					//intersect y^2+x^2=innerR^2 with y = h
					
					//The coordinates of the square is tl to br
					//The a to start integration, can't go past the left of the square
					//Do a check to see if the bottom of the circle never reaches the bottom
					double bottomInt = Math.sqrt(innerR * innerR - br.y * br.y);	//bottom intercept
					if (Double.isNaN(bottomInt)) {
						bottomInt = 0;	//Will be replaced with tl.x
					}
					double left = Math.max(tl.x, bottomInt);
					double right = Math.min(br.x, Math.sqrt(innerR * innerR - tl.y * tl.y));
					
					//integrate from left to right
					wantTotal += (g- 2*f) * (g-2*f);
					wantTotal -= integrate(left - tl.x, right - tl.x,-tl.x,-br.y,innerR);					
					
					//Finish the leftover the rectangle
					wantTotal -= (br.x - right) * (tl.y - br.y);					
					
				}
			}
			
			
			double prob;	//prob = want /total
			//you only calculated one quarter of the circle
			wantTotal *= 4;
			if (g - 2 * f < 0) {
				wantTotal = 0;
			}
			
			//total = area of large circle
			prob = 1 - wantTotal/(Math.PI * R * R);
			
			DecimalFormat format = new DecimalFormat("#0.000000");
			out.println("Case #" + test + ": " + format.format(prob));
			
			
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = null;
		PrintStream out = null;
		in = new Scanner(System.in);
		out = System.out;
		in = new Scanner(new FileReader("C-large.in"));
		out = new PrintStream(new FileOutputStream("C-large.out"));
		new FlySwatter().solve(in, out);
		out.close();
		System.exit(0);
	}
}
