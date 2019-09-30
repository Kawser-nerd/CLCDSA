import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws ParseException {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String h = "Heisei";
		String t = "TBD";
		Calendar c =Calendar.getInstance();
		SimpleDateFormat f = new SimpleDateFormat("yyyy/MM/dd");
		Date d = f.parse("2019/05/01");
		if(f.parse(s).before(d)) 
			System.out.println(h);
		else
			System.out.println(t);
	}
}