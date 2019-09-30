import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        switch(sc.next()){
            case "a":
            case "i":
            case "u":
            case "e":
            case "o":
                System.out.println("vowel");
                break;
            default:
                System.out.println("consonant");
        }
    }
    
 
}