import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double height = in.nextDouble() / 100, bmi = in.nextDouble();
        System.out.println(height * height * bmi);
    }
}