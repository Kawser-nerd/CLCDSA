import java.util.*;

public class Main{
  
  public static void main (String[] args){
    
    Main main = new Main();
    main.solve();
  }
  
  private void solve (){
    
    Scanner scanner = new Scanner (System.in);
    
    int X = scanner.nextInt();
    int Y = scanner.nextInt();
    
    Y/=2;
    
    System.out.println(X+Y);
  }
}