import static java.util.Comparator.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static public void main(String[] args) {

		// ???????
		Scanner scan = new Scanner(System.in);

		// ??????????????????
		int size = scan.nextInt();

		// ??????????????????(yymm-yymm)
		List<String> list = new ArrayList<>(size);
		for (int i = 0; i < size; i++) {
			list.add(scan.next());
		}

		// ??????????????????
		list.sort(naturalOrder());

		// ??????????????????????
		int start = 9999;
		int end = -1;

		// ???????????????????
		for (String data : list) {

			// ????????????????
			String[] record = data.split("-");
			int rainStart = Integer.parseInt(record[0]);
			int rainEnd = Integer.parseInt(record[1]);

			// ???????5??????????(1148?1145)
			rainStart -= rainStart % 5;

			// ???????5??????????(1401?1405)
			if (rainEnd % 5 > 0) {
				rainEnd += 5 - rainEnd % 5;
			}

			// ???????5?????????????????????(1456?1460?1500)
			if (rainEnd % 100 == 60) {
				rainEnd += 40;
			}

			// ????????????????????????????????????????
			// ???????????????????????????????????
			if (rainStart > end) {
				// ???????????????(=9999)???????????
				if (start != 9999) {
					// ???????????????????????????
					System.out.println(String.format("%04d", start) + "-" + String.format("%04d", end));
				}
				// ????????????????
				start = rainStart;
				// ??????????????????????????
				// ??????????????????????
				end = -1;
			}

			// ?????????????????????????????????????????????
			if (end < rainEnd) {
				end = rainEnd;
			}
		}

		// ????????????????
		System.out.println(String.format("%04d", start) + "-" + String.format("%04d", end));

		// ?????????????
		scan.close();
	}
}