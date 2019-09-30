import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.ParseException;
import java.util.Arrays;
import java.util.IntSummaryStatistics;

public class Main {
	public static void main(String[] args) throws IOException, ParseException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int number = Integer.parseInt(br.readLine());
		int[] pointArray = new int[number];
		for(int i=0;i<number;i++){
			pointArray[i] = Integer.parseInt(br.readLine());
		}
		IntSummaryStatistics iss=Arrays.stream(pointArray).summaryStatistics();
		long max=iss.getMax();
		long sum =iss.getSum();
		System.out.println(sum);
		System.out.println(Math.max(0, max-(sum-max)));
	}
}