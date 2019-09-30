package round1a;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class A {
	
	int caseNo;
	double epsilon = 0.00000001;
	
	boolean equals(double a, double b) {
		return (Math.abs(a-b) < epsilon);
	}
	
	public void test(Scanner in) {
		
		
		long maxGamesToday = in.nextLong();
		int rateToday = in.nextInt();
		int rateTotal = in.nextInt();
		
		boolean possible = true;
		
		//first check if rateToday is possible
		
		//Obviously if 100 its easy to win that amount exactly
		if (maxGamesToday < 100) {
			
			boolean found = false;
			
			//final double desired = rateToday/100.0;
			//f/inal double mgt = (double)maxGamesToday;
			
			
			if (maxGamesToday >= 1) {  //100
				found |= (rateToday % 100 == 0);
			}
			if (maxGamesToday >= 2) {  //50
				found |= (rateToday % 50 == 0);
			}
			if (maxGamesToday >= 4) {  //25
				found |= (rateToday % 25 == 0);
			}
			if (maxGamesToday >= 5) {  //20
				found |= (rateToday % 20 == 0);
			}
			if (maxGamesToday >= 10) {  //10
				found |= (rateToday % 10 == 0);
			}
			if (maxGamesToday >= 20) {  //5
				found |= (rateToday % 5 == 0);
			}

			if (maxGamesToday >= 25) {  //4
				found |= (rateToday % 4 == 0);
			}
			if (maxGamesToday >= 50) {  //2
				found |= (rateToday % 2 == 0);
			}
			
			possible = found;
			
		}
		
		
		//if so do dummy check for rate total
		if (possible) {
			
			if (rateTotal == 0 && rateToday != 0) possible = false;
			if (rateTotal == 100 && rateToday != 100) possible = false;
			
		}
		
		
		if (possible)
			System.out.println("Case #"  + caseNo + ": Possible");
		else
			System.out.println("Case #"  + caseNo + ": Broken");			
		
	}
	
	

	public static void main(String[] args) throws Exception{
	
		(new A()).test();
		
	}

	public void test() throws Exception{

		Scanner s = new Scanner(new File("A-large.in"));

		int numTests = s.nextInt();

		for (caseNo = 1; caseNo <= numTests; caseNo++) {
			test(s);
		}

	}
}
