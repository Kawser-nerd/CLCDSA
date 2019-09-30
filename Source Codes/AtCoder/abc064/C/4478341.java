public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), ans = 0, colors[] = new int[9];
        for (int i = 0, temp; i < n; i++)
            if (++colors[temp = Color.getColor(scanner.nextInt()).ordinal()] == 1 && temp != 8)
                ans++;
        System.out.println(Math.max(1, ans) + " " + (ans + colors[8]));
    }

    enum Color {
        GRAY(1, 399),
        BROWN(400, 799),
        GREEN(800, 1199),
        LIGHT_BLUE(1200, 1599),
        BLUE(1600, 1999),
        YELLOW(2000, 2399),
        ORANGE(2400, 2799),
        RED(2800, 3199),
        FREE(3200, 4800);

        int min, max;
        Color(int min, int max) {
            this.min = min;
            this.max = max;
        }

        static Color getColor(int rate) {
            for (Color color : values())
                if (color.min <= rate && rate <= color.max)
                    return color;
            return null;
        }
    }
}