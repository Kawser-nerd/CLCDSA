import java.util.Scanner;

public class Main {
	//static Map<Long,Long>map=new TreeMap<>();
	static String ans="";
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       String a=sc.next();
       String b=sc.next();
          if(a.length()>b.length())ans="GREATER";
          if(a.length()<b.length())ans="LESS";
          if(a.length()==b.length()) {
        	  ans="EQUAL";
        	  for(int i=0;i<a.length();i++) {
        		  if(Integer.parseInt(a.substring(i, i+1))>Integer.parseInt(b.substring(i, i+1))){
        			  ans="GREATER";
        			  break;
        		  }
        		  else if(Integer.parseInt(a.substring(i, i+1))<Integer.parseInt(b.substring(i, i+1))){
        			  ans="LESS";
        			  break;
        		  }
        	  }
          }
       System.out.println(ans);
    }
}