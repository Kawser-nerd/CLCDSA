public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int answer, temp;
        System.out.println(Math.max(Math.max((answer = (temp = 0) + scanner.nextInt()) - temp, (answer = (temp = answer) + scanner.nextInt()) - temp), (answer = (temp = answer) + scanner.nextInt()) - temp) * 9 + answer);
    }
}