import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        char ans;
        
        Set<Character> set = new HashSet<>();
        for(int i = 0; i < S.length(); i++){
            set.add(S.charAt(i));
        }
        
        for(int i = 'a'; i <= 'z'; i++){
            if(set.size() == 26){
                System.out.println("None");
                break;
            }
            if(!set.contains((char)i)){
                System.out.println((char)i);
                break;
            }
        }
    }
}