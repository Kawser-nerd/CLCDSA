import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Map;
import java.util.TreeMap;

public class Csmall {
	

	public static String solve(long n, long k) {
		int maxSize = 0;
		long[] tmp = {0L, 0L};
		TreeMap<Long, Long> map = new TreeMap<>(Collections.reverseOrder());
		map.put(n, 1L);
		while(k >= 1) {
			Map.Entry<Long, Long> top = map.firstEntry();
			if(k <= top.getValue()) {
				split(top.getKey(), tmp);
				//System.out.println("maxSize "+maxSize);
				return String.format("%d %d", tmp[0], tmp[1]);
			} else {
				split(top.getKey(), tmp);
				if(tmp[0] > 0) {
					map.put(tmp[0], map.getOrDefault(tmp[0], 0L) + top.getValue());
				}
				if(tmp[1] > 0) {
					map.put(tmp[1], map.getOrDefault(tmp[1], 0L) + top.getValue());
				}
				map.remove(top.getKey());
				k -= top.getValue();
				maxSize = Math.max(maxSize, map.size());
			}
		}
		throw new RuntimeException();
	}
	
	public static void split(long size, long[] out) {
		long half = size / 2;
		if(size % 2 == 0) {
			out[0] = half;
			out[1] = half - 1;
		} else {
			out[0] = half;
			out[1] = half;
		}
	}
	
	static int[] splitToInts(String s) {
		return Arrays.stream(s.split("\\s")).mapToInt(Integer::parseInt).toArray();
	}
	
	static long[] splitToLongs(String s) {
		return Arrays.stream(s.split("\\s")).mapToLong(Long::parseLong).toArray();
	}

	public static void main(String[] args) throws IOException{
		BufferedReader input = new BufferedReader(new FileReader(args[0]));
		FileWriter output = new FileWriter(args[0].substring(0, args[0].length()-2)+"out");
		final int tn = Integer.parseInt(input.readLine());
		
		for(int t=1; t<= tn; t++) {
			long[] tmp = splitToLongs(input.readLine());
			String result = solve(tmp[0], tmp[1]);
			System.out.println(String.format("Case #%d: %s", t, result));
			System.out.println("=========================");
			output.write(String.format("Case #%d: %s\n", t, result));
		}
		
		input.close();
		output.close();
		
	}
}
