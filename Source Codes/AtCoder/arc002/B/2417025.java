import java.io.*;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2= false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 == args.length;
		debug2= 2 == args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		ZonedDateTime date = ZonedDateTime.parse(in.readLine().replaceAll("/", "-") + "T00:00:00Z");

		while(true)
		{
			if (date.getYear() % date.getMonthValue() == 0
			 && date.getYear() / date.getMonthValue() % date.getDayOfMonth() == 0)
			{
				System.out.println(date.format(DateTimeFormatter.ISO_LOCAL_DATE).replaceAll("-", "/"));
				break;
			}
			date = date.plusDays(1);
		}
	}
}