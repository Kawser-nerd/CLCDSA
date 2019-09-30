import java.io.*;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

	Scanner sc = new Scanner(System.in);

	String s=sc.next();
	
	int a=s.length();
	
	int b=a/2;
	boolean t=true;
	

	for (int i = 0; t&&i < b; i++) {
	    
	    if(s.charAt(i)!=s.charAt(a-i-1))
		if(s.charAt(i)!='*'&&s.charAt(a-i-1)!='*'){
		    System.out.println("NO");
		    t=false;
		}
	    
	}
		if (t) 
	    
	
    System.out.println("YES");
    }

}