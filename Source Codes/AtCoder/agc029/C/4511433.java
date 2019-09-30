import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] lengths = new int[n];
        for (int i = 0; i < n; ++i) {
            lengths[i] = scanner.nextInt();
        }
        int i;
        for (i = 1; i < n; ++i) {
            if (lengths[i] <= lengths[i - 1]) {
                break;
            }
        }
        if (i == n) {
            System.out.println(1);
            return;
        }
        int a = 1; // cannot
        int b = n; // can
        while (a + 1 < b) {
            int m = (a + b) / 2;
            boolean isOk = check(m, lengths);
            //   System.out.println("m: " + m + " isOk: " + isOk);
            if (isOk) {
                b = m;
            } else {
                a = m;
            }
        }
        System.out.println(b);
    }
    public static class Element {
        int pos;
        int value;

        public Element(int pos, int value) {
            this.pos = pos;
            this.value = value;
        }
    }

    public static boolean check(int m, int[] lengths) {
        Stack<Element> stack = new Stack<>();
        for (int i = 1; i < lengths.length; ++i) {
            if (lengths[i] > lengths[i - 1]) {
                continue;
            }
            while (!stack.isEmpty()) {
                Element end = stack.peek();
                if (end.pos > lengths[i]) {
                    stack.pop();
                } else {
                    break;
                }
            }
            int carry = 1;
            int targetPos = lengths[i];
            while (!stack.isEmpty()) {
                Element end = stack.peek();
                if (end.pos == targetPos) {
                    stack.pop();
                    if (end.value + carry < m) {
                        stack.push(new Element(targetPos, end.value + carry));
                        carry = 0;
                        break;
                    }
                    targetPos--;
                } else if (end.pos < targetPos) {
                    stack.push(new Element(targetPos, 1));
                    carry = 0;
                    break;
                }
            }
            if (carry > 0) {
                if (targetPos >= 1) {
                    stack.push(new Element(targetPos, 1));
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}