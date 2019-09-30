import java.util.*;
import java.math.*;
import java.io.*;

public class D{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		
		
		for(int kasus=1;kasus<=T;kasus++){
			int N = in.nextInt();
			int M = in.nextInt();
			
			int[] px = new int[N];
			int[] py = new int[N];
			double[] ans = new double[M];
			for(int i=0;i<N;i++){
				px[i] = in.nextInt();
				py[i] = in.nextInt();
			}
			
			for(int k2 = 0;k2<M;k2++){
				int qx = in.nextInt();
				int qy = in.nextInt();
				
				//System.out.println(qx+" "+qy+" "+px[0]+" "+px[1]+" "+py[0]+" "+py[1]);
				
				double[] rad = new double[N];
				for(int i=0;i<N;i++){
					rad[i] = Math.sqrt(Math.pow(1.0*qx-px[i],2)+Math.pow(1.0*qy-py[i],2));
				//	System.out.println("rad "+i+": "+rad[i]);
				}
				
				double d = Math.sqrt(Math.pow(px[1]-px[0],2)+Math.pow(py[1]-py[0],2));
				if(d > rad[0]+rad[1]){
					ans[k2]=0;
				}
				else if(d < Math.abs(rad[0]-rad[1])){
					double minrad = rad[0];
					int mi = 0;
					if(rad[1] < minrad){
						mi = 1;
						minrad = rad[1];
					}
					ans[k2]=Math.PI*minrad*minrad;
				}
				else{
					double c = Math.sqrt(Math.pow(px[1]-px[0],2)+Math.pow(py[1]-py[0],2));
					double CBA = Math.acos(((rad[1]*rad[1])+(c*c)-(rad[0]*rad[0]))/(2*rad[1]*c));
					double CBD = 2*CBA;
					
					double CAB = Math.acos(((rad[0]*rad[0])+(c*c)-(rad[1]*rad[1]))/(2*rad[0]*c));
					double CAD = 2 * CAB;
					
					double area = CBD*rad[1]*rad[1]/2 - rad[1]*rad[1]*Math.sin(CBD)/2
						+ CAD*rad[0]*rad[0]/2 - rad[0]*rad[0]*Math.sin(CAD)/2;
					
					ans[k2] = area;
					//~ double a = ((rad[0]*rad[0])-(rad[1]*rad[1])+(d*d))/(2.0*d);
					//~ double h2 = (rad[0] * rad[0]) - (a*a);
					
					
					//~ double h = Math.sqrt(h2);
					
					//~ double x2 = px[0]+(a*(px[1]-px[0])/d);
					//~ double y2 = py[0]+(a*(py[1]-py[0])/d);
					
					//~ double x31 = x2 + h*(py[1]-py[0])/d;
					//~ double y31 = y2 - h*(px[1]-px[0])/d;
					
					//~ double x32 = x2 - h*(py[1]-py[0])/d;
					//~ double y32 = y2 + h*(px[1]-px[0])/d;
					
					//~ //System.out.println("tes "+rad[0]+ " "+rad[1]);
					//~ //System.out.println(x31 + " " +y31+" "+x32+" "+y32);
					
					//~ double major = Math.sqrt(Math.pow(x31-x2,2)+Math.pow(y31-y2,2));
					
					//~ double minor = rad[0] - (Math.sqrt(Math.pow(px[0]-x2,2)+Math.pow(py[0]-y2,2)));
					
					
					//~ ans[k2]=Math.PI*major*minor;
				}
			}
			
			String ansstring = "";
			for(int i=0;i<M;i++){
				ansstring += String.format(" %.7f",ans[i]);
			}
			System.out.println("Case #"+kasus+":"+ansstring);
		}
	}
}