import java.util.*;

public class Main{
  
  public static void main (String[] args){
    
    Main main = new Main();
    main.solve();
  }
  
  private void solve (){
    
    Scanner scanner = new Scanner(System.in);
    int age = scanner.nextInt();
    
    if (age==1){
      System.out.println("Hello World");
    } else {
      int A = scanner.nextInt();
      int B = scanner.nextInt();
      System.out.println(A+B);
    }
  }
}