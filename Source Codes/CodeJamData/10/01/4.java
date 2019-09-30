package qualification.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	
	Scanner in;	
	
	public A() {		
		in = new Scanner(System.in);
		
		int t = in.nextInt();
		for(int l=1;l<=t;l++){
			int n = in.nextInt();
			int k = in.nextInt();
			
			int bit = (1<<n)-1;
			if(bit==(k&bit)){
				System.out.printf("Case #%d: ON\n", l);
			} else {
				System.out.printf("Case #%d: OFF\n", l);
			}
			
		}
		
	}

	public static void main(String[] args) {
		
		try {
			/*
			 * sample
			 * ?-small-practice
			 * ?-large-practice
			 */		
			String p = "A-large-practice";		
			System.setIn(A.class.getResourceAsStream(p+".in"));
			System.setOut(new PrintStream(new File("src/qualification/a/"+p+".out")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}		
		
		new A();
	}

}
