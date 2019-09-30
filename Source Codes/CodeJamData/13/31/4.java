import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class GCJ_2013_C1 {

	public static long solve(String s, long n) {
		long bef_cont = 0;
		long bef_noncont = 0;
		long endpart = 0;
		
		System.out.println();
		
		for (int i=0;i<s.length();i++)
		{
			long bef_cont_prev = bef_cont;
			long bef_noncont_prev = bef_noncont;
			char c = s.charAt(i);
			boolean cns = !((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u'));

			bef_noncont = bef_noncont_prev + bef_cont_prev;
			if (cns)
			{
				endpart ++;
				if (endpart >= n)
				{
					bef_cont = (i-n+2);
				}
				else
				{
					bef_cont = bef_cont_prev;
				}
			}
			else
			{
				bef_cont = bef_cont_prev;
				endpart = 0;
			}
//			System.out.printf("%d %d -> %d %d\n",bef_cont_prev,bef_noncont_prev,bef_cont,bef_noncont);
		}
		return bef_cont + bef_noncont;
	}

	public static void main(String[] args) throws Exception {
//		String fname = "A_example";
//		String fname = "A_small";
		String fname = "A_large";
		
		File file = new File(fname+"_in.txt");
		Scanner scanner = new Scanner(file);

		FileWriter outFile = new FileWriter(fname+"_out.txt");
		PrintWriter outp = new PrintWriter(outFile);
		
		int T = scanner.nextInt();
		scanner.nextLine();
		for (int i=1;i<=T;i++)
		{
			String s = scanner.nextLine();
			String sin = s.split(" ")[0];
			int n = Integer.parseInt(s.split(" ")[1]);
			outp.printf("Case #%d: %d\n",i,solve(sin,n));
		}
		
		outp.close();

	}

}
