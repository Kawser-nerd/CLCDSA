import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Main m = new Main();
    m.input();
    m.check();
  }
  
    Scanner sc = new Scanner(System.in);
    int token  = sc.nextInt();
    int[] num = new int[token];
    int[] x   = new int[token];
    int[] y   = new int[token];

  public void input(){
  for(int i = 0 ; i < token ; i++){
    num[i] = sc.nextInt();
    x[i]   = sc.nextInt();
    y[i]   = sc.nextInt();
    }
  }
  
  public void check(){
      
    int lastNum = 0 , lastX = 0 , lastY = 0;
  
  for(int i = 0 ; i < token ; i++){
    int move = Math.abs(x[i]-lastX) + Math.abs(y[i]-lastY);

    if((num[i]-lastNum) < move || (num[i]-lastNum)%2 != move % 2){
        System.out.println("No");
        return;
    }else{
        
    lastNum = num[i];
    lastX = x[i];
    lastY = y[i];
    }    
  }
  System.out.println("Yes");
  return;
 }
}