import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long a = in.nextLong(), b = in.nextLong();
        System.out.println(b - a - (a*b<0?1:0));
    }
}