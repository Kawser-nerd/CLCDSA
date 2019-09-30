import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class CenterOfMass {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("x.txt"));

			Scanner scan = new Scanner(in);

			int T = scan.nextInt();
			//scan.nextLine();
			for(int ii=0; ii<T; ii++)
			{
				int N = scan.nextInt();
				int[]x = new int[N];
				int[]y = new int[N];
				int[]z = new int[N];
				int[]vx = new int[N];
				int[]vy = new int[N];
				int[]vz = new int[N];
				
				
				xx = yy = zz = vxx = vyy = vzz = 0;
				for(int i=0; i<N; i++)
				{
					xx+= x[i] = scan.nextInt();
					yy+= y[i] = scan.nextInt();
					zz+= z[i] = scan.nextInt();
					vxx += vx[i] = scan.nextInt();
					vyy += vy[i] = scan.nextInt();
					vzz+= vz[i] = scan.nextInt();
				}
				
				xx /= (double)N;
				yy /= (double)N;;
				zz /= (double)N;;
				vxx /= (double)N;;
				vyy /= (double)N;;
				vzz /=(double)N;;
				double time = ternarySearch(0, 1e23, 1e-9);
				double dmin = f(time);
				out.write("Case #"+(ii+1)+": "+dmin+" "+time+"\n");
			}



			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	static double xx=0, yy=0, zz=0, vxx=0, vyy=0, vzz=0;
	private static double ternarySearch(double left, double right, double absolutePrecision) {
		//left and right are the current bounds; the maximum is between them
	    if (right-left < absolutePrecision) return (left+right)/2;
	    double leftThird = (left*2+right)/3;
	    double rightThird = (left+right*2)/3;
	    if (f(leftThird) > f(rightThird))
	        return ternarySearch(leftThird, right, absolutePrecision);
	    else
	        return ternarySearch(left, rightThird, absolutePrecision);
	}

	private static double f(double time) {
		
		double cx=0, cy=0, cz =0;
		cx = xx + vxx*time;
		cy = yy + vyy*time;
		cz = zz + vzz*time;
		
		return Math.sqrt(cx*cx +cy*cy + cz*cz);
		
	}

	
}
