import java.util.*;

public class Main{
  
  public static void main (String[] args){
    
    Main main = new Main();
    main.solve();
  }
  
  private void solve(){
    
    Scanner scanner = new Scanner (System.in);
    int number = scanner.nextInt();
    int maximumTime = scanner.nextInt();
    
    int cost=0;
    int time=0;
    int minimumCost=0;
    boolean firstFlag=true;
    
    for (int index=0; index<number; index++){
      
      cost = scanner.nextInt();
      time = scanner.nextInt();
      
      if(time<=maximumTime&&(cost<minimumCost||firstFlag==true)){
        minimumCost=cost;
        firstFlag=false;
      }
    }
    
    if (firstFlag==true){
      System.out.println("TLE");
    } else {
    System.out.println(minimumCost);
    }
  }
}