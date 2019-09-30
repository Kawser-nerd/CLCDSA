import java.util.*;
import java.io.*;

public class MainC {
	
	static double f, R, r, t, g, rad, side;
	
	static double norm(double x, double y)
	{
		return Math.sqrt(x*x + y*y);
	}
	
	static double ISectArea(double x, double y)
	{
		if(norm(x,y) >= rad) return 0.0;
		if(norm(x+side, y+side) <= rad) return side*side;
		
		double x1, y1;
		double x2, y2;
		
		if(norm(x+side, y) >= rad)
		{
			y1 = y;
			x1 = Math.sqrt(rad*rad - y1*y1);
		}
		else
		{
			x1 = x+side;
			y1 = Math.sqrt(rad*rad - x1*x1);
		}
		
		if(norm(x, y+side) >= rad)
		{
			x2 = x;
			y2 = Math.sqrt(rad*rad - x2*x2);
		}
		else
		{
			y2 = y+side;
			x2 = Math.sqrt(rad*rad - y2*y2);
		}
		
		double theta = 2*Math.asin(norm(x1-x2, y2-y1)/(2*rad));
		
		
		double answer = 0.0;
		
		answer += rad*rad*(theta-Math.sin(theta))/2;
		answer += (x1-x2)*(y2-y1)/2;
		answer += (x1-x)*(y1-y);
		answer += (x2-x)*(y2-y);
		answer -= (x2-x)*(y1-y);
		
		return answer;
	}
	
	public static void main(String args[]) throws FileNotFoundException, IOException
	{
		Scanner in = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter("C-large.out");
		int cas = in.nextInt();
		for(int iii = 0; iii < cas; iii++)
		{
			f = in.nextDouble();
			R = in.nextDouble();			
			t = in.nextDouble();
			r = in.nextDouble();
			g = in.nextDouble();
			
			rad = R-t-f;
			side = g-(2*f);
			if(rad <= norm(r+f, r+f) || side <= 0.0)
			{
				out.println("Case #" + (iii+1) + ": 1.00000000");
				continue;
			}
			
			double temp = Math.sqrt(rad*rad - (r+f)*(r+f));
			temp -= (r+f);
			temp /= (2*r + g);
			int numRows = 1+(int)temp;
			
			double area = 0.0;
			
			for(int j = 0; j < numRows; j++)
			{
				double y = (r+f) + j*(2*r + g);
				
				temp = Math.sqrt(rad*rad - y*y);
				
				temp -= (r+f);
				temp /= (2*r+g);
				int numCols = 1+(int)temp;
				
				int numColsComplete;
				
				if(rad <= norm(y+side, r+f))
				{
					numColsComplete = 0;
				}
				else
				{
					temp = Math.sqrt(rad*rad - (y+side)*(y+side));
					temp -= (r+f);
					temp /= (2*r+g);
					numColsComplete = (int)temp;
				}
				
				area += numColsComplete*side*side;
				
				for(int i = numColsComplete; i < numCols; i++)
				{
					area += ISectArea((r+f) + i*(2*r + g), y);
				}
			}
			
			double answer = 1-(4*area/(Math.PI*R*R));
			
			out.printf("Case #%d: %.8f\n", (iii+1), answer);
			
		}
		out.close();
	}
}
