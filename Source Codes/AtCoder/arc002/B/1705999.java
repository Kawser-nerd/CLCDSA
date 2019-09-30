import java.io.*;
import java.util.*;

public class Main {
    public static boolean find_date(Calendar cal) {
        int year = cal.get(Calendar.YEAR);
        int month = cal.get(Calendar.MONTH) + 1;
        int day = cal.get(Calendar.DATE);

        if(year % month == 0 && year / month % day == 0)
            return true;
        else
            return false;
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        String date[] = scan.next().split("/", 0);

        int year = Integer.parseInt(date[0]);
        int month = Integer.parseInt(date[1]);
        int day = Integer.parseInt(date[2]);

        Calendar cal = Calendar.getInstance();
        cal.set(year, month - 1, day);

        while(!(find_date(cal)))
            cal.add(Calendar.DAY_OF_MONTH, 1);

        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONTH) + 1;
        day = cal.get(Calendar.DATE);
        System.out.printf("%4d/%02d/%02d\n", year, month, day);

    }
}