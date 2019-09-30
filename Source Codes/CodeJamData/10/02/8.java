package qualification.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class B {
	
	Scanner in;	
	
	public B() {		
		in = new Scanner(System.in);
		
		int t = in.nextInt();
		for(int l=1;l<=t;l++){
			int n = in.nextInt();
			
			ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
			for(int i=0;i<n;i++){
				arr.add(in.nextBigInteger());
			}
			
			BigInteger min = arr.get(0);
			for(int i=1;i<n;i++){
				if(min.compareTo(arr.get(i))>0){
					min = arr.get(i);
				}
			}
			
			//System.out.println(min);
			
			for(int i=0;i<n;i++){
				arr.set(i, arr.get(i).subtract(min));
				//System.out.println(arr.get(i));
			}
			
			BigInteger gcd = arr.get(0);
			for(int i=1;i<n;i++){
				gcd = gcd.gcd(arr.get(i));
			}
			
			//System.out.println(gcd);
			
			BigInteger div = min.divide(gcd);
			
			BigInteger ans = gcd.multiply(div.add(BigInteger.ONE)).subtract(min);
			//System.out.println(ans);
			
			if(ans.equals(gcd)){
				System.out.printf("Case #%d: 0\n", l);
			} else {
				System.out.printf("Case #%d: %s\n", l, ans);
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
			String p = "B-large-practice";		
			System.setIn(B.class.getResourceAsStream(p+".in"));
			System.setOut(new PrintStream(new File("src/qualification/b/"+p+".out")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}		
		
		new B();
	}

}
