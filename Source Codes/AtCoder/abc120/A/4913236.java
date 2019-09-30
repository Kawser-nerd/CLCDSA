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
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
//		int d = Integer.parseInt(sc.next());
		int count = 0;
		if(b/a>c){
			count = c;
		}else{
			count = b/a;
		}
		
	System.out.println(count);
	System.out.flush();
	sc.close();
	}
}