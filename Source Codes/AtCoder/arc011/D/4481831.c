#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-9
#define inf 1e18

typedef struct {
	double X;
	double Y;
}pos;

typedef struct {
	double A;
	double B;
	double C;
}line;

//2?p1,p2???????
line perpendicular_bisector(pos p1, pos p2){
	double A = p2.X - p1.X;
	double B = p2.Y - p1.Y;
	double C = (pow(p1.X, 2) - pow(p2.X, 2) + pow(p1.Y, 2) - pow(p2.Y, 2)) / 2;
	return (line){A, B, C};
}

//2??l1,l2???????(2???)
line *bisector_of_the_corner(line l1, line l2){
	double D1 = hypot(l1.A, l1.B), D2 = hypot(l2.A, l2.B);
	double A1 = D2 * l1.A, B1 = D2 * l1.B, C1 = D2 * l1.C;
	double A2 = D1 * l2.A, B2 = D1 * l2.B, C2 = D1 * l2.C;
	line *ls = (line *)malloc(sizeof(line) * 2);
	ls[0] = (line){A1 + A2, B1 + B2, C1 + C2};
	ls[1] = (line){A1 - A2, B1 - B2, C1 - C2};
	return ls;
}

//2??l1,l2???????
int is_parallel(line l1, line l2){
	if(fabs(l1.A * l2.B - l1.B * l2.A) <= eps){
		return 1;
	}
	else{
		return 0;
	}
}

//2??l1,l2???
pos point_of_intersection(line l1, line l2){
	if(is_parallel(l1, l2) == 1){
		printf("in function 'point_of_intersection'\n");
		printf("lines are parallel\n");
	}
	double X = -(l2.B * l1.C - l1.B * l2.C) / (l2.B * l1.A - l1.B * l2.A);
	double Y = -(l2.A * l1.C - l1.A * l2.C) / (l2.A * l1.B - l1.A * l2.B);
	return (pos){X, Y};
}

int is_same_point(pos p1, pos p2){
	if(hypot(p2.X - p1.X, p2.Y - p1.Y) <= eps){
		return 1;
	}
	else{
		return 0;
	}
}



double max(double a, double b){
	return a >= b ? a : b;
}

double min(double a, double b){
	return a <= b ? a : b;
}

double dist_road(pos p, line l){
	return fabs(l.A * p.X + l.B * p.Y + l.C) / hypot(l.A, l.B);
}

double dist_point_v2(pos p, pos q){
	return pow(q.X - p.X, 2) + pow(q.Y - p.Y, 2);
}

double f(int N, line *ls, int M, pos *ps, pos p){
	int i;
	double ans1 = inf, ans2 = inf;
	for(i = 0; i < N; i++){
		ans1 = min(ans1, dist_road(p, ls[i]));
	}
	for(i = 0; i < M; i++){
		ans2 = min(ans2, dist_point_v2(p, ps[i]));
	}
//	printf("(ans1, ans2) = (%lf, %lf)\n", ans1, ans2);
	return ans1 + ans2;
}

int main(){
	int N, M, K, i, j;
	double R;
	scanf("%d%d%lf", &N, &M, &R);
	line *ls = (line *)malloc(sizeof(line) * N);
	for(i = 0; i < N; i++){
		scanf("%lf%lf%lf", &ls[i].A, &ls[i].B, &ls[i].C);
	}
	pos *ps = (pos *)malloc(sizeof(pos) * M);
	for(i = 0; i < M; i++){
		scanf("%lf%lf", &ps[i].X, &ps[i].Y);
	}
	line *bound_lines = (line *)malloc(sizeof(line) * (N * (N - 1) + (M * (M - 1)) / 2 + 4 + N));
	bound_lines[0] = (line){1, 0, R};
	bound_lines[1] = (line){1, 0, -R};
	bound_lines[2] = (line){0, 1, R};
	bound_lines[3] = (line){0, 1, -R};
	K = 4;
	line *pair_line;
	for(i = 0; i < N; i++){
		bound_lines[K] = ls[i];
		K++;
		for(j = i + 1; j < N; j++){
			pair_line = bisector_of_the_corner(ls[i], ls[j]);
			bound_lines[K] = pair_line[0];
			bound_lines[K + 1] = pair_line[1];
			K += 2;
		}
	}
	for(i = 0; i < M; i++){
		for(j = i + 1; j < M; j++){
			if(is_same_point(ps[i], ps[j]) == 0){
				bound_lines[K] = perpendicular_bisector(ps[i], ps[j]);
				K++;
			}
		}
	}
/*	printf("bound_lines\n");
	for(i = 0; i < K; i++){
		printf("(%lf, %lf, %lf)\n", bound_lines[i].A, bound_lines[i].B, bound_lines[i].C);
	}
	printf("\n");
*/	double ans = 0;
	pos p;
	for(i = 0; i < K; i++){
		for(j = i + 1; j < K; j++){
			if(is_parallel(bound_lines[i], bound_lines[j]) == 0){
				p = point_of_intersection(bound_lines[i], bound_lines[j]);
//				printf("p = (%lf, %lf)\n", p.X, p.Y);
				if(fabs(p.X) <= R + eps && fabs(p.Y) <= R + eps){
					ans = max(ans, f(N, ls, M, ps, p));
				}
//				printf("ans = %lf\n", ans);
			}
		}
	}
	printf("%.20lf\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:101:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%lf", &N, &M, &R);
  ^
./Main.c:104:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf%lf", &ls[i].A, &ls[i].B, &ls[i].C);
   ^
./Main.c:108:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf", &ps[i].X, &ps[i].Y);
   ^