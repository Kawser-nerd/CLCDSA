import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	String a=scan.next();
	String b=scan.next();
	if(a.length()<b.length()) {
		System.out.println("LESS");
	}
	else if(a.length()>b.length()){
		System.out.println("GREATER");
	}
	else {
		for(int i=0;i!=a.length()+1;i++) {
			if(i==a.length()) {
				System.out.println("EQUAL");
			break;
			}
			char cha=a.charAt(i);
			char chb=b.charAt(i);
			int A=Character.getNumericValue(cha);
			int B=Character.getNumericValue(chb);
			if(A>B){
				System.out.println("GREATER");
				break;
			}
			else if(A<B){
				System.out.println("LESS");
			break;
			}
	}
	}
}
}