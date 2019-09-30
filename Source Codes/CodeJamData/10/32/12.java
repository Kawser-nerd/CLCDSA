package gcj2010r1c.b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			
			BufferedReader reader;
			if (args.length>0) {
				reader = new BufferedReader(new FileReader(args[0]));
			} else {
				reader = new BufferedReader(new InputStreamReader(System.in));				
			}
			String line = null;
			line = reader.readLine();
			int caseCount = Integer.parseInt(line);
						
			long startTime = System.currentTimeMillis();

			for (int i=0; i<caseCount; i++) {
				line = reader.readLine();
				String[] nums = line.split(" ");
				int l = Integer.parseInt(nums[0]);
				int p = Integer.parseInt(nums[1]);
				int c = Integer.parseInt(nums[2]);
				
				System.out.print("Case #");
				System.out.print(i+1);
				System.out.print(": ");
				System.out.println(countTest(l,p,c));					
			}
			
			System.err.println("Elasped Time : "+(System.currentTimeMillis()-startTime));
			reader.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static int countTest(int l, int p, int c) {
		double max = ((double)p)/((double)l);
		double ml = Math.log(max)/Math.log(c);
		double result = Math.ceil(Math.log(ml)/Math.log(2));
		if (result<0) return 0;
		return (int)result;
	}

}
