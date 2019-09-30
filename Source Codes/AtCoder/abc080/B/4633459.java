import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	String s=sc.nextLine();
    	int a=Integer.parseInt(s);
    	int sum=0;
    	for(int i=0;i<s.length();i++) {
    		sum+=Integer.parseInt(s.substring(i,i+1));
    	}
    	System.out.println(a%sum==0?"Yes":"No");
	}
}