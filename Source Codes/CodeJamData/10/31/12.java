package gcj2010r1c.a;

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
				int n = Integer.parseInt(nums[0]);
				int[] a = new int[n];
				int[] b = new int[n];
				for (int j=0; j<n; j++) {
					line = reader.readLine();
					nums = line.split(" ");
					a[j] = Integer.parseInt(nums[0]);
					b[j] = Integer.parseInt(nums[1]);
				}
				
				System.out.print("Case #");
				System.out.print(i+1);
				System.out.print(": ");
				System.out.println(countIntersect(a,b));					
			}
			
			System.err.println("Elasped Time : "+(System.currentTimeMillis()-startTime));
			reader.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static int countIntersect(int[] a, int[] b) {
		int n = a.length;
		int c=0;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if ((a[i]-a[j])*(b[i]-b[j])<0) c++;
			}
		}
		return c;
	}

}
