import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;


public class Goats {
	static void deal(String file) throws Exception{
		BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(file),"utf-8"));
		int T = Integer.parseInt(r.readLine());
		for(int no = 1; no <= T; no++){
			String[] NM = r.readLine().split("\\s");
			int n = Integer.parseInt(NM[0]);
			int m = Integer.parseInt(NM[1]);
			int px[] = new int[n];
			int py[] = new int[n];
			int qx[] = new int[m];
			int qy[] = new int[m];
			for(int i = 0; i < n; i++){
				String xy[] = r.readLine().split("\\s");
				px[i] = Integer.parseInt(xy[0]);
				py[i] = Integer.parseInt(xy[1]);
			}
			for(int i = 0; i < m; i++){
				String xy[] = r.readLine().split("\\s");
				qx[i] = Integer.parseInt(xy[0]);
				qy[i] = Integer.parseInt(xy[1]);
			}
			double[] a = new double[m];
			for(int i = 0; i < m; i++){
				double r0 = Math.sqrt((px[0]-qx[i])*(px[0]-qx[i])+(py[0]-qy[i])*(py[0]-qy[i]));
				double r1 = Math.sqrt((px[1]-qx[i])*(px[1]-qx[i])+(py[1]-qy[i])*(py[1]-qy[i]));
				double l = Math.sqrt((px[1]-px[0])*(px[1]-px[0])+(py[1]-py[0])*(py[1]-py[0]));
				double p = (r0+r1+l)/2;
				double sTriangle = Math.sqrt(p*(p-r0)*(p-r1)*(p-l));
				double h = 2*sTriangle/l;
				if(h>=r1)
					h = r1;
				if(h>=r0)
					h = r0;
				double arch0 = 2*Math.asin(h/r0);
				double arch1 = 2*Math.asin(h/r1);
				double sT0 = h*(Math.cos(arch0/2)*r0);
				double sT1 = h*(Math.cos(arch1/2)*r1);
				if(l*l + r0*r0 < r1*r1)
					arch0 = 2*Math.PI - arch0;
				
				if(l*l + r1*r1 < r0*r0)
					arch1 = 2*Math.PI - arch1;
				
				double s0;
				if(arch0 > Math.PI){
					s0 = arch0*r0*r0/2+sT0;
				}else{
					s0 = arch0*r0*r0/2-sT0;
				}
				double s1;
				if(arch1 > Math.PI){
					s1 = arch1*r1*r1/2+sT1;
				}else{
					s1 = arch1*r1*r1/2-sT1;
				}
				double s = s0+s1;
				a[i] = s;
			}
			out.print("Case #"+no+":");
			for(int i = 0; i < m; i++){
				out.print(" "+a[i]);
			}
			out.println(); 
		}
	}
	
	static PrintStream out;
	public static void main(String[] args) throws Exception{
		out = new PrintStream(new FileOutputStream("result.txt"));
		deal("test.txt");
		out.flush();
		out.close();
	}
}
