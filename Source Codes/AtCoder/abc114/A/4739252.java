import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
      if(a == 3||a == 5|| a == 7){
        System.out.println("YES");
      }else{
        System.out.println("NO");
      }
      sc.close();
    }
}