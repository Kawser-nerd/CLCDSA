import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        double x1 = scan.nextDouble();
        double x2 = scan.nextDouble();
        double y1 = scan.nextDouble();
        double y2 = scan.nextDouble();
        double z1 = scan.nextDouble();
        double z2 = scan.nextDouble();

            y1 = y1 - x1;
            z1 = z1 - x1;

            y2 = y2 - x2;
            z2 = z2 - x2;

        double a = Math.abs(y1 * z2 - y2 * z1);
        double s = a/2.0;

        System.out.println(String.format("%.1f", s));
    }


}