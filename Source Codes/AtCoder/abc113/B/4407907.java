import java.util.*;

public class Main{
  
  public static void main (String[] args){
    
    Main main = new Main ();
    main.solve();
  }
  
  private void solve(){
    
    Scanner scanner = new Scanner (System.in);
    
    int N = scanner.nextInt();
    int T = scanner.nextInt();
    int A = scanner.nextInt();
    
    double nearOndo =0;
    int nearIndex=26;
    for (int index=0; index<N; index++){
      int temp = scanner.nextInt();
      double ondo = T-(temp*0.006);
      if (index==0){
        nearOndo=ondo;
        nearIndex=index;
   	  }else if (Math.abs(ondo-A)<Math.abs(nearOndo-A)){
        nearOndo=ondo;
        nearIndex=index;
      }
    }
    System.out.println(nearIndex+1);
  }
}