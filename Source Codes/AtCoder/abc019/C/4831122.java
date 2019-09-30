public class Main {
    public static void main(String[]$) {
        java.util.Scanner s = new java.util.Scanner(System.in);
        System.out.println(java.util.stream.IntStream.range(0, s.nextInt()).map(i -> s.nextInt()).map(i -> i >> Integer.numberOfTrailingZeros(i)).distinct().count());
    }
}