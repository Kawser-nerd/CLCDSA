import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class Main {

    private  final String DATE_STR = "20190101";
    private List<String> result = new ArrayList<>();
    private DateTimeFormatter iPattern = DateTimeFormatter.ofPattern("uuuuMMddHHmm");
    private DateTimeFormatter oPattern = DateTimeFormatter.ofPattern("HHmm");

    public static void main(String[] args) {
        new Main().exec();
    }

    private void exec() {
        Scanner sc = new Scanner(System.in);
        int lines = sc.nextInt();
        Map<String, String> times = new TreeMap<>();
        for (int i = 0; i < lines; i++) {
            String[] time = sc.next().split("-");
            if (times.containsKey(time[0])) {
                if (Integer.parseInt(times.get(time[0])) < Integer.parseInt(time[1])) {
                    times.put(time[0], time[1]);
                }
            } else {
                times.put(time[0], time[1]);
            }
        }
        LocalDateTime beforeStart = null;
        LocalDateTime beforeEnd = null;

        for (String start : times.keySet()) {
            LocalDateTime curStart = LocalDateTime.parse(DATE_STR + start, iPattern);
            curStart = curStart.minusMinutes(curStart.getMinute() % 5);
            LocalDateTime curEnd = LocalDateTime.parse(DATE_STR + (times.get(start)), iPattern);
            if (0 < curEnd.getMinute() % 5) {
                curEnd = curEnd.plusMinutes(5 - curEnd.getMinute() % 5);
            }
            if (beforeStart == null) {
                beforeStart = curStart;
                beforeEnd = curEnd;
            } else if (curStart.isAfter(beforeEnd)) {
                addResult(beforeStart, beforeEnd);
                beforeStart = curStart;
                beforeEnd = curEnd;
            } else if (curEnd.isAfter(beforeEnd)) {
                beforeEnd = curEnd;
            }
        }

        addResult(beforeStart, beforeEnd);
        for (String res : result) {
            System.out.println(res);
        }
    }

    private void addResult(LocalDateTime start, LocalDateTime end) {
        String endHm = oPattern.format(end);
        if (endHm.equals("0000")) {
            endHm = "2400";
        }
        result.add(oPattern.format(start) + "-" + endHm);
    }
}