import java.io.*;
import java.util.*;

public class CruiseControl {

	double ans;
	final double INF = Long.MAX_VALUE;
	final double EPS = 1e-8;

	class Car {
		int lane;
		int speed;
		double pos;

		public Car(int lane, int speed, double pos) {
			super();
			this.lane = lane;
			this.speed = speed;
			this.pos = pos;
		}

		@Override
		protected Object clone() throws CloneNotSupportedException {
			return new Car(lane, speed, pos);
		}

		@Override
		public String toString() {
			return "Car [lane=" + lane + ", speed=" + speed + ", pos=" + pos
					+ "]";
		}
	}

	boolean ok(Car[] cars) {
		for (int i = 0; i < cars.length; i++) {
			for (int j = i + 1; j < cars.length; j++) {
				if (cars[i].lane == cars[j].lane
						&& Math.abs(cars[i].pos - cars[j].pos) < 5 - EPS) {
					return false;
				}
			}
		}
		return true;
	}

	Car[] clone(Car[] a) {
		Car[] res = new Car[a.length];
		for (int i = 0; i < a.length; i++) {
			try {
				res[i] = (Car) a[i].clone();
			} catch (CloneNotSupportedException e) {
			}
		}
		return res;
	}

	long ttime;

	void bForce(double curTime, Car[] cars) {
		if (ans == INF) {
			return;
		}
		if (System.currentTimeMillis() > ttime + 15000) {
			return;
		}
		double minTime = INF;
		ans = Math.max(ans, curTime);
		for (Car car1 : cars) {
			for (Car car2 : cars) {
				if (car1.pos < car2.pos - 5 - EPS && car2.speed < car1.speed) {
					minTime = Math.min((car2.pos - 5 - car1.pos)
							/ (car1.speed - car2.speed), minTime);
				}
				if (car1.pos < car2.pos - EPS && car2.speed < car1.speed) {
					minTime = Math.min((car2.pos - car1.pos)
							/ (car1.speed - car2.speed), minTime);
				}
				if (car1.pos < car2.pos + 5 - EPS && car2.speed < car1.speed) {
					minTime = Math.min((car2.pos - car1.pos + 5)
							/ (car1.speed - car2.speed), minTime);
				}
			}
		}

		if (minTime == INF) {
			ans = INF;
			return;
		}

		Car[] newCars = clone(cars);
		for (Car c : newCars) {
			c.pos += c.speed * minTime;
		}
		if (ok(newCars)) {
			bForce(curTime + minTime, newCars);
		}

		for (int i = 0; i < cars.length; i++) {
			newCars = clone(cars);
			newCars[i].lane = 1 - newCars[i].lane;
			if (ok(newCars)) {
				for (Car c : newCars) {
					c.pos += c.speed * minTime;
				}
				if (ok(newCars)) {
					bForce(curTime + minTime, newCars);
				}
			}
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		Car[] init = new Car[n];
		ttime = System.currentTimeMillis();
		for (int i = 0; i < n; i++) {
			char lane = nextToken().charAt(0);
			int l = 0;
			if (lane == 'R') {
				l = 1;
			}
			init[i] = new Car(l, nextInt(), nextInt());

		}
		ans = 0;
		bForce(0, init);
		if (ans == INF) {
			out.println("Possible");
		} else {
			out.println(ans);
		}
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();
			for (int i = 0; i < tests; i++) {
				long time = System.currentTimeMillis();
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println("Solved case #" + (i + 1) + " in "
						+ (System.currentTimeMillis() - time) + " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("CruiseControl").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new CruiseControl().run();
	}

}
