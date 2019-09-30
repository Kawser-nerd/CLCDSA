import java.util.*;

public class Main {
    private static int y;
    private static int m;
    private static int d;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        String str = scan.next();
        String[] date = str.split("/", 0);
        y = Integer.parseInt(date[0]);
        m = Integer.parseInt(date[1]);
        d = Integer.parseInt(date[2]);
    }

    public static void main(String args[]) {
        //??
        input();

        Calendar calendar = Calendar.getInstance();
        calendar.set(y,(m-1),d);   // month?0?????

        String answer ="";
        while(true) {
            int year = calendar.get(Calendar.YEAR);
            int month = calendar.get(Calendar.MONTH)+1;
            int day = calendar.get(Calendar.DATE);

            if((year%(month*day))==0) {
                answer = year +"/"+ ((month>=10)? month : "0"+month)  +"/"+ ((day>=10)? day : "0"+day);
                break;
            }

            calendar.add(Calendar.DAY_OF_MONTH, 1);
        }
        System.out.println(answer);
    }
}