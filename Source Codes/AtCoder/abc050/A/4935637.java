import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(sc.nextInt()+(sc.next().equals("+")?1:-1)*sc.nextInt());
    }
    
 
}