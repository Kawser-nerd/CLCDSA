import java.util.Scanner;

public class Main {
	//static Map<Long,Long>map=new TreeMap<>();
	static int k;
	static String ans="NO";
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       int a=sc.nextInt();
       int b=sc.nextInt();
       int c=sc.nextInt();
       for(int i=1;i<=b;i++) {
    	   if(a*i%b==c)ans="YES";
       }
       System.out.println(ans);
    }
}