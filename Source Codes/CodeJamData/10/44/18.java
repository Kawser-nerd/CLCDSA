import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Set;


public class AAAGoats {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		int T = Integer.parseInt(in.readLine());
		for (int t=1;t<=T;t++) {
			System.out.print("Case #"+t+": ");
			String arr[] = in.readLine().split(" ");
			int N = Integer.parseInt(arr[0]);
			int M = Integer.parseInt(arr[1]);
			int x1,x2,y1,y2;
			arr = in.readLine().split(" ");
			x1 = Integer.parseInt(arr[0]);
			y1 = Integer.parseInt(arr[1]);
			arr = in.readLine().split(" ");
			x2 = Integer.parseInt(arr[0]);
			y2 = Integer.parseInt(arr[1]);
			int[][] foo = new int[M][2];
			for (int i=0;i<M;i++) {
				arr = in.readLine().split(" ");
				foo[i][0] = Integer.parseInt(arr[0]);
				foo[i][1] = Integer.parseInt(arr[1]);
			}
			System.out.println(doit(x1,y1,x2,y2,foo));
		}
	}

	private static String doit(int x1, int y1, int x2, int y2, int[][] foo) {
		String s="";
		for (int i=0;i<foo.length;i++) {
			if (i>0)
				s+=" ";
			s+=
				String.format("%.7f",doit(x1,y1,x2,y2,foo[i]));
		}
		return s;
	}
static 	double dist(int x1,int y1, int x2, int y2) {
	int a = x2-x1;
	int b=y2-y1;
	return Math.sqrt(a*a + b*b);
}
	private static double doit(int x1, int y1, int x2, int y2, int[] foo) {
		double r1 = dist(x1,y1,foo[0],foo[1]);
		double r2 = dist(x2,y2,foo[0],foo[1]);
		double c = dist(x1,y1,x2,y2);
		double cosCBA = (r2*r2 + c*c - r1*r1)/(2*r2*c);
		double CBA = Math.acos(cosCBA);
		double CBD = 2*CBA;
		double cosCAB = (r1*r1+c*c-r2*r2)/(2*r1*c);
		double CAB = Math.acos(cosCAB);
		double CAD = 2*CAB;
		double area = .5*CBD*r2*r2 - .5*r2*r2*Math.sin(CBD);
		area += .5*CAD*r1*r1 - .5*r1*r1*Math.sin(CAD);
		return area;
	}
}
