import java.util.Scanner;

public class Main {
	static long N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	String s=sc.nextLine();
	String s2=sc.nextLine();
	String ans="You can win";
	String chenge[]= {"a","t","c","o","d","e","r"};
	for(int i=0;i<s.length();i++) {
		boolean flag=false;
		if(s.substring(i,i+1).equals("@")) {
			for(int j=0;j<7;j++)
				if(s2.substring(i,i+1).equals(chenge[j])||s2.substring(i,i+1).equals("@"))flag=true;
			if(flag==false)ans="You will lose";
		}else if(s2.substring(i,i+1).equals("@")==false){
			if(s.substring(i,i+1).equalsIgnoreCase(s2.substring(i,i+1))==false)ans="You will lose";
		}
	}
	for(int i=0;i<s2.length();i++) {
		boolean flag=false;
		if(s2.substring(i,i+1).equals("@")) {
			for(int j=0;j<7;j++)
				if(s.substring(i,i+1).equals(chenge[j])||s.substring(i,i+1).equals("@"))flag=true;
			if(flag==false)ans="You will lose";
		}
	}
	System.out.println(ans);
	}
}