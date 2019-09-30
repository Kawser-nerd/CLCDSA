import java.util.Scanner;
 
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    String[] a = new String[n];
    String[] b = new String[m];
    for(int i = 0; i < n; i++){
      a[i] = sc.next();
    }
    for(int i = 0; i < m; i++){
      b[i] = sc.next();
    }
    
    for(int i = 0; i <= n - m; i++){
      for(int j = 0; j <= n - m; j++){
        boolean hit = true;
        if(a[i].substring(j, j + m).equals(b[0])){
          for(int k = 1; k < m; k++){
            if(!a[i + k].substring(j, j + m).equals(b[k])){
              hit = false;
              break;
            }
          }
        }else{
          hit = false;
          continue;
        }
        
        if(hit){
          System.out.println("Yes");
          return;
        }
      }
    }
    System.out.println("No");
  }
}