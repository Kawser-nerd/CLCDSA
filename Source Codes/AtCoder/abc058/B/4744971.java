import java.util.Scanner;

public class Main {
	//static Map<Long,Long>map=new TreeMap<>();
	static String ans="";
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       String a=sc.next();
       String b=sc.next();
       for(int i=0;i<a.length();i++) {
    	   ans+=a.substring(i, i+1);
    	   if(i+1>b.length())break;
    	   ans+=b.substring(i, i+1);
       }
       System.out.println(ans);
    }
}