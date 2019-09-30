import java.util.*;

public class Main{
	public static void main(String arge[]){
    	Scanner scan = new Scanner(System.in);
      	int i= scan.nextInt();
      String[] a;
      a = new String[i];
      String ans="Three";
      
      for(int j=0;j<i;j++){
      	a[j]=scan.next();
        if(a[j].equals("Y")){
        ans="Four";
        }
      }
      System.out.print(ans);
      
    }
}