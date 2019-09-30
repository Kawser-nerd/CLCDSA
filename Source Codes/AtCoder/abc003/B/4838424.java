import java.util.*;
public class Main {
  public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    String T = sc.next();
    Boolean r = true;

    for( int i = 0; i < S.length(); i++){

      String _s = S.substring(i,i+1);
      String _t = T.substring(i,i+1);

      if(_s.equals("@")){
        if(!(_t.equals("a") || _t.equals("t") || _t.equals("c") || _t.equals("o") || _t.equals("d") || _t.equals("e") || _t.equals("r") || _t.equals("@"))){
          r = false;
          break;
        }
      } else if(_s.equals("a") || _s.equals("t") || _s.equals("c") || _s.equals("o") || _s.equals("d") || _s.equals("e") || _s.equals("r")){
        if(!(_t.equals("@")) && !(_s.equals(_t))){
          r = false;
          break;
        }
      } else if(!(_s.equals(_t))){
        r = false;
        break;
      }
    }
    
    if(r){
      System.out.println("You can win");
    } else {
      System.out.println("You will lose");
    }
    
  }
}