import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.OptionalDouble;
import java.util.function.DoubleFunction;

public class Main {

	private interface F extends DoubleFunction<OptionalDouble> {
	}

	private static void setVMaxLine(int[] t, int[] v, List<F> vmaxs) {
		int n = t.length;
		int lastTime = 0;
		for (int i = 0; i < n; lastTime += t[i++]) {
			final int now = lastTime;
			final int time = t[i];
			final int vmax = v[i];
			// vmax??????????
			vmaxs.add(x -> {
				double dx = x - now;
				if (0 <= dx && dx <= time) {
					return OptionalDouble.of(vmax);
				}
				return OptionalDouble.empty();
			});
		}
	}

	private static void setUpLine(int[] t, int[] v, List<F> up) {
		int n = t.length;
		int lastTime = 0;
		double lastSpeed = 0;
		for (int i = 0; i < n; lastTime += t[i++]) {
			final double speed = lastSpeed;
			final int now = lastTime;
			final int time = t[i];
			final int vmax = v[i];

			final double needUpSpeed = vmax - speed;

			if (needUpSpeed > 0) {
				final double canUpSpeed = Math.min(needUpSpeed, time);
				up.add(x -> {
					double dx = x - now;
					if (0 <= dx) {
						return OptionalDouble.of(dx + speed);
					}
					return OptionalDouble.empty();
				});
				lastSpeed += canUpSpeed;
			} else {
				lastSpeed = vmax;
			}
		}
	}

	private static void setDownLine(int[] t, int[] v, int T, List<F> down) {
		final int n = t.length;
		int lastTime = T;
		double lastSpeed = 0;
		for (int i = n - 1; i >= 0; lastTime -= t[i--]) {
			final double speed = lastSpeed;
			final int now = lastTime;
			final int time = t[i];
			final int vmax = v[i];

			final double needUpSpeed = vmax - speed;

			if (needUpSpeed > 0) {
				final double canUpSpeed = Math.min(needUpSpeed, time);
				down.add(x -> {
					double dx = now - x;
					if (0 <= dx) {
						return OptionalDouble.of(dx + speed);
					}
					return OptionalDouble.empty();
				});
				lastSpeed += canUpSpeed;
			} else {
				lastSpeed = vmax;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			br.readLine();
			int[] t = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			int[] v = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

			int T = Arrays.stream(t).sum();

			List<F> functions = new ArrayList<>();

			setVMaxLine(t, v, functions);
			setUpLine(t, v, functions);
			setDownLine(t, v, T, functions);

			// 0.5??????????
			double sum = 0;
			double last = 0;
			for (int i = 0; i <= 2 * T; i++) {
				double x = i / 2.0;
				OptionalDouble min = functions.stream().map(f -> f.apply(x)).filter(OptionalDouble::isPresent)
						.mapToDouble(OptionalDouble::getAsDouble).min();

				if (min.isPresent()) {
					sum += last + min.getAsDouble();
					last = min.getAsDouble();
				} else {
					last = 0;
				}
			}
			System.out.println(sum / 4.0);
		}
	}

}