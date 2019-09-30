import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
public class ProperShuffle {
	public final static String INPUT_FILE_NAME = "C-small-attempt0(1).in";
	public final static String OUTPUT_FILE_NAME = "ProperShuffle.out";
	public static void main(String[] args) {
		try (Scanner in = new Scanner(new FileReader(INPUT_FILE_NAME));
				PrintWriter out = new PrintWriter(new FileWriter(
						OUTPUT_FILE_NAME))) {
			double[][] rv = new double[1000][1000];
			for(int t = 0; t < 1000; t ++)
			{
				double[] cv = new double[1000];
				for(int i = 0; i < 1000; i ++)
				{
					if(i==t)
					{
						cv[i] = 1;
					}
					else
					{
						cv[i] = 0;
					}
				}
				
				for(int i = 0; i < 1000; i ++)
				{
					double[] nv = new double[1000];
					for(int j = 0; j < 1000; j ++)
					{
						if(i != j)
						{
							nv[j] = cv[j]*.999 + cv[i]*.001;
						}
					}
					nv[i] = .001;
					
					cv = nv;
				}
				rv[t] = cv;
				//System.out.println(Arrays.toString(rv[t]));
			}
			System.out.println("done");
			int numT = in.nextInt();
			int res = 0;
			for (int t = 1; t <= numT; t++) {
				in.nextInt();
				double total = 0;
				for(int i = 0; i < 1000; i ++)
				{
					int v = in.nextInt();
					total += rv[v][i];
				}
				if(total <=1.005)
				{
					out.println("Case #"+t+": GOOD");
					res ++;
				}
				else
				{
					out.println("Case #"+t+": BAD");
				}
			}
			System.out.println(res);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
