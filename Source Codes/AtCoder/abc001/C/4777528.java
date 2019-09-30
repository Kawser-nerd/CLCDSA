import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int deg = scanner.nextInt() * 10;
        int dis = scanner.nextInt();

        String[] degs = {"NNE", "NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"};

        int normDeg;
        if (deg >= 34900 || deg < 1125) {
            normDeg = -1;
        } else {
            normDeg = deg - 1125;
        }
        String dir;
        if (normDeg == -1) {
            dir = "N";
        } else {
            dir = degs[normDeg / 2250];
        }

        int disLevel;
        int disAvg = (dis * 100 / 60);
        int tmp = disAvg % 10;
        if (tmp <= 4) {
            disAvg = disAvg / 10;
        } else {
            disAvg = (disAvg / 10) + 1;
        }


        if (disAvg <= 2) {
            disLevel = 0;
            dir = "C";
        } else if (disAvg <= 15) {
            disLevel = 1;
        } else if (disAvg <= 33) {
            disLevel = 2;
        } else if (disAvg <= 54) {
            disLevel = 3;
        } else if (disAvg <= 79) {
            disLevel = 4;
        } else if (disAvg <= 107) {
            disLevel = 5;
        } else if (disAvg <= 138) {
            disLevel = 6;
        } else if (disAvg <= 171) {
            disLevel = 7;
        } else if (disAvg <= 207) {
            disLevel = 8;
        } else if (disAvg <= 244) {
            disLevel = 9;
        } else if (disAvg <= 284) {
            disLevel = 10;
        } else if (disAvg <= 326) {
            disLevel = 11;
        } else {
            disLevel = 12;
        }

        System.out.printf("%s %d\n", dir, disLevel);
    }
}