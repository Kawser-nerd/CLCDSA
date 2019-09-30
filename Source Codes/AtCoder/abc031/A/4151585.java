import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), d = sc.nextInt();
        int attack = (a + 1) * d;
        int defence = (d + 1) * a;
        
        if (attack == defence) {
            System.out.println(attack);
        } else if (attack > defence) {
            System.out.println(attack);
        } else {
            System.out.println(defence);
        }
        
    }
}