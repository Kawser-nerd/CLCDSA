import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		String[]days={
				"Monday",
				"Tuesday",
				"Wednesday",
				"Thursday",
				"Friday",
				"Saturday",
				"Sunday"
				};
		String in=s.next();
		for(int i=0;i<7;i++) {
			if(days[i].equals(in)) {
				System.out.println(Math.max(5-i, 0));
				return;
			}
		}
	}
}