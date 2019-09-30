import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		String po=sc.nextLine();
        String p[]=po.split("",0);
      int count =700;
        for(int i=0;i<p.length;i++){
         if(p[i].equals("o"))count+=100;
        }
        System.out.println(count);
	}
}