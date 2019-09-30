public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        switch (scanner.next()) {
            case "WBWBWWBWBWBWWBWBWWBW":
            case "BWBWWBWBWBWWBWBWWBWB":
                System.out.println("Do");
                return;
            case "WBWWBWBWBWWBWBWWBWBW":
            case "BWWBWBWBWWBWBWWBWBWB":
                System.out.println("Re");
                return;
            case "WWBWBWBWWBWBWWBWBWBW":
                System.out.println("Mi");
                return;
            case "WBWBWBWWBWBWWBWBWBWW":
            case "BWBWBWWBWBWWBWBWBWWB":
                System.out.println("Fa");
                return;
            case "WBWBWWBWBWWBWBWBWWBW":
            case "BWBWWBWBWWBWBWBWWBWB":
                System.out.println("So");
                return;
            case "WBWWBWBWWBWBWBWWBWBW":
            case "BWWBWBWWBWBWBWWBWBWW":
                System.out.println("La");
                return;
            case "WWBWBWWBWBWBWWBWBWWB":
                System.out.println("Si");
        }
    }
}