import java.util.Scanner;
public class Main {
  public static void main (String[]args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();

    for(int i = 1;;i++){
      int j = A*i;
      if(j == B){
        System.out.println(A+B);
        break;
      } 
      if(j>B) {
        System.out.println(B-A);
        break;
      }      
    }
  }
}