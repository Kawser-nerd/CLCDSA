package r1c;

import java.io.FileReader;
import java.util.HashMap;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	
	public static long answer(String in) {
	
		HashMap<Character,Integer> h = new HashMap<Character,Integer>();
		
		boolean zeroUsed=false;
		int big=1;
		for (int i = 0; i<in.length(); i++) {
			if (h.get(in.charAt(i)) == null) {
				if (big > 1 &&  zeroUsed==false) {
					zeroUsed = true;
					h.put(in.charAt(i),0);
				} else {
					h.put(in.charAt(i), big);
					big++;
				}
			}
		}
		
		long out = 0;
		for (int i= 0; i< in.length(); i++) {
			out = out*big+h.get(in.charAt(i));
		}
		
		return out;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner infile = new Scanner(new FileReader(args[0]));
			
			int t = infile.nextInt();
			infile.nextLine();
						
			for (int i = 0; i<t;i++) {
				
				System.out.print("Case #"+(i+1)+": ");
				System.out.println(answer(infile.nextLine()));
			}
			infile.close();

		} catch (Exception e) 
		{
			System.out.println("Exception occured, stacktrace to follow.");
			e.printStackTrace();
		}

	}

}
