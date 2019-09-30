public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), k = scanner.nextInt();
        System.out.println(java.util.stream.LongStream.range(0,n).map(i->scanner.nextInt()*Math.min(Math.min(Math.min(i+1,n-i),k),n-k+1)).sum());
    }
}