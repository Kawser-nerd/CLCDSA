import java.util.*;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String word = sc.nextLine();
        String[] ngWord = {"a","i","u","e","o"};
        
        for(String data:ngWord){
            word = word.replace(data,"");
        }
        
        System.out.println(word);
    }
}