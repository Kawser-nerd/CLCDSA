import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        char c = sc.next().charAt(0);
        
        if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
            System.out.println("vowel");
        }else{
            System.out.println("consonant");
        }
    }
}