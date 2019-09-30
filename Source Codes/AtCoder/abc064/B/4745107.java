import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	static Map<String,Integer>map=new TreeMap<>();
	static String ans="";
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
    int a=sc.nextInt();
    int min=1001;
    int max=-1;
    for(int i=0;i<a;i++) {
    	int b=sc.nextInt();
    	min=Math.min(min, b);
    	max=Math.max(max, b);
    }
     System.out.println(max-min);
    }
}