import static java.lang.Math.floor;
import static java.lang.Math.log10;
import static java.lang.Math.max;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;
import static java.util.Arrays.asList;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws Exception{
		
//		System.out.println(isPalindrom(11));
//		System.out.println(isPalindrom(121));
//		System.out.println(isPalindrom(120021));
//		System.out.println(isPalindrom(120121));
//		System.out.println(isPalindrom(1200110021));
		List<String>[] table1 = new List[51];
		List<String>[] table2 = new List[51];
		table1[1] = asList("1", "2", "3");
		table2[1] = new ArrayList<String>();
		
		PrintStream writer = new PrintStream(new File("output"));
		for (int i= 2; i <= 50; i++){
			table1[i] = oneStartedList(i, table1);
			
//			System.out.printf("\n%d digits: \n", i);
//			for (String num : table1[i]){
//				System.out.println(num);
//			}
			
			table2[i] = twoStartedList(i);
		}
		
		
		Scanner scanner = new Scanner(new File("C-large-2.in"));
		
		int T = scanner.nextInt();
		for (int c = 0; c < T; c++){
			String a = scanner.next();
			String b = scanner.next();
			BigInteger ai = new BigInteger(a);
			BigInteger bi = new BigInteger(b);
			
			int count = 0;
			for (int i = 1; i<= 50; i++){
				boolean done = false;
				List<String> list = new ArrayList<String>();
				list.addAll(table1[i]);
				list.addAll(table2[i]);
				
				for (String num : list){
					
					BigInteger numSquare = new BigInteger(num).pow(2);
					if (numSquare.compareTo(bi) > 0){
						done = true;
						break;
					}
					else if (numSquare.compareTo(ai) >= 0)
					{
						count++;
					}
				}
				
				if (done)
					break;
//				if (isPalindrom(i)){
//					long ipower = (long) i*i;
//					if (ipower >= a && ipower <= b && isPalindrom(ipower)){
//						System.out.printf("[%d: %d]\n", i, ipower);
//						count++;
//					}
//				}
			}
			
			System.out.printf("Case #%d: %d\n", c+1, count);
			writer.printf("Case #%d: %d\n", c+1, count);
		}
	}
	
	
	static List<String> twoStartedList(int nDigits ){
		List<String> ret = new ArrayList<String>();
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < nDigits; i++){
			sb.append(0);
		}
		sb.setCharAt(0, '2');
		sb.setCharAt(nDigits-1, '2');
		
		
		ret.add(sb.toString());
		if (nDigits %2 == 1){
			sb.setCharAt(nDigits/ 2, '1');
			ret.add(sb.toString());
		}
		
		return ret;
	}
	
	static List<String> oneStartedList(int nDigits, List<String>[] table1){
		
		List<String> ret = new ArrayList<String>();
		ret.addAll(oneStartedList(nDigits, new ArrayList<String>()));
		for (int i = nDigits%2; i < nDigits; i+=2){
			if (i == 0)
				continue;
			ret.addAll(oneStartedList(nDigits, table1[i]));
		}
		return ret;
	}
	
	static List<String> oneStartedList(int nDigits, List<String> subList){
		List<String> ret = new ArrayList<String>();
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < nDigits; i++){
			sb.append(0);
		}
		sb.setCharAt(0, '1');
		sb.setCharAt(nDigits-1, '1');
		
		
		if (subList.size() == 0)
		{
			ret.add(sb.toString());
			return ret;
		}
		
		
		for (String subStr : subList){
			int startIndex = (nDigits - subStr.length()) / 2;
			for (int i = 0; i < subStr.length(); i++){
				sb.setCharAt(startIndex + i, subStr.charAt(i));
			}
			String d = sb.toString();
			BigInteger num = new BigInteger(d);
			if (isPalindrom(num.pow(2).toString()))
				ret.add(sb.toString());
		}
		
		return ret;
	}
	static boolean isPalindrom(String a){
		int n = a.length();
		for (int i = 0; i < n / 2; i++){
			if (a.charAt(i) != a.charAt(n-1-i))
				return false;
		}
		return true;
	}
}
