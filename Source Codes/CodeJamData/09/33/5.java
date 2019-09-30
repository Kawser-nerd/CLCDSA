package r1c;

import java.io.FileReader;
import java.util.Scanner;

public class C {

	/**
	 * @param args
	 */
	static int[] release; 
	static long[][] table;
	
	public static long solve(int s, int e) {
		//System.out.println("Solving "+s+" to "+e+": ");
		if (s > e) {
			return 0;
		}
		if (table[s][e] != -1) {
			return table[s][e]; 
		}
		if (s==e) { //base case
			table[s][e] = release[e+1]-release[s-1]-2; 
			return table[s][e];
		} else {
			long min = release.length*release[release.length-1];
			long temp;
			for (int i = s; i<=e; i++) {
				temp = solve(s,i-1)+solve(i+1,e)+release[e+1]-release[s-1]-2;
				if (temp<min) {
					min = temp;
				}
			}
			table[s][e] = min;
			//System.out.println(min);
			return min;
		}
	}
	
	public static long answer(Scanner in) {
	
		int p = in.nextInt();
		int q = in.nextInt();
		
		release = new int[q+2];
		
		release[0] = 0;
		for (int i = 1; i<=q; i++) {
			release[i] = in.nextInt();
		}
		release[q+1] = p+1;
		
		table= new long[q+1][q+1];
		
		for (int i=0;i<=q;i++) {
			for (int j=0; j <= q; j++) {
				table[i][j] = -1;
			}
		}
		return solve(1,q);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner infile = new Scanner(new FileReader(args[0]));
			
			int t = infile.nextInt();
			infile.nextLine();
						
			for (int i = 0; i<t;i++) {
				
				System.out.print("Case #"+(i+1)+": ");
				System.out.println(answer(infile));
			}
			infile.close();

		} catch (Exception e) 
		{
			System.out.println("Exception occured, stacktrace to follow.");
			e.printStackTrace();
		}

	}

}
