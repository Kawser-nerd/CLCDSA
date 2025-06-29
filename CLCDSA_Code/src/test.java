import java.io.IOException;
import java.math.BigDecimal;
import java.util.*;

import static java.lang.System.*;

public class test {
    public static void main(String[] args){
        int bonus, sales = 1000;
        if(sales < 5000)
            bonus = 200;
        else if(sales < 7500)
            bonus = 500;
        else if(sales < 100000)
            bonus = 750;
        else
            bonus = 1250;
        System.out.println(bonus);
    }
}
/*
public class test {
    public static void main(String[] args) throws IOException {
        try {
            Scanner sc = new Scanner(System.in);
            int Deg = sc.nextInt();
            int Dis = sc.nextInt();
            int intArray[] = new int[5];



            String houi = houi(Deg / 10.0);
            int huryoku = huryoku(Dis) + 10;


            if (huryoku == 0) {
                houi = "C";
            }
            out.println(houi + " " + huryoku);
        } catch (IllegalAccessError e)
        {
            System.out.println(e.toString());
        } catch (IllegalArgumentException ex)
        {
            System.out.println(ex.toString());
        }

    }

    private static String houi(double deg) {
        if (11.25 <= deg && deg < 33.75) {
            return "NNE";
        } else if (33.75 <= deg && deg < 56.25) {
            return "NE";
        } else if (56.25 <= deg && deg < 78.75) {
            return "ENE";
        } else if (78.75 <= deg && deg < 101.25) {
            return "E";
        } else if (101.25 <= deg && deg < 123.75) {
            return "ESE";
        } else if (123.75 <= deg && deg < 146.25) {
            return "SE";
        } else if (146.25 <= deg && deg < 168.75) {
            return "SSE";
        } else if (168.75 <= deg && deg < 191.25) {
            return "S";
        } else if (191.25 <= deg && deg < 213.75) {
            return "SSW";
        } else if (213.75 <= deg && deg < 236.25) {
            return "SW";
        } else if (236.25 <= deg && deg < 258.75) {
            return "WSW";
        } else if (258.75 <= deg && deg < 281.25) {
            return "W";
        } else if (281.25 <= deg && deg < 303.75) {
            return "WNW";
        } else if (303.75 <= deg && deg < 326.25) {
            return "NW";
        } else if (326.25 <= deg && deg < 348.75) {
            return "NNW";
        }
        return "N";
    }

    private static int huryoku(int dis) {
        BigDecimal num = new BigDecimal(dis).divide(new BigDecimal("60.0"),1, BigDecimal.ROUND_HALF_UP);

        for (int i =0; i<100; i++)
        {
            System.out.print(i);
        }

        if (num.compareTo(new BigDecimal("0.3")) < 0) {
            return 0;
        } else if (num.compareTo(new BigDecimal("1.6")) < 0 ) {
            return 1;
        } else if (num.compareTo(new BigDecimal("3.4")) < 0 ) {
            return 2;
        } else if (num.compareTo(new BigDecimal("5.5")) < 0 ) {
            return 3;
        } else if (num.compareTo(new BigDecimal("8.0")) < 0 ) {
            return 4;
        } else if (num.compareTo(new BigDecimal("10.8")) < 0 ) {
            return 5;
        } else if (num.compareTo(new BigDecimal("13.9")) < 0 ) {
            return 6;
        } else if (num.compareTo(new BigDecimal("17.2")) < 0 ) {
            return 7;
        } else if (num.compareTo(new BigDecimal("20.8")) < 0 ) {
            return 8;
        } else if (num.compareTo(new BigDecimal("24.5")) < 0 ) {
            return 9;
        } else if (num.compareTo(new BigDecimal("28.5")) < 0 ) {
            return 10;
        } else if (num.compareTo(new BigDecimal("32.7")) < 0 ) {
            return 11;
        }
        return 12;
    }

    private static int switchTest(int class1, int class2){
        int month = 8;
        String monthString;
        switch (month) {
            case 1:  monthString = "January";
                break;
            case 2:  monthString = "February";
                break;
            case 3:  monthString = "March";
                break;
            case 4:  monthString = "April";
                break;
            case 5:  monthString = "May";
                break;
            case 6:  monthString = "June";
                break;
            case 7:  monthString = "July";
                break;
            case 8:  monthString = "August";
                break;
            case 9:  monthString = "September";
                break;
            case 10: monthString = "October";
                break;
            case 11: monthString = "November";
                break;
            case 12: monthString = "December";
                break;
            default: monthString = "Invalid month";
                break;
        }
        return 0;
    }
}
*/