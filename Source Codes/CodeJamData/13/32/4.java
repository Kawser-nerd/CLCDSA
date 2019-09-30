import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class GCJ_2013_C2 {

	public static String solve(int x, int y) {
		StringBuffer s = new StringBuffer("");
		for (int i=0;i<Math.abs(x);i++)
		{
			if (x<0)
				s.append("EW");
			else
				s.append("WE");
		}
		for (int i=0;i<Math.abs(y);i++)
		{
			if (y<0)
				s.append("NS");
			else
				s.append("SN");
		}
		return s.toString();
	}

	public static void main(String[] args) throws Exception {
//		String fname = "B_example";
		String fname = "B_small";
//		String fname = "B_large";
		
		File file = new File(fname+"_in.txt");
		Scanner scanner = new Scanner(file);

		FileWriter outFile = new FileWriter(fname+"_out.txt");
		PrintWriter outp = new PrintWriter(outFile);
		
		int T = scanner.nextInt();
		for (int i=1;i<=T;i++)
		{
			int x = scanner.nextInt();
			int y = scanner.nextInt();
			outp.printf("Case #%d: %s\n",i,solve(x,y));
		}
		
		outp.close();

	}

}
