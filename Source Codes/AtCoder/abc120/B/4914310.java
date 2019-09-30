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
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());

		int c = Integer.parseInt(sc.next());
//		int d = Integer.parseInt(sc.next());
		int count = 0;
		if(a<b){
			for(int i = 0; i < a; i++){
				int d = i+1;
				if(a%d == 0 && b%d == 0){
					list.add(d);
				}
			}
		}else{
			for(int i = 0; i < b; i++){
				int d = i+1;
				if(a%d == 0 && b%d == 0){
					list.add(d);
				}
		}
		}
		
		System.out.println(list.get(list.size()-c));
		System.out.flush();
		sc.close();

	}
}