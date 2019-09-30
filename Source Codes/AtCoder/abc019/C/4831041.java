public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        java.util.Set<Integer> a = java.util.stream.IntStream.range(0, n).map(i -> scanner.nextInt()).boxed().collect(java.util.stream.Collectors.toSet());
        System.out.println(a.stream().filter(i -> {
            while (i % 2 == 0)
                if (a.contains(i /= 2))
                    return false;
            return true;
        }).count());
    }
}