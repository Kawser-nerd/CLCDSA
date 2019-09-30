import java.util.Scanner;

public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int n1 = sc.nextInt();
    int n2 = sc.nextInt();
	int mod = n1 % n2;
    if (mod == 0){
     	System.out.println("YES"); 
    } else {
      	System.out.println("NO");
    }
  }
}