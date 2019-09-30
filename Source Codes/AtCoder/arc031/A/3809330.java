import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    String name = scanner.next();
    boolean flag = true;
    for(int i = 0; i < name.length()/2; i++){
      if(name.charAt(i) != name.charAt(name.length()-1-i)){
        flag = false;
        break;
      }
    }
    if(flag){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}