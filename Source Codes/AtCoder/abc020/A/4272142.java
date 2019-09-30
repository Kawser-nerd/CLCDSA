import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        scan.close();
        System.out.println(q == 1 ? "ABC" : "chokudai");
    }
}