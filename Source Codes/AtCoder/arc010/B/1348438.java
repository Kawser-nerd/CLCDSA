import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BitSet calendar = new BitSet(366);
		int tmp = 0;
		for(int i = 1; i <= 366; i++) {
			tmp = i % 7;
			if(tmp == 1 || tmp == 0) {
				calendar.set(i-1);
			}
		}

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Integer allNissu = Integer.valueOf(br.readLine());

		List<Integer> syukuList = new ArrayList<>();
		Integer month = 0;
		Integer day = 0;
		for(int i = 0; i < allNissu; i++) {
			String[] tmpStr = br.readLine().split("/");
			month = Integer.valueOf(tmpStr[0]);
			day = Integer.valueOf(tmpStr[1]) - 1;
			if(month == 1) {
				syukuList.add(day);
			} else if(month == 2) {
				syukuList.add(day + 31);
			} else if(month == 3) {
				syukuList.add(day + 31 + 29);
			} else if(month == 4) {
				syukuList.add(day + 31 + 29 + 31);
			} else if(month == 5) {
				syukuList.add(day + 31 + 29 + 31 + 30);
			} else if(month == 6) {
				syukuList.add(day + 31 + 29 + 31 + 30 + 31);
			} else if(month == 7) {
				syukuList.add(day + 31 + 29 + 31 + 30 + 31 + 30);
			} else if(month == 8) {
				syukuList.add(day + 31 + 29 + 31 + 30 + 31 + 30 + 31);
			} else if(month == 9) {
				syukuList.add(day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31);
			} else if(month == 10) {
				syukuList.add(day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
			} else if(month == 11) {
				syukuList.add(day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31);
			} else if(month == 12) {
				syukuList.add(day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
			}
		}

		for(Integer syukujitu : syukuList) {
			if(calendar.get(syukujitu)) {
				calendar.set(calendar.nextClearBit(syukujitu));
			} else {
				calendar.set(syukujitu);
			}
		}

		Integer result = 0;
		int tmpCnt = 0;
		Integer tmpLast = 0;
		Integer tmpFirst = 0;
		for(int i = 0; i < 366; i++) {
			tmpFirst = calendar.nextSetBit(i);
			if(tmpFirst == -1) {
				System.out.println(result);
				return;
			}
			tmpLast = calendar.nextClearBit(tmpFirst);

			if(tmpLast > 366) {
				tmpLast = 366;
			}
			if(tmpFirst > 366) {
				tmpFirst = 366;
			}

			tmpCnt = tmpLast - tmpFirst;
			if(tmpCnt > result) {
				result = tmpCnt;
			}
			i = calendar.nextSetBit(i) + tmpCnt - 1;
		}
		System.out.println(result);
	}
}