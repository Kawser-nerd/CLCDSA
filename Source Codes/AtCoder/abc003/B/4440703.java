import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String s1 = sc.nextLine();
    String s2 = sc.nextLine();
    Set<Character> list = new HashSet<>();
    list.add('a');
    list.add('t');
    list.add('c');
    list.add('o');
    list.add('d');
    list.add('e');
    list.add('r');
    
    boolean check = true;
    for(int i = 0; i < s1.length(); i++){
      if(s1.charAt(i) == s2.charAt(i)){
        continue;
      }
      else if((s1.charAt(i) == '@' && list.contains(s2.charAt(i))) ||
             	(s2.charAt(i) == '@' && list.contains(s1.charAt(i)))){
        continue;
      }
      else{
        check = false;
        break;
      }
    }
    System.out.println(check ? "You can win" : "You will lose");
  }
}