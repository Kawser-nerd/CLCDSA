import java.util.Scanner;

public class Main {
	//static Map<Long,Long>map=new TreeMap<>();
	static String ans="";
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       int a=sc.nextInt();
       int b=sc.nextInt();
       String s[][]=new String[a+2][b+2];
       for(int i=0;i<a+2;i++) {
    	   for(int j=0;j<b+2;j++) {
    		   s[i][j]="#";
    	   }
       }
       for(int i=1;i<=a;i++) {
    	     String S=sc.next();
    	     String S2[]=S.split("");
    	     for(int j=0;j<b;j++) {
    	    	 s[i][j+1]=S2[j];
    	     }
    	}
       for(int i=0;i<a+2;i++) {
    	   for(int j=0;j<b+2;j++) {
    		  System.out.print(s[i][j]);
    	   }
    	   System.out.println();
       }
    }
}