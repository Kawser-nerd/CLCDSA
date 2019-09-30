import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int time[][] = new int[num][2];
		for(int i = 0; i < num; i ++) {
			String tmp = sc.next();
			time[i][0] = Integer.valueOf(tmp.substring(0, 4));
			time[i][0] = (int) Math.floor(time[i][0] / 100.0) * 60 + (int) Math.floor(time[i][0] % 100 / 5.0) * 5;
			time[i][1] = Integer.valueOf(tmp.substring(5, 9));
			time[i][1] = (int) Math.floor(time[i][1] / 100.0) * 60 + (int) Math.ceil(time[i][1] % 100 / 5.0) * 5;
		}

		int start[] = new int[1441];
		int end[] = new int[1441];
		for(int i = 0; i < num; i ++) {
			start[time[i][0]] ++;
			end[time[i][1]] ++;
		}

		int startCount = 0;
		int endCount = 0;
		boolean raining = false;
		for(int i = 0; i <= 1440; i += 5) {
			startCount += start[i];
			endCount += end[i];
			int tmp = (int) Math.floor(i / 60.0) * 100 + i % 60;
			if(startCount > endCount && !raining) {
				System.out.print(String.format("%04d", tmp));
				System.out.print("-");
				raining = true;
			}else if(startCount == endCount && raining) {
				System.out.println(String.format("%04d", tmp));
				raining = false;
			}
		}
	}
}