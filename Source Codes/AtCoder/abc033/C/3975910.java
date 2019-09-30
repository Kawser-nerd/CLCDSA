import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
      
     Scanner sc = new Scanner(System.in);
	   String S = sc.next();
       int count = 0;
   
      String[] a = S.split("\\+");
      for(int i = 0; i < a.length; i++){
        if(!a[i].contains("0")){
          count++;
        }
    }
    System.out.println(count);
  }
}