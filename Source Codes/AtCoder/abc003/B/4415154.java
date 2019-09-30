import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        boolean win = true;

        String s = sc.next();
        String t = sc.next();

        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == t.charAt(i)){
                continue;
            }else if(s.charAt(i) == '@' && String.valueOf(t.charAt(i)).matches("[atcoder]")){
                continue;
            }else if(t.charAt(i) == '@' && String.valueOf(s.charAt(i)).matches("[atcoder]")){
                continue;
            }

            win = false;
        }

        System.out.println(win?"You can win":"You will lose");
    }
}