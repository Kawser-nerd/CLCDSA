import java.util.*;

public class C {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int N = sc.nextInt();
		for(int id = 1; id <= N; id++){
			double f = sc.nextDouble();
			double R = sc.nextDouble();
			double t = sc.nextDouble();
			double r = sc.nextDouble();
			double g = sc.nextDouble();
			double ans;
			if(g - 2 * f <= 0.0){
				ans = 1.0;
			}
			else if(R - t - f <= 0.0){
				ans = 1.0;
			}
			else{
				double all = Math.PI * R * R / 4.0;
				double miss = 0.0;
				for(int y = 0; (g + 2.0 * r) * y + (r + f) < R; y++){
					for(int x = 0; (g + 2.0 * r) * x + (r + f) < R; x++){
						double x1 = (g + 2.0 * r) * x + (r + f);
						double x2 = (g + 2.0 * r) * x + (r + g - f);
						double y1 = (g + 2.0 * r) * y + (r + f);
						double y2 = (g + 2.0 * r) * y + (r + g - f);
						if(x1 * x1 + y1 * y1 > (R - t - f) * (R - t - f)){
							// no intersection
						}
						else if(x2 * x2 + y2 * y2 < (R - t - f) * (R - t - f)){
							miss += (y2 - y1) * (x2 - x1);
						}
						else{
							int d = (1 << 16);
							double dx = (x2 - x1) / d;
							double missacc = 0.0;
							for(int i = 0; i < d; i++){
								double sx = x1 + dx * 0.5 + dx * i;
								double sy2 = (R - t - f) * (R - t - f) - sx * sx;
								if(sy2 >= 0){
									double sy = Math.sqrt(sy2);
									if(sy > y1){
										if(sy > y2) sy = y2;
										missacc += dx * (sy - y1);
									}
								}
							}
							miss += missacc;
						}
					}
				}
				ans = (all - miss) / all;
			}
			System.out.printf("Case #%d: %f%n", id, ans);
		}
	}
}
