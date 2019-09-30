import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String e = in.nextLine();
        String b = in.nextLine();
        String[] l = in.nextLine().split(" ");
        int sa = 0, bo = 0;
        for (int i = 0; i < l.length; i++) {
            if (e.indexOf(l[i]) != -1) {
                sa++;
            } else {
                if (b.equals(l[i])) {
                    bo++;
                }
            }
        }
        if (sa == 6) {
            System.out.println(1);
        } else if (sa == 5 && bo == 1) {
            System.out.println(2);
        } else if (sa == 5) {
            System.out.println(3);
        } else if (sa == 4) {
            System.out.println(4);
        } else if (sa == 3) {
            System.out.println(5);
        } else {
            System.out.println(0);
        }
    }
}