import java.util.*;

public class Main {

    public static void main(String[] args) {
        
        Scanner sn = new Scanner(System.in);
        String word = sn.next();
        
        word = word.replaceAll("a", "");
        word = word.replaceAll("i", "");
        word = word.replaceAll("u", "");
        word = word.replaceAll("e", "");
        word = word.replaceAll("o", "");
         
        System.out.println(word);
    }
}