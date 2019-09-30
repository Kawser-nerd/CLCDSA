import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){
//		String [][] boad = new String[4][4];
		String s1 = sc.next();
		if(s1.equals("A")){
			s1 = "T";
		}else if(s1.equals("T")){
			s1 = "A";
		}
		
		if(s1.equals("G")){
			s1 = "C";
		}else if(s1.equals("C")){
			s1 = "G";
		}
			
	System.out.println(s1);
	System.out.flush();
//		BigDecimal xx1 = new BigDecimal(Integer.parseInt(sc.next()));
//		double c = 0;
//		System.out.println();
//		System.out.flush();
		sc.close();
	}
}