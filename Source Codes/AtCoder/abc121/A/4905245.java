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
//		String [][] boad = new String[4][4];
		int h1 = Integer.parseInt(sc.next());
		int w1 = Integer.parseInt(sc.next());
		int h2 = Integer.parseInt(sc.next());
		int w2 = Integer.parseInt(sc.next());
		int count = 0;
		if(h1==h2 && w1==w2){
			count =0;
		}else{
			count = h1*w1 -(h2*w2 + (h2*(w1-w2)) + (w2*(h1-h2)));
		}
		
	System.out.println(count);
	System.out.flush();
	sc.close();
	}
}