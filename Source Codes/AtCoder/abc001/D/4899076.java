import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int[] timeTable = new int[24 * 60 + 2];
        for (int i = 0; i < n; i++) {
            String str = sc.next();
            String startString = str.split("-")[0];
            int start = Integer.valueOf(startString.substring(0, 2)) * 60 + roundDown(Integer.valueOf(startString.substring(2, 4)));
            String endString = str.split("-")[1];
            int end = Integer.valueOf(endString.substring(0, 2)) * 60 + roundUp(Integer.valueOf(endString.substring(2, 4)));
            timeTable[start] += 1;
            timeTable[end + 1] += -1;
        }
        for(int i = 1; i <= 24 * 60; i++) {
            timeTable[i] += timeTable[i-1];
        }
        for(int i = 0; i <= 24 * 60; i++) {
            if(timeTable[i] >= 1) {
                int s = i;
                while(i <= 24 * 60 && timeTable[i] >= 1) i++;
                System.out.println(timeFormat(s) + "-" + timeFormat(i-1));
            }
        }
    }

    private static String timeFormat(int num) {
        String time = "";
        int hour = num / 60;
        time += hour < 10 ? "0" + hour : hour;
        int minute = num - (hour * 60);
        time += minute < 10 ? "0" + minute : minute;
        return time;
    }

    private static int roundDown(int num) {
        int mod = num % 10;
        if(mod != 0 && mod != 5) {
            if(mod < 5) num -= mod;
            else num -= (mod - 5);
        }
        return num;
    }

    private static int roundUp(int num) {
        int mod = num % 10;
        if(mod != 0 && mod != 5) {
            if(mod > 5) num += (10 - mod);
            else num += (5 - mod);
        }
        return num;
    }
}