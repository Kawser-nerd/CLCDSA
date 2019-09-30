public class Main {
    public static void main(String[]$) {
        int n=2025-new java.util.Scanner(System.in).nextInt();
        java.util.stream.IntStream.range(1,10).filter(i->n%i==0&&n/i<=9).forEach(i->System.out.println(i+" x "+n/i));
    }
}