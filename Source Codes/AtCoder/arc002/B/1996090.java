import java.io.*;
import java.util.*;

public class Main {
    public static int year;
    public static int month;
    public static int day;

    public static boolean find_date(Calendar cal) {
        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONTH) + 1;
        day = cal.get(Calendar.DATE);

        return year % (month * day) == 0 ? true : false;
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        String date[] = scan.next().split("/", 0);

        year = Integer.parseInt(date[0]);
        month = Integer.parseInt(date[1]);
        day = Integer.parseInt(date[2]);

        Calendar cal = Calendar.getInstance();
        cal.set(year, month - 1, day);

        while(!(find_date(cal)))
            cal.add(Calendar.DAY_OF_MONTH, 1);

        System.out.printf("%4d/%02d/%02d\n", year, month, day);
    }
}