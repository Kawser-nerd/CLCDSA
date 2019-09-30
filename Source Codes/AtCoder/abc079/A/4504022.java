import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		System.out.println(s.charAt(1)==s.charAt(2)&&(s.charAt(0)==s.charAt(1)||s.charAt(2)==s.charAt(3)) ? "Yes":"No");
	}
}