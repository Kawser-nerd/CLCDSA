import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main (String [] args){
		ArrayList <Integer> list = new ArrayList<Integer>();
//		String [][] boad = new String[4][4];
		double a = Double.parseDouble(sc.next());
		double b = Double.parseDouble(sc.next());

//		int c = Integer.parseInt(sc.next());
//		int d = Integer.parseInt(sc.next());
		double count = 0;
		
		count = a/b;
		
		
		System.out.println(count);
		System.out.flush();
		sc.close();

	}
}