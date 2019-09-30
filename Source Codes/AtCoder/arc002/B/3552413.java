import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		// ???????
		String YMD = sc.next();

		SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd");
		SimpleDateFormat sdf2 = new SimpleDateFormat("yyyyMMdd");

		Date date = new Date();
		Date d1 = new Date();
		String Day1 = "";
		String Day2 = "";

		try {
			date = sdf.parse(YMD);
		} catch (ParseException e) {
			e.printStackTrace();
		}

		Calendar calendar = Calendar.getInstance();
		calendar.setTime(date);

		Day1 = sdf2.format(date);
		// System.out.println(Double.valueOf(Day1.substring(0, 4)) /
		// Double.valueOf(Day1.substring(4, 6))% Integer.valueOf(Day1.substring(6, 8)));
		if (Double.valueOf(Day1.substring(0, 4)) / Double.valueOf(Day1.substring(4, 6))
				% Integer.valueOf(Day1.substring(6, 8)) == 0) {
			System.out.println(sdf.format(date));
		} else {

			while (1 == 1) {
				// ????
				calendar.add(Calendar.DATE, 1);
				//
				d1 = calendar.getTime();
				Day1 = sdf2.format(d1);
				if (Double.valueOf(Day1.substring(0, 4)) / Double.valueOf(Day1.substring(4, 6))
						% Integer.valueOf(Day1.substring(6, 8)) == 0) {
					System.out.println(sdf.format(d1));
					break;
				}
			}

		}

	}

}