import java.util.*;

class Main{
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int x,y;
    x = sc.nextInt();
    y = sc.nextInt();
    if(x>8||y>8){
      System.out.println(":(");
    }
    else{
      System.out.println("Yay!");
    }
    
  }

}