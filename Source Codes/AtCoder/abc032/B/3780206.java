import java.util.*;

class Main {
    public static void main(String[] args) {
        new Main().main();
    }

    public void main() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int k = Integer.parseInt(scanner.nextLine());

        String[] memory = new String[s.length()];
        int memorySize = 0;

        for (int i = 0; i <= s.length() - k; i++) {
            String sub = s.substring(i, i + k);
            if (!this.includes(memory, memorySize, sub)) {
                memory[memorySize] = sub;
                memorySize++;
            }
        }
        System.out.println(memorySize);
    }

    private boolean includes(String[] arr, int n, String s) {
        for (int i = 0; i < n; i++) {
            if (arr[i].equals(s)) {
                return true;
            }
        }
        return false;
    }
}