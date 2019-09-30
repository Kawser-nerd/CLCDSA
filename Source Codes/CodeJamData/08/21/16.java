import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Task1a {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedInputStream(new FileInputStream("in.txt")));
			PrintStream out = new PrintStream(new BufferedOutputStream(new FileOutputStream("out.txt")));
			
			
			int TT = in.nextInt();
			for(int tt=0;tt<TT;tt++)
			{
				int n = in.nextInt();
				int A = in.nextInt();
				int B = in.nextInt();
				int C = in.nextInt();
				int D = in.nextInt();
				long X0 = in.nextInt();
				long Y0 = in.nextInt();
				int M = in.nextInt();
				
				long[] x = new long[n];
				long[] y = new long[n];
				
				x[0] = X0;
				y[0] = Y0;
				
				long[] c = new long[9];
				
				for(int i = 1 ;i< n;i++)
				{
					X0 = (A * X0 + B) % M;
					Y0 = (C * Y0 + D) % M;
					x[i]= X0;
					y[i] = Y0;
				}
				for(int i = 0 ;i< n;i++)
					c[(int)(x[i]%3*3+y[i]%3)]++;
				
				System.out.println(Arrays.toString(c));
															
				long res = 0;
				for(int i = 0 ;i<3;i++)
					for(int j = 0;j<3;j++) {
						long br = c[i*3+j];					
						if (br>=3)
						res+= br*(br-1)*(br-2)/3/2;
					}
				
				for(int i = 0 ;i<3;i++) {
					res+= c[i*3]*c[i*3+1]*c[i*3+2];
					res+= c[i]*c[i+3*1]*c[i+3*2];
				}
				
				res+= c[0]*c[3+1]*c[6+2];
				res+= c[0]*c[6+1]*c[3+2];
				res+= c[3+0]*c[0+1]*c[6+2];
				res+= c[3+0]*c[6+1]*c[0+2];
				res+= c[6+0]*c[3+1]*c[0+2];
				res+= c[6+0]*c[0+1]*c[3+2];
				
				out.format("Case #%d: %d\n", 1+tt,res);
				
			}
			in.close();
			out.flush();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
