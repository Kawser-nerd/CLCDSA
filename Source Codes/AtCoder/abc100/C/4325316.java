public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(java.util.stream.Stream.generate(() -> null).limit(scanner.nextInt()).mapToInt(n -> (int)(Math.log(Integer.lowestOneBit(scanner.nextInt())) / Math.log(2))).sum());
    }
}