import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long X = scan.nextLong();
        long A = scan.nextLong();
        long B = scan.nextLong();
        scan.close();
        if (B <= A) System.out.println("delicious");
        else if (B - A <= X) System.out.println("safe");
        else System.out.println("dangerous");
    }
}