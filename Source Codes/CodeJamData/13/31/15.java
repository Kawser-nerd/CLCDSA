import java.io.*;
import java.util.*;
import java.math.*;
public class A2 {
	public static Scanner scan = null;
	public static Scanner scan2 = null;
	public static PrintWriter out = null;
	public static boolean bg = false;
	public static int no = 4;
	public static HashSet<Character> vowels = new HashSet();
	static{
		try {
			vowels.add('a');
			vowels.add('e');
			vowels.add('i');
			vowels.add('o');
			vowels.add('u');
			scan2 = new Scanner(System.in);
			scan = new Scanner(new FileReader("input"+no+".txt"));
			out = new PrintWriter(new File("output"+no+".txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args){
		if (bg) System.out.println(vowels);
		int t = Integer.parseInt(scan.next());
		for (int count = 0;count<t;count++){
			String str1 = scan.next();
			
			int n = Integer.parseInt(scan.next());
			
			StringBuilder k2 = new StringBuilder();
			for (char e: str1.toCharArray()){
				if (vowels.contains(e) ){
					k2.append('1');
				}
				else {
					k2.append('0');
				}
			}
			str1 = k2.toString();
			char[] l1 = k2.toString().toCharArray();
			LinkedList<Character> l2 = new LinkedList();
			int count2 = 0;
			int count3 = 0;
			for (int i=0;i<n;i++){
				if (l1[i]=='0'){
					count2++;
				}
				l2.add(l1[i]);
			}
			if (count2!=n){
				count3++;
			}
			if (bg) System.out.println("count2 "+count2);
			ArrayList<Integer> cache = new ArrayList();
			for (int i=n;i<str1.length();i++){
				
				char temp = l2.pollFirst();
				//System.out.println("temp "+temp);
				if (temp=='0'){
					count2--;
				}
				l2.add(l1[i]);
				if (l1[i]=='0'){
					count2++;
				}
				//System.out.println("count2 "+count2);
				if (bg) System.out.println("count3 "+count3);
				if (count2!=n){
					count3++;
					if (bg) System.out.println("ok");
				}
				else {
					if (count3!=0) cache.add(count3);
					count3=0;
				}
				if (bg) System.out.println(l2);
			}
			if (count3!=0) cache.add(count3);
			if (bg) System.out.println(cache);
			int temp4 = str1.length()-n+1;
			//long total = temp4*(temp4+1)/2;
			BigInteger total = new BigInteger(temp4+"");
			total = total.multiply(total.add(BigInteger.ONE)).divide(new BigInteger(2+""));
			for (int e: cache){
				long temp = e;
				temp = temp*(temp+1)/2;
				total=total.subtract(new BigInteger(temp+""));
				//total-=temp;
			}
			
			
			//System.out.println("fin "+total);
			if (bg) System.out.println();
			System.out.println("Case #"+(count+1)+": "+total);
			out.println("Case #"+(count+1)+": "+total);
			out.flush();
			//scan2.next();
		}
		
	}
}
