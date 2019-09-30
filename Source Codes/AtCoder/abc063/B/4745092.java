import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	static Map<String,Integer>map=new TreeMap<>();
	static String ans="";
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       String s=sc.next();
       for(int i=0;i<s.length();i++) {
    	   map.put(s.substring(i,i+1),1);
       }
       if(map.size()==s.length())System.out.println("yes");
       else System.out.println("no");
    }
}