import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            String str = sc.next();
            String startString = str.split("-")[0];
            int start = Integer.valueOf(startString.substring(0, 2)) * 60 + roundDown(Integer.valueOf(startString.substring(2, 4)));
            String endString = str.split("-")[1];
            int end = Integer.valueOf(endString.substring(0, 2)) * 60 + roundUp(Integer.valueOf(endString.substring(2, 4)));
            map.put(start, Math.max(map.getOrDefault(start, -1), end));
        }
        int start = -1;
        int end = -1;
        for(Map.Entry entry: map.entrySet()) {
            if(start == -1 && end == -1) {
                start = (int)entry.getKey();
                end = (int)entry.getValue();
            } else {
                if(end >= (int)entry.getKey()) {
                    end = Math.max(end, (int)entry.getValue());
                } else {
                    System.out.println(timeFormat(start) + "-" + timeFormat(end));
                    start = (int)entry.getKey();
                    end = (int)entry.getValue();
                }
            }
        }
        if(start != -1 && end != -1) {
            System.out.println(timeFormat(start) + "-" + timeFormat(end));
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